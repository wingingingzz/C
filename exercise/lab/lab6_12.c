#include <stdio.h>

void searchArray(int *Ptr1,int *Ptr2,int key);

int main(void)
{
    int search;
    printf("Please enter the number which should be searched: ");
    scanf("%d",&search);

    int array[12]={5,2,6,3,6,3,6,8,9,4,7,0};
    searchArray(&array[0],&array[11],search);
    
    return 0;
}

void searchArray(int *Ptr1,int *Ptr2,int key)
{
    int count=0;
    for(;Ptr1<Ptr2;Ptr1++)
    {
        if(key==*Ptr1)
        {
            count=count+1;
            printf("The %d element is the same as %d.\n",count,key);
        }
    }
    if(count==0)
    {
        printf("No element is same as %d.\n",key);
    }
}