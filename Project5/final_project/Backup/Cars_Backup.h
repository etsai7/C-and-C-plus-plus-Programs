#ifndef Cars_H
#define Cars_H

#include <string>
using std::string;

#include "Vehicle.h"

class Cars : public Vehicles
{
    public:
        Cars(const int ID, const int Yr, string Color, long Mileage, int Eng_Size, string Gas, int Poll_lvl);
        virtual void print();
        
    private:
        int engine_size;
        string gas_type;
        int eng_poll_lvl;       
};

#endif
