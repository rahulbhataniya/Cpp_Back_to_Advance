#include <iostream>
#include <memory>

template <typename T>
class sharedptr
{

private:
  int *counter;
  int *res;

  void increment_counter()
  {
    if (counter)
    {
      (*counter)++;
    }
  }
  void decrement_counter()
  {
    if (counter)
    {
      (*counter)--;
      if ((*counter) == 0)
      {
        delete res;
        delete counter;
        res = nullptr;
        counter = nullptr;
      }
    }
  }

public:
  sharedptr(T *newptr = nullptr) : res(newptr), counter(new int(1))
  {
  }

  sharedptr(const sharedptr &ptr) // copy constructor
  {
    res = ptr.res;
    counter = ptr.counter;
    increment_counter();
  }

  sharedptr &operator=(sharedptr &ptr)
  {
    decrement_counter(); // decrement the counter because we are releseasing the previously hold resource
    res = ptr.res;
    counter = ptr.counter;
    increment_counter(); // alocated new resource
    ptr.res = nullptr;   // we should not use delete because our aim is not to
    // delete the memory or resource but just relase the link between memory and ptr.res
    //  because from now this.res will point the memory location.
    ptr.counter = nullptr;
    return *this;
  }

  sharedptr &operator=(sharedptr &&ptr)
  {
    res = ptr.res;
    counter = ptr.counter;
    ptr.res = nullptr;
    ptr.counter = nullptr;
  }

  sharedptr(sharedptr &&ptr)
  {
    res = ptr.res;
    counter = ptr.counter;
    ptr.res = nullptr;
    ptr.counter = nullptr;
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

  void reset(T *ptr)
  {
    decrement_counter(); //  release current hole memory resource
    res = ptr;
    counter = new int(1);
  }

  T &get_count()
  {
    if (counter)
      return (*counter);
  }
};

int main()
{
  sharedptr<int> ptr1;
  sharedptr<int> ptr2(new int(10));
  sharedptr<int> ptr3(ptr2);
  sharedptr<int> ptr4 = ptr3;
  sharedptr<int> ptr5;
  ptr5 = ptr4;
  sharedptr<int> ptr6(std::move(ptr5));

  std::cout << (*ptr6);
  std::cout << ptr6.get();
  std::cout << ptr6.get_count();
  return 0;
}