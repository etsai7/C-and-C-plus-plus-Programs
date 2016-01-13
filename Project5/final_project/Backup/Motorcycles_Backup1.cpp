#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

#include "Motorcycles.h"

Motorcycles::Motorcycles(const int ID, const int Yr, string Color, long Mileage, int Eng_size, int FW_Size, int BW_Size)
:Vehicles(ID, Yr, Color, Mileage)
{
    Engine_Size = Eng_size;
    Front_Wheel_Size = FW_Size;
    Back_Wheel_Size = BW_Size;   
}

void Motorcycles::print()
{
    cout << "Motorcycle Type" << endl;
    Vehicles::print();
    cout << "Engine Size (cc): " << Engine_Size << endl;
    cout << "Front Wheel Size: " << Front_Wheel_Size;
    cout << "Back Wheel Size: " << Back_Wheel_Size;
}
