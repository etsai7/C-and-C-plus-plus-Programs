#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <iomanip>
using std::setw;
using std::fixed;
using std::setprecision;

#include "Task.h"

Task::Task(const string name, double parts, double labor)
{
    Task_Name = name;
    Parts_Cost = parts;
    Labor_Cost = labor;
    next = NULL;
}

void Task::set_task_name(string x)
{
    Task_Name = x;
}

void Task::set_parts_cost(double x)
{
    Parts_Cost = x;
}

void Task::set_labor_cost(double x)
{
    Labor_Cost = x;       
}

string Task::get_task_name()
{
    return Task_Name;
}

double Task::get_parts_cost()
{
    return Parts_Cost;
}

double Task::get_labor_cost()
{
    return Labor_Cost;
}

double Task::get_total_cost()
{
    return (Labor_Cost + Parts_Cost);
}

Task_List::Task_List()
{
    Head = NULL;
    Tasks_Names[1] = "Schedule Maintenance";
    Tasks_Names[2] = "Brake Change";
    Tasks_Names[3] = "Tune-Up";
    Tasks_Names[4] = "Repaint";
    Tasks_Names[5] = "Oil Change";
}

Task_List::~Task_List()
{
    Task *temp;

    while(Head != NULL)
    {
        temp = Head;
        Head = temp->next;
        delete temp;
    }
}

double Task_List::Calculate_Total()
{
    double total = 0;
    Task *temp = Head;
    while(temp != NULL)
    {
        total = total + temp->get_total_cost();
        temp = temp->next;
    }
    return total;
}

void Task_List::Insert()
{
    int name;
    double P_Cost;
    double L_Cost;
    Task *temp;
    cout << "--------------------------------------------" << endl;
    for(int i = 1; i < 6; i++)
    {
        cout << i << ". " << Tasks_Names[i] << endl;
    }
    cout << "Enter a number between 1 and 5 for new task" << endl;
    cin >> name;
    while(name < 1 || name > 5)
    {
        cout << "Please choose a valid choice" << endl;
        cin >> name;
    }
    cout << "Enter a Parts cost: " << endl;
    cin >> P_Cost;
    while(P_Cost < 0.0)
    {
        cout << "Please enter a valid price." << endl;
        cin >> P_Cost;
    }
    cout << "Enter a Labor cost: " << endl;
    cin >> L_Cost;
    while(L_Cost < 0.0)
    {
        cout << "Please enter a valid price." << endl;
        cin >> L_Cost;
    }
    temp = new Task(Tasks_Names[name], P_Cost, L_Cost);
    if(Head == NULL)
    {
        Head = temp;
    }
    else
    {
        temp->next = Head;
        Head = temp;
    }
}

void Task_List::Print()
{
    Task *temp = Head;

    while(temp != NULL)
    {
        cout << temp->get_task_name() << endl;
        cout << std::fixed;
        cout << "Parts Cost: $" << setprecision(2) << temp->get_parts_cost() << endl;
        cout << "Labor Cost: $" << setprecision(2) << temp->get_labor_cost() << endl;
        cout << "----------------------------------------------" <<  endl;
        temp = temp->next; 
    }
}
