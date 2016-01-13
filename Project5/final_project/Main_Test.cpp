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
    char rand_operation;
    int rand_key;
    int operation_range ;
    int key_range;
    unsigned int seed;
    int *remove;
    
    cout << "Please enter a seed: " << endl;
    cout << "Seed: ";
    cin >> seed; 
    cout << "Please enter a key range" << endl;
    cout << "Key Range: ";
    cin >> key_range;
    cout << "Operation Range: ";
    cin >> operation_range;
    
    Hash_Tree< int > *tree = new Hash_Tree<int>();
    Random_operation *rand_generator = new Random_operation(seed, key_range);

    tree->MLH_set_print_option(key_range);
    for (int operation = 1; operation <= operation_range; operation++)
    {
        rand_operation = rand_generator->Get_op();
        rand_key = rand_generator->Get_key();
        switch( rand_operation )
        {
            case 'I':
                int rand_data;
                rand_data  =  operation;
                tree->MLH_insert(rand_key, rand_data); 
                   break;

            case 'G':
                tree->MLH_get(rand_key);
                    break;

            case 'D':
                tree->MLH_delete(rand_key);
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

delete rand_generator;
delete tree;
return 0;
}
