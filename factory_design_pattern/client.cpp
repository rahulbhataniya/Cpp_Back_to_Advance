#include <iostream>
#include "vehicle_factory.hpp"
using namespace std;

int main()
{
  string vehicle_type;
  vehicle *veh;
  cout << "enter type of vehicle" << endl;
  cin >> vehicle_type;
  veh = VehicleFactory::get_vehicle(vehicle_type);
  veh->create_vehicle();
  return 0;
}