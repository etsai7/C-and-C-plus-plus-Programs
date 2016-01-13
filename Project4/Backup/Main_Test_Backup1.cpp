#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
using std::cin;
#include "Hash_Tree.h"
#include "random_op.h"
int main()
{
 
/* 
 int x = 1;
 Hash_Tree< int > *tree = new Hash_Tree<int>();
 tree->MLH_insert(5,x);
 tree->MLH_set_print_option();
 tree->print_Head_total();
 tree->MLH_delete(5);
 tree->MLH_set_print_option();
 tree->print_Head_total();
 tree->MLH_insert(5,x);
 tree->MLH_set_print_option();
 tree->print_Head_total();
*/ 

 
    char rand_operation;
    int rand_key;
    int *rand_data;
    int operation_range ;
    int key_range;
    unsigned int seed = 1;
    int *remove;
    
    cout << "Please enter a seed: " << endl;
    cout << "Seed: ";
    cin >> seed; 
    cout << "Please enter a key range" << endl;
    cout << "Key Range: ";
    cin >> key_range;
 
    Hash_Tree< int > *tree = new Hash_Tree<int>();
    Random_operation *rand_generator = new Random_operation(seed, key_range);

    cout << "Please enter an operation range" << endl;
    cout << "Operation Range: ";
    cin >> operation_range;
    tree->MLH_set_print_option(key_range);
    for (int operation = 1; operation <= operation_range; operation++)
    {
        /*cout << "Operation: " << operation << endl;*/
        rand_operation = rand_generator->Get_op();
        rand_key = rand_generator->Get_key();
        switch( rand_operation )
        {
            case 'I':
                /*cout << "I " <<  rand_key << endl;*/
                rand_data = new int (operation);
                if(tree->MLH_insert(rand_key, *rand_data) == 0  )
                {
                   /*cout << "Did not Insert" << endl;*/
                    delete rand_data;
                }
                /*delete rand_data;*/
                   break;

            case 'G':
                /*cout << "G " << rand_key << endl;*/
                if( tree->MLH_get(rand_key) == NULL )
                  /*cout << "Did not Get" << endl;*/
                    break;

            case 'D':
                /*out << "D " << rand_key << endl;*/
                remove = tree->MLH_delete(rand_key);
                if(remove == NULL)
                { 
                    /*cout << "Did not Delete" << endl;*/
                }
                else
                {
                    delete remove; 
                } 
                    break;
            
            default:
                cout << "Illegal operation: " << rand_operation << endl;
         }
        
         if(operation%(operation_range/10) == 0)
         {
            cout << *(tree);
         }
         rand_generator->Randomize_next_op();
    }

    cout << *(tree);
delete rand_generator;
delete tree;


/*

    int x = 1;
    Hash_Tree< int > *tree = new Hash_Tree<int>();
    tree->MLH_insert(5,x);
    tree->MLH_insert(10,x);
    tree->MLH_insert(15,x);
    tree->MLH_insert(20,x);
    tree->MLH_insert(25,x);
    tree->MLH_insert(30,x);
    tree->MLH_set_print_option(100);
    tree->print();
    tree->MLH_get(4);    
    tree->MLH_get(5);    
    tree->print_Head_total();
    tree->MLH_delete(5);
    tree->MLH_delete(10);
    tree->MLH_delete(15);
    tree->MLH_delete(20);
    tree->MLH_delete(25);
    tree->MLH_delete(30);
    tree->MLH_insert(5,x);    
*/
/*    delete tree;
    return 0;
*/
/*
    tree->MLH_insert(9,x);
    tree->MLH_insert(9,x);
    tree->print_Head_total();   
    cout << endl;
    tree->MLH_insert(10,x);
    tree->print_Head_total();
    cout << endl;
    
    tree->MLH_set_print_option(100);
    tree->MLH_delete(5);
    tree->print_Head_total();
    tree->MLH_insert(5,x);
    tree->MLH_insert(11,x);
    tree->print_Head_total();
    tree->print();
    tree->MLH_insert(12,x);
    tree->MLH_insert(13,x);
    tree->MLH_insert(14,x);
    tree->MLH_insert(15,x);
    tree->print();
    tree->print_Head_total();
    tree->MLH_get(2);
    tree->MLH_get(5);
    return 0;
*/
return 0;
}
