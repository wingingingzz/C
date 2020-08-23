#include <stdio.h>

int main(void)
{
    int size;
    int arr[100];
    printf("Enter number of marks: ");
    scanf("%d",&size);
    int arr[size];
    
    for (size_t i=0;i<size;i++)
    {
        printf("Please enter %d integers: ",size);
        scanf("%d",&arr[i]);
    }

    for(int j=1;j<size;j++)
    {
        for(int k=0;k<size-1;k++)
        {
            if(arr[k]>arr[k+1])
            {
                int temp=arr[k];
                arr[k]=arr[k+1];
                arr[k+1]=temp;
            }
            
        }
    }
    puts("sorted array is: ");
    for(size_t p=0;p<size;p++)
    {
        printf("%4d",arr[p]);
    }

    return 0;
}