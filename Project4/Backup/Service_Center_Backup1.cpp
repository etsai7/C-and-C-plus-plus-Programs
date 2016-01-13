#include<string>
#include<iostream>
#include <cstring>
using std::string;
using std::cout;
using std::endl;
using std::cin;

#include "Service_Center.h"

Service_Center::Service_Center()
{
    current_vehicle = NULL;
    tree = new Hash_Tree<Vehicles>();
    tree->MLH_set_print_option(100);
}

Service_Center::~Service_Center()
{
    delete tree;
}

void Service_Center::menu()
{
    int choice;
    int cont = 1;
    cout << "Welcome to the Service Center. What would you like to do?" << endl;
    while(cont == 1)
    {
        cout << "1. Add a new Vehicle" << endl;
        cout << "2. Add a Task" << endl;
        cout << "3. Checkout a Vehicle and Print Bill" << endl;
        cout << "4. See all the the Vehicles" << endl;
        cout << "5. Exit Service Center" << endl;
        cout << "Choice: ";
        cin >> choice;
        while(choice < 1 || choice > 5)
        {
            cout << "Please enter a valid choice option: " << endl;
            cin >> choice;
        }
        
        if(choice == 1)
        {
            this->add_new_vehicle();
        }
        else if(choice == 2)
        {
            this->add_task();
        }
        else if(choice == 3)
        {
            this->vehicle_checkout();
        }
        else if(choice == 4)
        {
            this->print_tree();           
        }
        else if(choice == 5)
        {
            cout << "Current Vehicles in Service Center" << endl;
            tree->MLH_set_print_option(100);
            tree->print();
            cout << "Goodbye" << endl;
            cont = 0;
        }
        cout << endl;
    }
}

void Service_Center::add_new_vehicle()
{
    int type;
    int new_id;
    int year;
    string color;
    long mileage;

    cout << "-------------------------------------------------" << endl; 
    cout << "Please enter the number for the type of car: " << endl;
    cout << "1. Cars" << endl;
    cout << "2. Hybrids " << endl;
    cout << "3. Motorcycle " << endl;
    cout << "4. Bus " << endl;
    cout << "Type: ";
    cin >> type;
    while(type < 1 || type > 4)
    {
        cout << "Please enter a valid type of Vehicle: " << endl;
        cout << "Type: ";
        cin >> type;
    }

    cout << "Please enter a new id for your Vehicle" << endl;
    cout << "ID: ";
    cin >> new_id;
    while(tree->MLH_get(new_id) != NULL)
    {
        cout << "Sorry the ID has already been taken. Please enter another ID." << endl;
        cout << "ID: ";
        cin >> new_id;
    }
    
    cout << "Please enter the model year for your car" << endl;
    cout << "Model: ";
    cin >> year;
    while(year < 0)
    {
        cout << "Please enter a valid year" << endl;
        cout << "Model: ";
        cin >> year;
    }

    cout << "Please enter a color for your car" << endl;
    cout << "Color: ";
    cin >> color;
    
    cout << "Please enter car mileage" << endl;
    cout << "Mileage: ";
    cin >> mileage;

    while(mileage < 0)
    {
        cout << "Please ener a valid mileage" << endl;
        cout << "Mileage: ";
        cin >> mileage;
    }
    
    if(type == 1)
    {
        Cars *new_Car;
        int engine_size;
        string gas_type;
        int eng_poll_lvl;
        cout << "You chose a Car" << endl;       
   
        cout << "Enter an Engine Size" << endl;
        cout << "Engine Size: ";
        cin >> engine_size;
        while(engine_size < 0)
        {
            cout << "Please enter a valid engine size" << endl;
            cout << "Engine Size: ";
            cin >> engine_size;
        }

        cout << "Enter Gas type (premium, plus, regular) " << endl;
        cout << "Gas Type: ";
        cin >> gas_type;
        while(gas_type.compare( "premium") && gas_type.compare("plus") && gas_type.compare("regular"))
        {
            cout << "Please enter a valid gas type" << endl;
            cout << "Gas Type";
            cin >> gas_type;
        }

        cout << "Enter a pollution level" << endl;
        cout << "Pollution Level: ";
        cin >> eng_poll_lvl;
        while(eng_poll_lvl < 0)
        {
            cout << "Please enter a valid pollution level" << endl;
            cout << "Pollution Level: ";
            cin >> eng_poll_lvl;
        }

        new_Car = new Cars(new_id, year, color, mileage, engine_size,gas_type, eng_poll_lvl);
        current_vehicle = new_Car;
        tree->MLH_insert(new_id, *current_vehicle);
    }

    else if(type == 2)
    {
        Hybrids *new_Hybrid;   
        int engine_size;
        string gas_type;
        int eng_poll_lvl;
        int MP;
        int MH;
        int BC;

        cout << "Enter an Engine Size" << endl;
        cout << "Engine Size: ";
        cin >> engine_size;
        while(engine_size < 0)
        {
            cout << "Please enter a valid engine size" << endl;
            cout << "Engine Size: ";
            cin >> engine_size;
        }

        cout << "Enter Gas type (premium, plus, regular) " << endl;
        cout << "Gas Type: ";
        cin >> gas_type;
        while(gas_type.compare( "premium") && gas_type.compare("plus") && gas_type.compare("regular"))
        {
            cout << "Please enter a valid gas type" << endl;
            cout << "Gas Type";
            cin >> gas_type;
        }

        cout << "Enter a pollution level" << endl;
        cout << "Pollution Level: ";
        cin >> eng_poll_lvl;
        while(eng_poll_lvl < 0)
        {
            cout << "Please enter a valid pollution level" << endl;
            cout << "Pollution Level: ";
            cin >> eng_poll_lvl;
        }

        cout << "Please Enter Motor Power" << endl;
        cout << "Motor Power: ";
        cin >> MP;
        while(MP < 0)
        {
            cout << "Please Enter valid Motor Power value" << endl;
            cout <<"Motor Power: ";
            cin >> MP;
        }

        cout << "Please Enter Motor overall usage in hours" << endl;
        cout << "Motor Usage: ";
        cin >> MH;
        while(MH < 0)
        {
            cout << "Please Enter valid hours" << endl;
            cout << "Motor Usage: ";
            cin >> MH;
        }

        cout << "Please enter Battery Capacity" << endl;
        cout << "Battery Capacity: ";
        cin >> BC;
        while(BC < 0)
        {
            cout << "Please Enter valid Battery Capacity value" << endl;
            cout << "Battery Capacity: ";
            cin >> BC;
        }
        
        new_Hybrid = new Hybrids(new_id, year, color, mileage,engine_size, gas_type, eng_poll_lvl, MP, MH, BC);
        current_vehicle = new_Hybrid;
        tree->MLH_insert(new_id, *current_vehicle);
    }
    else if(type == 3)
    {
        Motorcycles *new_Motorcycle;
        int ES;
        int FWS;
        int BWS;
 
        cout << "Please enter Engine size (cc)" << endl;
        cout << "Engine Size: ";
        cin >> ES;
        while(ES < 0)
        {
            cout << "Please enter a valid size" << endl;
            cout << "Engine Size: ";
            cin >> ES;
        }

        cout << "Please enter Front Wheel Size" << endl;
        cout << "Front Wheel Size: ";
        cin >> FWS;
        while(FWS < 0 )
        {
            cout << "Please Enter a valid size" << endl;
            cout << "Front Wheel Size: ";
            cin >> FWS;
        }   
    
        cout << "Please Enter a Back Wheel Size" << endl;
        cout << "Back Wheel Size: ";
        cin >> BWS;
        while (BWS < 0)
        {
            cout << "Please Enter a valid size" << endl;
            cout << "Back Wheel Size: ";
            cin >> BWS;
        }

        new_Motorcycle = new Motorcycles(new_id, year, color, mileage, ES, FWS, BWS);
        current_vehicle = new_Motorcycle;
        tree->MLH_insert(new_id, *current_vehicle);
    }
    else if(type == 4)
    {
        Bus *new_Bus;
        int PC;

        cout << "Please enter Bus capacity" << endl;
        cout << "Bus Capacity: ";
        cin >> PC;
        while(PC < 0)
        {
            cout << "Please enter a valid size" << endl;
            cout << "Bus Capacity: ";
            cin >> PC;
        }

        new_Bus = new Bus(new_id, year, color, mileage, PC);
        current_vehicle = new_Bus;
        tree->MLH_insert(new_id, *current_vehicle);
    }

    cout << "Successfully Added, what would you like to do now? " << endl;
}

void Service_Center::add_task()
{
    int new_id;
    cout << "Please enter a id for the vehicle to add a task to" << endl;
    tree->MLH_set_print_option(1);
    tree->print();
    cout << "ID: ";
    cin >> new_id;
    while(tree->MLH_get(new_id) == NULL)
    {
        cout << "Sorry the Vehicle was not found. Please enter another ID." << endl;
        cout << "ID: ";
        cin >> new_id;
    }
    current_vehicle = tree->MLH_get(new_id);
    current_vehicle->add_Task();   
}

void Service_Center::print_tree()
{
    tree->MLH_set_print_option(1);
    tree->print();
}

void Service_Center::vehicle_checkout()
{
    int new_id;
    cout << "Please enter an id for the vehicle to checkout. Enter a negative number to exit." << endl;
    this->print_tree();
    cout << "ID: ";
    cin >> new_id;
    while(tree->MLH_get(new_id) == NULL)
    {
        if(tree->MLH_get(new_id) == NULL)
        {
            cout << "Sorry the Vehicle was not found. Please enter another ID." << endl;
            cout << "Or enter a negative number to exist" << endl;
            cout << "ID: ";
            cin >> new_id;
        }
        if(new_id < 0)
        {
            cout << "What would you like to do now?" << endl;
            return;
        }   
    }
    current_vehicle = tree->MLH_delete(new_id);
    current_vehicle->checkout();
    delete current_vehicle;
    current_vehicle = NULL;     
}
