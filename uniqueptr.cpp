#include <iostream>
#include <memory>

template <typename T>
class uniqueptr
{
private:
  T *res;

public:
  uniqueptr(T *ptr = nullptr) : res(ptr) {}
  uniqueptr(const uniqueptr<T> &ptr) = delete;            // remove copy constructor
  uniqueptr &operator=(const uniqueptr<T> &ptr) = delete; // remove assignment operator

  uniqueptr(uniqueptr &&ptr) // move copy constructor
  {
    if (this != &ptr)
    {
      res = ptr.res;
      ptr.res = nullptr;
    }
  }

  uniqueptr &operator=(uniqueptr<T> &&ptr)
  {
    if (this != &ptr)
    {
      if (res)
      {
        delete res;
      }
      res = ptr.res;
      ptr.res = nullptr;
    }

    return *this;
  }

  T *get()
  {
    return res;
  }

  T &operator*()
  {
    return *res;
  }

  T *operator->()
  {
    return res;
  }

  void reset(T *newres = nullptr) // reset it used to reset the value of resource
  {
    if (res)
    {
      delete res;
    }
    res = newres;
  }

  ~uniqueptr()
  {
    if (res)
    {
      delete res;
    }
  }
};

int main()
{
  uniqueptr<int> ptr1;
  uniqueptr<int> ptr2(new int(20));
  // uniqueptr<int>ptr3=ptr2; //should not be allowed and throw error
  uniqueptr<int> ptr4;
  // ptr4=ptr2; // should not allowd this and throw error.
  uniqueptr<int> ptr5 = std::move(ptr2);
  std::cout << ptr5.get() << "\n";      // get return the raw ptr.
  std::cout << *ptr5 << "\n";           // should return value of ptr
  uniqueptr<int> ptr6(std::move(ptr5)); // it is move copy constructor ; this two are same
  uniqueptr<int> ptr7;
  ptr7 = std::move(ptr6);

  std::cout << "before reset ptr7 =: " << *ptr7 << "\n";
  ptr7.reset(new int(10));
  std::cout << "after reset with 10 ptr7 =: " << *ptr7;
  return 0;
}