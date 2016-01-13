#ifndef MOTORCYCLES_H
#define MOTORCYCLES_H
#include "Vehicle.h"
#include <string>
using std::string;

class Motorcycles : public Vehicles
{
    public:
        Motorcycles( int = 0,  int = 0, string = "Red", long = 0, int = 0, int = 0 ,int = 0);   
        virtual void print();

    private:
        int Engine_Size;
        int Front_Wheel_Size;
        int Back_Wheel_Size;   
};

#endif
