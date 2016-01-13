#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;

#include "Cars.h"

Cars::Cars(const int ID, const int Yr, string Color, long Mileage, int Eng_Size, string Gas, int Poll_lvl)
:Vehicles(ID, Yr, Color, Mileage)
{
    engine_size = Eng_Size;
    gas_type = Gas;
    eng_poll_lvl = Poll_lvl;
}

void Cars::print()
{
    cout << "Car Type" << endl;
    Vehicles::print();
    cout << "Engine Size: " << engine_size << endl;
    cout << "Gas Type: " << gas_type << endl;
    cout << "Engine Pollution Level: " << eng_poll_lvl << endl;;
}
