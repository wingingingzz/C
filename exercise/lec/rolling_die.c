#include <stdio.h>
#include <stdlib.h>
#include <time.h>//time(NULLs)
#define SIZE 7//no ;

int main(void)
{
    int frequency[SIZE]={0};//clear counts

    srand(time(NULL));

    for(int roll=1;roll<60000;roll++)
    {
        int face=1+rand()%6;
        frequency[face]=frequency[face]+1;
    }

    printf("%s%17s\n","Face","Frequency");//imp!!!

    for(int face=1; face<SIZE;face++)
    {
        printf("%4d%17d\n",face,frequency[face]);
    }

    return 0;
}