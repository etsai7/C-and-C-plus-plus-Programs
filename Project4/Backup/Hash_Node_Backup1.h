#ifndef HASHNODE_H
#define HASHNODE_H
#define MAX_SIZE 6
#include "Hash_Tree.h"
template< typename T > class Hash_Tree;

template<typename T >
class Hash_Node
{
    friend class Hash_Tree< T >;

    public:
        Hash_Node();
        ~Hash_Node();
        int get_num_objects();
        void increase_num_objects(int x);

    private:
        int num_objects;  
        int ID_List[MAX_SIZE];
        T *Objects[MAX_SIZE];
        Hash_Node< T > *branch[MAX_SIZE]; 
};

template< typename T >
Hash_Node< T >::Hash_Node()
{
    num_objects = 0;
    int x = 0;
    while(x < MAX_SIZE)
    {
        ID_List[x] = 0;
        Objects[x] = NULL;
        branch[x] = NULL;
        x++;
    }
/*Check how to initialize the arrays. Also what the T means*/
}

template< typename T >
Hash_Node< T >::~Hash_Node()
{
    int x = 0;
    while(x < MAX_SIZE)
    {
        ID_List[x] = 0;
        Objects[x] = NULL;
        if(branch[x] != NULL)
        {
            delete branch[x];
        }
        x++;
    }
}

template< typename T >
int Hash_Node< T >::get_num_objects()
{
    return num_objects;
}

template< typename T >
void Hash_Node< T >::increase_num_objects(int x)
{
    num_objects = num_objects + x;
}

#endif
