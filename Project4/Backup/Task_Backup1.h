#ifndef TASK_H
#define TASK_H
#define TASK_LIST_SIZE 6    
#include <string>
using std::string;

class Task
{
    public:
        Task(const string , double = 0.0, double = 0.0);
        string get_task_name();
        void set_task_name(string);
        void set_parts_cost(double);
        void set_labor_cost(double);
        double get_parts_cost();
        double get_labor_cost();
        double get_total_cost();

    private:
        string Task_Name;
        double Parts_Cost;
        double Labor_Cost;
        Task *next;

        friend class Task_List;
};

class Task_List
{
    public:
        Task_List();
        ~Task_List();
        double Calculate_Total();
        void Insert();
        void Print();

    private:
        Task *Head;
        string Tasks_Names[TASK_LIST_SIZE];
};

#endif
