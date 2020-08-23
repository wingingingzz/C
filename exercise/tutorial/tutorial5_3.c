#include <stdio.h>

int sort(int arr[],int size);
void printarr(int arr[],int length);

int main(void)
{
    int len;
    printf("Please enter the length of array: ");
    scanf("%d",&len);

    int array[len];
    for(int i=0;i<len;i++)
    {
        printf("Please enter %d element: ",i);
        scanf("%d",&array[i]);
    }

    sort(array,len);
    printarr(array,len);
    
    return 0;
}

int sort(int arr[],int size)
{
    for (int i=0;i<size;i++)
    {
        for(int j=0;j<size-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    return arr[size];
}

void printarr(int a[],int length)
{
    for(int i=0;i<length;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}