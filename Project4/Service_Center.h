#ifndef SERVICE_CENTER_H
#define SERVICE_CENTER_H

#include "Hash_Tree.h"
#include "Vehicle.h"
#include "Cars.h"
#include "Hybrids.h"
#include "Motorcycles.h"
#include "Bus.h"
#include "Task.h"

class Service_Center
{
    public:
        Service_Center();
        ~Service_Center(); 
        void menu();
        void add_new_vehicle();
        void add_task();
        void print_tree();
        void vehicle_checkout();

    private:
        Vehicles *current_vehicle;
        Hash_Tree< Vehicles > *tree;

};

#endif
