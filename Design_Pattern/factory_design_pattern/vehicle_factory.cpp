#include "vehicle_factory.hpp"

vehicle *VehicleFactory::get_vehicle(string vehicle_type)
{
  vehicle *veh;
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
  return veh;
}