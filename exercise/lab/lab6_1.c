#include <stdio.h>

void searchArray(int a[],int size,int key);

int main(void)
{
    int search;
    printf("Please enter the number which should be searched: ");
    scanf("%d",&search);

    int array[12]={5,2,6,3,6,3,6,8,9,4,7,0};
    searchArray(array,12,search);
    
    return 0;
}

void searchArray(int a[],int size,int key)
{
    int count=0;
    for(int i=0;i<size;i++)
    {
        if(key==a[i])
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