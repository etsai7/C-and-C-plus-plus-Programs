#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

#include "Hybrids.h"

Hybrids::Hybrids(const int ID, const int Yr, string Color, long Mileage, int Eng_Size, string Gas, int Poll_lvl, int Mot_Power, int Mot_hrs, int Bat_Cap)
:Cars(ID, Yr, Color, Mileage, Eng_Size, Gas, Poll_lvl)
{
    Motor_Power = Mot_Power;
    Motor_Hours = Mot_hrs;
    Battery_Cap = Bat_Cap;
}

void Hybrids::print() 
{
    cout << "Hybrid Type" << endl;
    Cars::print();
    cout << "Motor Power: " << Motor_Power << endl;
    cout << "Motor Overall Usage: " << Motor_Hours << endl;
    cout << "Battery Capacity: " << Battery_Cap << endl;
}
