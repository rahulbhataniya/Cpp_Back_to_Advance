#include <iostream>

class Base
{
public:
  int x;
  Base()
  {
    std::cout << "calling default first\n";
  }
  Base(int a) : x(a)
  {
    std::cout << "calling parameterized\n";
  }
};

class Derived
{
  Base b1;

public:
  int y;
  Derived(int a, int b) : y(b), b1(10)
  {
  }
};

int main()
{
  Derived d1(1, 2);
  return 0;
}