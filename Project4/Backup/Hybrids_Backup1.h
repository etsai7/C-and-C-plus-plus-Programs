#ifndef HYBRIDS_H
#define HYBRIDS_H

#include <string>
using std::string;

#include "Cars.h"

class Hybrids : public Cars
{
    public:
        Hybrids(const int ID, const int Yr, string Color, long Mileage, int Eng_Size, string Gas, int Poll_lvl, int Mot_Power, int Mot_hrs, int Bat_Cap);
        virtual void print();
    private:
        int Motor_Power;
        int Motor_Hours;
        int Battery_Cap;

};

#endif
