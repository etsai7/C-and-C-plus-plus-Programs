#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

#include "Bus.h"

Bus::Bus(const int ID, const int Yr, string Color, long Mileage, int cap)
:Vehicles(ID, Yr, Color, Mileage)
{
    Pass_Cap = cap;
}

void Bus::print()
{
    cout << "Bus Type" << endl;
    Vehicles::print();
    cout << "Passenger Capacity: " << Pass_Cap << endl;
}
