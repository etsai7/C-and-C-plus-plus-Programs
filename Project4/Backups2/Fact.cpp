#include <iostream>
#include <string>
#include "Project4_utilities.h"
#include "Fact.h"
using std::cout;
using std::endl;
using std::string;
#
Fact::Fact(const string subject_name)
{
    int success;
    success = Get_fact(subject_name, fact_id,fact_description);
    next = NULL  ;
}

string Fact::get_fact() const
{
    return fact_description;
}

int Fact::get_id() const
{
    return fact_id;
}
/*----------------------------------------------------------------*/
Fact_List::Fact_List()
{
    Fact_List_Head = NULL;
}

Fact_List::~Fact_List()
{
    Fact *tempFact;

    while(Fact_List_Head != NULL)
    {
        tempFact = Fact_List_Head;
        Fact_List_Head = tempFact->next;
        cout << "Fact: " << tempFact->get_fact() << "\n" << endl;
        delete tempFact;
    }
}
bool Fact_List::Remove()
{
    Fact *FactHead;

    if(Fact_List_Head == NULL) return false;
    FactHead = Fact_List_Head;
    Fact_List_Head = Fact_List_Head->next;
    cout << "Fact:" << FactHead->get_fact() << endl;
    cout << "ID: " << FactHead->get_id() << endl;
    delete FactHead;
    return true;
}
void Fact_List::set_next_Fact(string subject)
{
    int x = 1;
    int t = 1;
    Fact *new_Fact;
    Fact *tempFact;
    while(t == 1)
    {
        t = 0;
        new_Fact = new Fact(subject);
        tempFact = Fact_List_Head;   
        while(tempFact != NULL)
        {
            if(new_Fact->get_id() == tempFact->get_id())
            {
                delete new_Fact;
                t = 1;
                break;
            }
            tempFact = tempFact->next;
        }
        if(t == 0)
        {
            new_Fact->next = Fact_List_Head;
            Fact_List_Head = new_Fact;
        }
    }
}
