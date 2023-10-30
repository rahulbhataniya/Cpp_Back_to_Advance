#ifndef vehicle_factory_hpp
#define vehicle_factory_hpp

#include <iostream>
#include "car.hpp"
#include "bike.hpp"

using namespace std;

class VehicleFactory
{
  public :
  static vehicle* get_vehicle(string vehicle_type);
};

#endif