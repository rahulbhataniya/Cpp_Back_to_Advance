// https://www.youtube.com/watch?v=tGfG3u0CB7s&list=PLvv0ScY6vfd_ocTP2ZLicgqKnvq50OCXM&index=2
#include <iostream>
#include <thread>

using namespace std;

void test()
{
  cout << "Hello from thread" << endl;
}

int main()
{
  thread mythread(&test);
  cout << "hello from main" << endl;
  mythread.join();
  return 0;
}