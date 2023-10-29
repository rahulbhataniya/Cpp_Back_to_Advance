#include <iostream>
#include "car.hpp"
#include "bike.hpp"
using namespace std;

int main()
{
  string vehicle_type;
  vehicle *veh;
  cout << "enter type of vehicle" << endl;
  cin >> vehicle_type;
  if (vehicle_type == "car")
  {
    veh = new car();
  }
  else if (vehicle_type == "bike")
  {
    veh = new bike();
  }
  else
  {
    cout << "vehicle type is not valid "
         << "endl";
    return 0;
  }

  veh->create_vehicle();

  return 0;
}