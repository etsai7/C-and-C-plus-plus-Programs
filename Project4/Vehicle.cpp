#include <iostream>
using std::ostream;
using std::cout;
using std::endl;
#include <string>
using std::string;

#include "Vehicle.h"

Vehicles::Vehicles(const int ID, const int Yr, string Color, long Mileage)
:id(ID), year(Yr), color(Color), mileage(Mileage)
{
    T_List = new Task_List();
}

void Vehicles::add_Task()
{
    T_List->Insert();
}

int Vehicles::get_ID()
{
    return id;
}

void Vehicles::checkout()
{
    print();
    print_bill();
    clear_list();
}

void Vehicles::clear_list()
{
    delete T_List;
}

void Vehicles::print_bill() 
{
    T_List->Print();
    cout << "Total Cost: $" << T_List->Calculate_Total() << endl;    
}

void Vehicles::print()
{
    cout << "Vehicle ID: " << id << "\nModel: " << year << "\nColor: " << color << "\nMileage: " << mileage << endl;
}

ostream &operator<<( ostream &out, Vehicles &vehicle)
{
    vehicle.print();
    vehicle.print_bill();
    return out;
}


