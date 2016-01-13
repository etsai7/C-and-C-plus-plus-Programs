
/* 
 * Project 3 template: to be modified by students to incorporate 
 *                     command line arguments exclusively 
 *                     (no input while program is running)
 */

#include <stdio.h>
#include <stdlib.h>
#include "sl_repository.h"

unsigned long int next =1;

void Get_next_op( char *random_op, int *random_int, int range );
int  rand( void ); 
void srand( unsigned int seed );
void Usage( int argc, char *argv[] );

int Max_range;
int num_op;
unsigned int s;
int probability;

int main( int argc, char *argv[] )
{

    int    rand_key; 
    char   rand_op;
    int    ret; 
    int    ret_data;
    int    i;

    unsigned int sum_data;
    int num_get, num_delete, num_update;

     Usage( argc, argv );

     printf("\n");
     printf("Max Range        : %d\n", Max_range);
     printf("Operations       : %d\n", num_op);
     printf("Seed             : %d\n", s );
     printf("Probability %    : %d\n", probability );

    srand( s );

    sum_data   = 0;

    num_get    = 0;
    num_delete = 0;
    num_update = 0;

    Repository_init( probability );
/*
    Repository_update(5,5);
    Repository_print(1);
    Repository_update(2,2);
    Repository_print(1);
    Repository_update(7,7);
    Repository_print(1);
    Repository_update(2,6);
    Repository_print(1);
    Repository_update(8,8);
    Repository_print(1);
    Repository_update(7,10);
    Repository_print(2);
    Repository_delete(5);
    Repository_print(2);
    Repository_delete(7);
    Repository_print(2);
*/

   for( i = 1; i <= num_op; i++ )
    {
        Get_next_op( &rand_op, &rand_key, Max_range );


        switch( rand_op )
        {
            case 'G':
                num_get++;
                ret = Repository_get( rand_key, &ret_data );
                if( ret < 0 ) {
                    printf("\nError in Get with return value %d \n", ret );
                }
                if( ret == 1 ) sum_data = sum_data + (ret_data%100);
                break;

            case 'U':
                num_update++;
                ret = Repository_update( rand_key, i );
                if( ret < 0 ) {
                    printf("\nError in Update with return value %d \n", ret );
                }
                break;

            case 'D':
                num_delete++;
                ret = Repository_delete( rand_key );
                if( ret < 0 ) {
                    printf("\nError in Delete with return value %d \n", ret );
                }
                break;

            default:
                printf("\nError!!!, Illegal operation %c\n", rand_op );
                return 0;
        }

        if( (i % (num_op/10)) == 0 )
        {
            printf("Printing after %d operations\n", i );
            if( Max_range > 100 ) Repository_print( 0 );
            else if(num_op == 1000000) Repository_print( 1 );
            else Repository_print(2);
        }
    }
    printf("Operation summary: get %d, delete %d, update %d\n", num_get, num_delete, num_update );
    printf("Sum of all Repository_get data modulo 100 is %d\n", sum_data );
}

void Usage(int argc, char *argv[])
{
    Max_range = 100;
    num_op = 1000000;
    s = 1;
    probability = 50;   

    while( --argc > 0 )
        {
             argv++;/*Just moves a pointer to the next index. This points to 2nd unit in the array for example*/
             if( !strncmp( *argv, "-r", 2 ) )/*Strncmp is string compare. Returns 0 if equal.*/
             {
                  sscanf(argv[1], "%d", &Max_range );/*The [1] is always the next one from the current pointer. So if we were at [2]. argv[1] is technically [3] */
                  argc--; argv++;
             }else if( !strncmp( *argv, "-o", 2 ) ){
                  sscanf(argv[1], "%d", &num_op );/*Get the input */
                  argc--; argv++;
             }else if( !strncmp( *argv, "-s", 2 ) ){
                  sscanf(argv[1], "%u", &s );
                  argc--; argv++;
             }else if( !strncmp( *argv, "-p", 2 ) ){
                  sscanf(argv[1], "%d", &probability );
                  argc--; argv++;
             }else{
                  printf( "Usage: \n%s\n%s\n%s\n%s\n%s\n%s\n",
                      "\t[-r <max range>]              : range of keys with default 100"
                      "\t[-o <operations>]             : number of operations, default is 1,000,000",
                      "\t[-s <seed>]                   : seed for Random Generator, default 1",
                      "\t[-p <probability percentage>] : probability of adding to another level, default is 50");
                  exit( -1 );
             }   
       }   
}

void Get_next_op( char *random_op, int *random_int, int range )
{
    int  random_number;
    int  limit;

    random_number = rand() % 4;

    switch( random_number )
    {
        case 0:
        case 1:
                *random_op = 'G';
                break;
        case 2:
                *random_op = 'D';
                break;
        case 3:
                *random_op = 'U';
    }

    limit = (32768 / range ) * range;
    while( ( random_number = rand() ) >= limit ) ;

    *random_int = random_number % range + 1;
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

