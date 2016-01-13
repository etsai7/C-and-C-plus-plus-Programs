#ifndef VEHICLES_H
#define VEHICLES_H
#include "Task.h"
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;
using std::string;

class Vehicles
{
    friend ostream& operator<<(ostream &o,  Vehicles &t);

    public:
        Vehicles(const int, const int, string, long);
        void add_Task();
        int get_ID();
        void checkout();
        void clear_list();
        void print_bill();
        virtual void print();

    private:
        int id;
        int year;
        string color;
        long mileage;
        Task_List *T_List;

/*template < typename T >
ostream& operator << (ostream &out, Vehicles &t)
{
    t.print();
};*/
};
ostream& operator << (ostream &out, Vehicles &t);

#endif
