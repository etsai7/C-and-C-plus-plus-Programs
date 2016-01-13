#ifndef HASH_TREE_H
#define HASH_TREE_H
#define MAX_LEVELS 9

#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;
#include "Hash_Node.h"
#include "ML_hash.h"

template <typename T >
class Hash_Tree;

template< typename T >
ostream& operator<<(ostream &o,  Hash_Tree< T > &Tree);

template< typename T >
class Hash_Tree
{
    friend ostream& operator << <>(ostream &o,  Hash_Tree< T > &Tree);
    public:
        Hash_Tree();
        ~Hash_Tree();
        void collapse(Hash_Node<T> *x);
        int MLH_insert(int key, T &obj);
        T* MLH_get(int key);
        T* MLH_delete(int key);/*See if the syntax is correct*/
        void MLH_set_print_option(int print_all);/*Find out what this means*/
        void print();
        void print_Head_total();
        void print_steps_total();
        void print_lowest_level();

    private:
        int MLH_insert_help(Hash_Node< T > *x, int level, int key, T &obj);
        T* MLH_delete_help(Hash_Node< T > *x, int level, int key);
        T* MLH_get_help(Hash_Node< T > *x, int level,int key);
        void MLH_set_print_option_help(Hash_Node< T > *x,int level, int print_all);
        Hash_Node< T > *Head_Node;
        int amt_levels[MAX_LEVELS];
        long steps;
        int amt_objects;
        int amt_nodes;
        int print_option;
};

template< typename T >
void Hash_Tree< T >::print_Head_total()
{
    cout << "Total: " << Head_Node->get_num_objects() << endl;
}

template< typename T >
Hash_Tree< T >::~Hash_Tree()
{
    delete Head_Node;           
}

template< typename T >
Hash_Tree< T >::Hash_Tree()
{
    int x = 0;
    Head_Node = new Hash_Node< T >();
    while(x < MAX_LEVELS)
    {
        amt_levels[x] = 0;
        x++;
    }
    amt_levels[0] = amt_levels[0] + 1;
    steps = 0;
    amt_objects = 0;
    amt_nodes = 0;
    print_option = 0;
}
/*INSERT*/
template< typename T >
int Hash_Tree< T >::MLH_insert(int id, T &obj)
{
    if(Head_Node == NULL)/*This is when we have deleted the top node*/
    {
        Head_Node = new Hash_Node< T >();
        amt_levels[0] = 1;
    }
    int add = this->MLH_insert_help(Head_Node, 0, id, obj);
    amt_objects = amt_objects + add;
    return add;
}

template< typename T >
int Hash_Tree< T >::MLH_insert_help(Hash_Node< T > *x, int level, int id, T &obj)
{
    int current_level = level;
    int can_add = 1;
    int counter = 1;
    Hash_Node< T > *temp = x;
    if(temp->get_num_objects() < 5)
    {
        while(counter < MAX_SIZE)
        {
            if(temp->ID_List[counter] == id)
            {
                can_add = 0;   
            }
            counter++;
        }
        counter = 1;
        if(can_add == 1)
        {
            while(counter < MAX_SIZE)
            {
                if(temp->ID_List[counter] == 0)
                {
                    temp->ID_List[counter] = id;
                    temp->Objects[counter] = &obj;
                    temp->increase_num_objects(1);
                    return  1;               
                }
                counter++;
            }
        }
        return 0;
    }
    
    else if(temp->get_num_objects() == 5)
    {
        int not_added = 1;
        while(counter < MAX_SIZE)
        {
            if(temp->ID_List[counter] == id)
            {
                can_add = 0;
            }
            counter++;
        }
        if(can_add == 1) /*Now we need to create a new node*/
        {
            int next_node;
            int x = 1;
            int t = 1;
            Hash_Node< T >* temp_new_node;/* = new Hash_Node< T >();*/
              
                temp->increase_num_objects(1);
                while(x < MAX_SIZE)
                {
                    next_node = ML_hash(current_level+1, temp->ID_List[x]);
                    if(temp->branch[next_node] == NULL)
                    {
                        temp->branch[next_node] = new Hash_Node<T>();
                        amt_levels[level + 1] = amt_levels[level + 1] + 1;
                    }
                    temp_new_node = temp->branch[next_node];
                    temp_new_node->ID_List[temp_new_node->get_num_objects() + 1] = temp->ID_List[x];
                    temp_new_node->Objects[temp_new_node->get_num_objects() + 1] = temp->Objects[x];
                    temp_new_node->increase_num_objects(1);
                    temp->ID_List[x] = 0;
                    temp->Objects[x] = NULL;
                    x++;
                }
                x = 1;
                
                next_node = ML_hash(current_level + 1, id);
                if(temp->branch[next_node] == NULL)
                {
                    temp->branch[next_node] = new Hash_Node<T>();
                    temp = temp->branch[next_node];
                }
                else
                {
                    temp_new_node = temp->branch[next_node];
                    temp = temp_new_node;
                }
                this->MLH_insert_help(temp, current_level + 1, id, obj);
            return 1;
        }
        return 0;
    }

    else if(temp->get_num_objects() > 5)
    {
        int next_node = ML_hash(current_level + 1, id);
        if(temp->branch[next_node] == NULL)
        {
            temp->branch[next_node] = new Hash_Node<T>();    
        }
        steps++;
        int add = this->MLH_insert_help(temp->branch[next_node],current_level+1, id, obj);    
        temp->increase_num_objects(add);
        return add;   
    }
}

/*GET*/
/*Check if this is how you return*/
template< typename T >
T* Hash_Tree< T >::MLH_get(int key)
{
    if(Head_Node == NULL)
    {
        cout << "NULL" << endl;
        return NULL;
    }
    else
    {
        T* temp;
        temp = this->MLH_get_help(Head_Node, 0, key);
        if(temp == NULL)
        {
        }
        else if(temp != NULL)
        {
        }
        return temp;
    }
}
template< typename T > 
T* Hash_Tree< T >::MLH_get_help(Hash_Node< T > *x, int level,int id)
{
    int current_level = level;
    int counter = 1;
    T *object;/*Check if this is the syntax*/
    Hash_Node< T > *temp = x;
    if(temp->get_num_objects() <= 5)
    {
        while(counter < MAX_SIZE)
        {
            if(temp->ID_List[counter] == id)
            {
                object = temp->Objects[counter];
                return object;
            }
            counter++;
        }
        object = NULL;
        return object;
    }
    else
    {
        steps++;
        int next_node = ML_hash(current_level + 1, id);
        if(temp->branch[next_node] == NULL)
        {
            object = NULL;
            return object;
        }
        else
        {
            return this->MLH_get_help(temp->branch[next_node],current_level + 1, id);
        }
    }
}

template< typename T >
void Hash_Tree< T >::MLH_set_print_option(int print_all)
{
    print_option = print_all;    
}

template< typename T >
void Hash_Tree< T >::print()
{
    amt_nodes = 0;
    amt_objects = 0;
    int x = 0;
    while(x < 9)
    {
        amt_levels[x] = 0;
        x++;
    }
    this->MLH_set_print_option_help(Head_Node,0, print_option);   
    cout << endl;
    cout << "Amount of objects: " << amt_objects << endl;
    cout << "Amount of Nodes: " << amt_nodes << endl;
  
}

template< typename T >
void Hash_Tree< T >::MLH_set_print_option_help(Hash_Node< T > *x,int level, int print_all)
{
    int counter = 1;
    int current_level = level;
    int to_print = print_all;
    Hash_Node< T > *temp = x;
    if(temp != NULL)
    {
        amt_levels[current_level]++;
        if(temp->get_num_objects() <= 5)
        { 
            amt_nodes++;  
            while(counter < MAX_SIZE)
            {
                if(temp->ID_List[counter] != 0)
                {
                    amt_objects++;
                    cout << "--------ID: " << temp->ID_List[counter] << endl;
                    if(to_print == 100)
                    {
                        cout << "--------Object " << *(temp->Objects[counter]) << endl;/*Check if this is how you print the object*/
                    }
                }
                counter++;
            }
        }
        else
        {
            while(counter < MAX_SIZE)
            {
                if(temp->branch[counter] != NULL)
                {
                    steps++;
                    amt_nodes++;
                    this->MLH_set_print_option_help(temp->branch[counter], current_level+1, print_all);
                }
                counter++;
            }
        }
    }
}

template< typename T >
T* Hash_Tree< T >::MLH_delete(int key)
{
    T *temp = this->MLH_delete_help(Head_Node, 0, key);
    return temp;
}

template< typename T >
T* Hash_Tree< T >::MLH_delete_help(Hash_Node< T > *x, int level, int key)
{ 
    Hash_Node< T > *temp = x;
    Hash_Node< T > *temp_delete;
    Hash_Node< T > *node_delete;
    T *return_obj = NULL;
    int copy_id = 1;
    int counter = 1;
    int non_empty = 0; /*Keeps track of how many that are not empty in the array*/
    if(temp == NULL)
    {
        return NULL;
    }
    if(temp->get_num_objects() <= 5)
    {
        while(counter < MAX_SIZE)
        {
            if(temp->ID_List[counter] != 0)
            {
                if(temp->ID_List[counter] == key)
                {
                    return_obj = temp->Objects[counter];
                    temp->Objects[counter] = NULL;                      
                    temp->ID_List[counter] = 0;
                    temp->increase_num_objects(-1); /*subtracts from total amount*/
                }
                non_empty++;
            }
            counter++;
        }
        
        return return_obj;
    }
    else
    {
        int next_node = ML_hash(level + 1, key);
        steps++;
        return_obj = this->MLH_delete_help(temp->branch[next_node],level + 1, key);
        if(return_obj != NULL) /*Found the object and key to delete, so need to check if need to collapse*/
        {
            if(temp->branch[next_node]->get_num_objects()==0)
            {
                delete temp->branch[next_node];
                amt_levels[level + 1]--;
                temp->branch[next_node] = NULL;
            }
            temp->increase_num_objects(-1); /*decreasing total count*/
            if(temp->get_num_objects() <= 5)/*time to collaps*/
            {
                for(int i = 1; i < MAX_SIZE; i++)
                {
                    node_delete = temp->branch[i];                   
                    if(node_delete != NULL)
                    {
                        amt_levels[level + 1]--;
                        for(int j = 1; j< MAX_SIZE; j++)
                        {
                            if(node_delete->ID_List[j] != 0)
                            {
                                temp->ID_List[copy_id] = node_delete->ID_List[j];   
                                temp->Objects[copy_id] = node_delete->Objects[j];
                                copy_id++;
                            }
                        }
                        temp_delete = node_delete;
                        temp->branch[i] = NULL;
                        delete temp_delete;
                        amt_levels[level + 1]--;
                    }
                }
            }
        }
        return return_obj;
    }
}

template< typename T >
void Hash_Tree< T >::print_steps_total() 
{
    cout << "Steps: " << steps << endl;
}
 
template< typename T >
void Hash_Tree< T >::print_lowest_level() 
{
    int x = 0;
    while(x < MAX_LEVELS)
    {
        if(amt_levels[x] == 0)
        {
            break;
        }
        
        x++;
    }
    cout << "Lowest Level: " << x << endl;
}

template< typename T >
ostream& operator<<(ostream &out,  Hash_Tree< T > &Tree)
{
    Tree.print();
    Tree.print_steps_total();
    Tree.print_lowest_level();
}
#endif
