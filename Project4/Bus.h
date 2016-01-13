#ifndef BUS_H
#define BUS_H
#include "Vehicle.h"
#include <string>
using std::string;

class Bus : public Vehicles
{
    public:
        Bus(const int ID, const int Yr, string Color, long Mileage, int cap);
        virtual void print();

    private:
        int Pass_Cap;
};

#endif
