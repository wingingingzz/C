#include <stdio.h>

int main(void)
{
    //int arr[100];
    int x;
    printf("please enter a nuber: ");
    scanf("%d",&x);
    int arr[x];

    for (size_t i=0;i<x;i++)
    {
        printf("Please enter %d integers: ",x);
        scanf("%d",&arr[i]);
    }
    puts("previous array is: ");
    for(size_t p=0;p<x;p++)
    {
        printf("%4d",arr[p]);
    }
    printf("\n");

    for(unsigned int j=1;j<x;j++)
    {
        for(size_t k=0;k<x-1;k++)
        {
            if(arr[k]<arr[k+1])
            {
                int temp=arr[k];
                arr[k]=arr[k+1];
                arr[k+1]=temp;
            }
            
        }
    }
    puts("sorted array is: ");
    for(size_t p1=0;p1<x;p1++)
    {
        printf("%4d",arr[p1]);
    }
    printf("\n");

    return 0;
}