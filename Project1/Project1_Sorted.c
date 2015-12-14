
/* 
 * Getting started quiz solution
 *
 * We would like to generate lines of the forms:
 *
 * I <random number>
 * D <random number>
 * G <random number>
 * 
 * such that randomly, about 50% of the lines are G lines,
 * 25% are D lines, and 25% are I lines. The random
 * numbers are integers uniformly distirbuted (subject to the
 * pseudo random generator) between 1 and 100.
 * 
 * Write a program that gets as input the number of lines 
 * to generate, and prints these lines as they are generated.
 * 
 * Please use the pseudo random generator provided in the
 * program random.c from class with a seed=1.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
unsigned long int next = 1;
int num_G, num_D, num_I = 0;
unsigned int next_count = 0;
//This is the "Object" of type record. Contains key, data, and pointer to next record.
typedef struct dummy_record{
	int key;
	int data;
	struct dummy_record *next;
} record;

record *ListHead;
record *ListTail;

int when_to_print;

void Get_next_op( char *random_op, int *random_key, int *random_data, int range );
int  rand( void ); 
void srand( unsigned int seed );

int init_ListHead();
int Insert_Sorted( int insert_sorted_key, int insert_sorted_data); 
int Delete( int delete_key);
int Get( int get_key);
void Print();

main()
{
    unsigned int s = 0;
    int    num_op, r_key, r_data, i;
    int    range;
    char   r_op;
 //   int when_to_print;

    printf("Generating random operations\n");
    printf("Please enter the number of operations requested: ");
    scanf("%d", &num_op );
    printf("Please enter a range: ");
    scanf("%d", &range );
    printf("Please enter a starting seed: ");
    scanf("%d", &s );
    printf("\nGenerating %d operations with range %d and random seed %d \n", num_op, range, s);
    printf("----------------------------------------------------------------------\n");
    
    when_to_print = num_op/10;
	printf("when to print: %d",when_to_print);
    srand( s );
    printf("\nOperation\t     Key\t    Data\n\n");

    for( i = 1; i <= num_op; i++ )
    {
        Get_next_op( &r_op, &r_key, &r_data, range );

	if(r_op == 'I')
	{
		Insert_Sorted(r_key,r_data);		
	}   
	else if(r_op == 'D')
	{
		Delete(r_key);
	}
	else if(r_op == 'G')
	{
		Get(r_key);
	}
	if(i%when_to_print == 0 )
	{
		Print();
	}
     }
    printf("Num_G %d, Num_D %d, Num_I %d\n", num_G, num_D, num_I );

}

void Get_next_op( char *random_op, int *random_key, int *random_data, int range )
{
    int  random_number;
    int  limit;

    /* Get random operation ('G' for Get, 'D' for Delete, 'I' for Insert) */
    random_number = rand() % 4;
    switch( random_number )
    {
        case 0:
        case 1:
                *random_op = 'G';
                num_G++;
                break;
        case 2:
                *random_op = 'D';
                num_D++;
                break;
        case 3:
                *random_op = 'I';
                num_I++;
    }

    /* Get random key between 1 and range */
    limit = (32768 / range) * range;
    while( ( random_number = rand() ) >= limit ) ;

    *random_key = random_number % range + 1;
    
    /* Get random data between 1 and range */
    while( ( random_number = rand() ) >= limit ) ;

    *random_data = random_number % range + 1;
}

/* Pseudo random generator on 0..32767 */
int  rand(void)
{
    next = next *1103515245 + 12345;
    return (unsigned int)(next/65536)%32768;
}

void srand( unsigned int seed )
{
    next = seed;
}
//Initialize the LinkedList ---------------------------------------------------------
int init_ListHead()
{
    ListHead = NULL;
    next_count++;
    ListTail = NULL;
    next_count++;
    return 1;   
}

//Inserting sorted a specific key and data if possible -----------------------------------
int Insert_Sorted(int insert_sorted_key, int insert_sorted_data)
{
    record *dummy_record;
    record *tempList = ListHead;

    dummy_record = malloc(sizeof(record));
    if( dummy_record == NULL) return -1; //This is for failed memory allocation    
    next_count++;

    dummy_record->key = insert_sorted_key;
    dummy_record-> data = insert_sorted_data;
    dummy_record-> next = NULL;
    next_count = next_count+3;

//Case 1: Empty List. Automatically add it in.
    if(ListHead == NULL)
    {
	ListHead = dummy_record;
	next_count++;
	ListTail = dummy_record;
	next_count++;
	next_count = next_count + 2;
	return 1;		
    }
//Case 2: The record is already there. Do not add it in.
    if(ListHead->key == dummy_record->key) //checks the first record in the list.
    {
	return 0;	
    } 
    while(tempList->next != NULL)//Keep going through the list until last one points to NULL
    {
	if(tempList->key == dummy_record->key)
	{
		return 0;
	}
	next_count++;
	tempList = tempList->next;		
    }
    if(ListTail->key == dummy_record-> key)//checks the last record in the list
    {
	return 0;
    }
//Case 3: Add it in sorted to the end.
    //Key is smaller than the ListHead
    tempList = ListHead;
    if(ListHead->key > dummy_record->key)
    {
	dummy_record->next = ListHead;
	next_count++;
	ListHead = dummy_record;
	next_count++;
	return 1;
    }
    //Key is greater than ListTail
    else if(ListTail->key < dummy_record->key)
    {
	ListTail->next = dummy_record;
	next_count++;
	ListTail = ListTail->next;
	next_count++;
	return 1;
    }

    //Key is inbetween ListHead and ListTail
    while(tempList->next != NULL)
    {
	if(tempList->key < insert_sorted_key && insert_sorted_key < tempList->next->key)
	{
		dummy_record->next = tempList->next;
		next_count++;
		tempList->next = dummy_record;
		next_count++;
		return 1;
	}
	next_count++;
	tempList=tempList->next;
    }
}

//Getting the data of a record if it exists.-----------------------------------------------------
int Get(int get_key)
{
    record *tempList = ListHead; 
    if(ListHead == NULL)//if the List is already empty
    {
	return 0;
    }
    else if(ListHead->key == get_key)//Checks the ListHead
    {
	return ListHead->data;	
    }
    while(tempList->next != NULL)//Checks from 2nd to ListTail
    {
	tempList = tempList->next;
	next_count++;
	if(tempList->key == get_key)
	{
		return tempList->data;
	}		
    }
    return 0; //Returns 0 if the key is not found.
}

//Deletes the data of a record if it exists-------------------------------------------------------
int Delete(int delete_key)
{   
    record *dummy_record;
    record *tempList = ListHead;;

    dummy_record = malloc(sizeof(record));
    if( dummy_record == NULL) return -1; //This is for failed memory allocation    
    next_count++;

    if(ListHead == NULL)
    {
	return 0;
    }
    else if(ListHead->key == delete_key)
    {
	dummy_record = ListHead;
	next_count++;
	ListHead = ListHead->next;
	next_count++;
	free(dummy_record);
	return 1;
     }
  
    while(tempList->next != NULL)//ASK IF doing tempList->next->next will auto point to a null.
    {
	if(tempList->next->key == delete_key)
	{
		dummy_record = tempList->next;
		tempList->next = tempList->next->next;
		if(tempList->next == NULL)
		{
			ListTail = tempList;
		}

		free(dummy_record);
		next_count = next_count + 2;
		return 1;	
	}
	tempList=tempList->next;
	next_count++;
    }
    return 0;
}

//Prints out the size of the repository, the number of next steps performed, and current key & data record;
void Print()
{
    record *tempList;   
    int unsigned size;

    printf("Repository Content: \n");
    tempList = ListHead;
    
    
 	   while(tempList != NULL)//CHECK IF this is more efficient and can be applied to the other methods
    	{
	    if(when_to_print != 1000000)
	    {	
		printf("\tkey:%d\tdata:%d\n",tempList->key, tempList->data);
	    }
		tempList = tempList->next;
		next_count++;
		size++;
    	}
    
   printf("Size of Repository:%d\n",size);
    printf("Number of next steps:%u\n",next_count);//%u is for unsigned    
}
