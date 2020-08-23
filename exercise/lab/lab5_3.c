#include <stdio.h>

int max_array(int arr[],int size);

int main(void)
{
    int size;
    printf("Please enter the number of elements in array: ");
    scanf("%d",&size);
    int arr[size];
    for(int i=0;i<size;i++)
    {
        printf("Please enter %d element: ",i);
        scanf("%d",&arr[i]);
    }
    int rslt;
    rslt=max_array(arr,size);//arr[] is incorrect!!!
    printf("The maximum of the array is %d",rslt);
    printf("\n");

    return 0;
}

int max_array(int arr[],int size)
{
    int max=arr[0];
    for(int i=0;i<size;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    return max;
}