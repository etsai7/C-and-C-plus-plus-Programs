#include <string>
#ifndef FACT_H
#define FACT_H
using std::string;

class Fact
{
    public:
        Fact(const string); 

        string get_fact() const;
        int get_id()const ;

    private:
        string fact_description;
        int fact_id;
        Fact *next;
        
        friend class Fact_List;
};

class Fact_List
{
    public:
        Fact_List();
        ~Fact_List();

        void set_next_Fact(string subject);
        bool Remove();
    private:
        Fact *Fact_List_Head;
};

#endif
