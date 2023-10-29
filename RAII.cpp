// RAII Resource Acquisition In initialisation

// in this code we will understand the what is RAII
// how it will bve used to prevent memory leak.

#include <iostream>

class Wrapper
{
public:
  Wrapper(int *mem) : mem_(mem)
  {
    std::cout << "inside constructor\n";
  }
  ~Wrapper()
  {
    std::cout << "inside destructor \n";
    delete mem_;
  }

private:
  int *mem_;
};

int main()
{
  Wrapper obj(new int(10));
  return 0;
}

// here you can see Resource Acquisition is taking place at the time of initialization in constructo thats why
//  we call it as RAII