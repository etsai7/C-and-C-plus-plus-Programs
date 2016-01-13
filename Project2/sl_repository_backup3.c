
#include <stdio.h>
#include <stdlib.h>
#include "rand100.h"
#include "sl_repository.h"

unsigned int next_count = 0;
static int probability;
int levels;
int MAX_LEVELS = 30 /*How this was chosen is in Strategy.txt*/;

typedef struct dummy_record{
    int key;
    int *data;
    struct dummy_record *next;
    struct dummy_record *down;
} record;

static record *ListHead;
record *BottomHead;

/*Initializes the Super List repository and the probability to p percent*/
void Repository_init( int p )
{
    ListHead = malloc(sizeof(record));          /*ListHead is a sentinel node*/
    if(ListHead == NULL) return;
    ListHead->next = NULL;
    ListHead->down = NULL;                      
    next_count = next_count + 2;                
    probability = p;                            
    levels = 1;                                 
    BottomHead = ListHead;                      
}                                               
                                                
                                                
/*Updates the data if the key is found. If not, insert new record and roll to see how many "layers" needed for this new record*/
int Repository_update(int key, int data)        
{                                               
    record *tempList = ListHead;                /*tempList is used to traverse data structure*/
    record *tempPointer = NULL;                 /*tempPointer points to the previous inserted record*/
    record *temp_record;                        /*record to be added*/
    
    record *newListHead;                        /*newListHead is a temp ListHead if we need to create a new lvl*/
    record *level_save[levels];                 /*level_save is an array of pointers that mark where we stopped on prev lvl*/
    int *data_pointer;                          /*data_pointer creates a pointer to data, so easy to manipulate across all lvls*/
    int x = 0;                                  /*x keeps track of where in array to access*/

    while(tempList != NULL)/*Checks by level for the record to insert after*/
    {
        while(tempList->next != NULL && tempList->next->key <= key)
        {
            if(tempList->next->key == key)
                {
                    *tempList->next->data = data;
                    return 0; /*data updated*/
                }
            tempList = tempList->next;
            next_count++;
        }
        level_save[x] = tempList;/*stores the record where it stopped and went down*/
        x++;
        tempList = tempList->down;
        next_count++;
    record *tempHead2 = ListHead;
    }
    /*Now that we have all the points of insertion, add them in*/
    /*If we reach this point, it means we need to insert*/
    data_pointer = malloc(sizeof(int));
    if(data_pointer == NULL) return -1;
    *data_pointer = data;

    do
    {
        temp_record = malloc(sizeof(record));
        if(temp_record == NULL) return -1;
        temp_record->key = key;
        temp_record->data = data_pointer;
        temp_record->down = tempPointer;
        if(x >= 1)
            {
                temp_record->next = level_save[x-1]->next;
                level_save[x-1]->next = temp_record;
                level_save[x-1] = NULL;
                x--;        
            }
        else if( x < 1)/*Creates new level if probability is "rolled"*/
        {
            temp_record->next  = NULL;
            newListHead = malloc(sizeof(record));
            if(newListHead == NULL) return -1;
            newListHead->down = ListHead;
            newListHead->next = temp_record;
            ListHead = newListHead;
            next_count = next_count + 3;
            levels++;
        }
        tempPointer = temp_record;
    }while(rand100() <= probability && levels <= MAX_LEVELS);
    
    return 1;/*successful insert*/
}
 
/*Removes a record with the given key if found*/
int Repository_delete( int key )
{
    record *dummy_record;                           /*dummy_record points to record that will be freed*/
    record *tempList = ListHead;                    /*pointer to traverse through the data structure*/
    record *dummy_ListHead;                         /*dummy_ListHead points to ListHead that we need to */
    int *dummy_data;                                /*delete if there are no other records on that level*/
    int x = 0;

    while(tempList != NULL)
    {
        while(tempList->next != NULL)
        {
            if(tempList->next->key == key)
            {
                dummy_record = tempList->next;
                next_count = next_count + 1;
                if(x == 0)/*This statement makes sure we only free the data pointer once*/
                {
                    dummy_data = tempList->next->data;
                    free(dummy_data);
                    x = 1;
                }
                tempList->next = tempList->next->next;
                free(dummy_record);
                break;
            }
            else if(tempList->next->key > key)
            {
                break;
            }
            tempList = tempList->next;
            next_count++;
        }

        tempList = tempList->down;
        next_count++;
        if(ListHead->next == NULL && ListHead->down != NULL)
        {
            dummy_ListHead = ListHead;
            ListHead = ListHead->down;
            free(dummy_ListHead);
            levels--;
        }
    }
    if(x == 1)/*Tells us that at least 1 item was deleted*/
    {
        return 1;
    }
    return 0;
}

/*Gets a record with that specific key and if found, stores the data into the *data pointer*/
int Repository_get( int key, int *data)
{
    record *tempList = ListHead;                /*Pointer used to traverse through data structure*/
    while(tempList != NULL)
    {
        while(tempList->next != NULL)
        {
           if(tempList->next->key == key)
            {
                *data = *(tempList->next->data);
                return 1;/*Found the key and updated*/ 
            }
            else if( tempList->next->key > key)
            {
                break;/*Key is not found, go down*/
            }
            tempList = tempList->next;
            next_count++;
        }

        tempList = tempList->down;
        next_count++;
    }

    return 0;
}

/*Prints the number of unique records in repository, the total number of records in each level
 * current number of levels including base lvl, and number of "next" steps
 * If print_elements is 1, print only list of unique records in repository
 * If print_elements is 2, print it like how the structure should look
*/
void Repository_print( int print_elements)
{
    int x = 0;
    int record_count[MAX_LEVELS];
    record *tempList = ListHead;
    record *tempHead = ListHead;
    record *BottomLevel = BottomHead;
    int num_records_print = 0;
    int printing_key;
    int temp_Levels = levels;
    int num_per_level = 0;
    int num_unique = 0;
    while(x < levels)/*Prints Level:x for the amount of levels in this data structure*/
    {
        printf(" Level:%4d ",x);
        x++;
    }
    x = 0;
    printf("\n");
    
    /*Compare each record at the bottom of the structure with all the other
     * records in the list to determine how many of that specific record to print.
     * Will print the structure sideways.
     */            
    while(BottomLevel->next != NULL)
    {
        printing_key = BottomLevel->next->key;
        while(tempList != NULL)
        {
            while(tempList->next != NULL)
            {
                if(tempList->next->key == printing_key)
                {
                    num_records_print++;
                    break; 
                }
                else if(tempList->next->key > printing_key)
                {
                break;
                }
                tempList = tempList->next;
                next_count++;
            }
            tempList = tempList->down;
        }
        if(print_elements == 2)
        {
            while(num_records_print >= 1)
            {
                printf("{%3d,%4d}",printing_key,*BottomLevel->next->data);
                if(num_records_print == 1)
                {
                    printf("\n");
                }
                num_records_print--;
            }
        }
        BottomLevel = BottomLevel->next;
        next_count++;
        tempList = ListHead;
        tempHead = ListHead;
        num_unique++;
        num_records_print = 0;
                      
    }
              
    while(tempList != NULL)
    {
        while(tempList->next != NULL)
        {
            num_per_level++;    
            tempList = tempList->next;
            next_count++;
        }
        record_count[x] = num_per_level;
        x++;

        num_per_level = 0;
        tempHead = tempHead->down;
        tempList = tempHead;
        next_count++;
    }

    x--;
    while ( x >= 0)
    {
        printf(" Size: %4d ",record_count[x]);
        x--;                        
    }
    if(print_elements == 1)
    {
        printf("\n");
        BottomLevel = BottomHead;
        while(BottomLevel->next != NULL)
        {
            printf("{%3d,%4d}\n",BottomLevel->next->key, *BottomLevel->next->data);
            BottomLevel = BottomLevel->next;
        }
    }
    printf("\nSteps:%u\n",next_count);
    printf("Unique:%d\n",num_unique);
 
}
