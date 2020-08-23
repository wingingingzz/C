#include <stdio.h>
#define SIZE 5

int main(void)
{
    int arr[SIZE]={6,2,5,3,9};
    int key;
    int index;
    int flag=0;

    printf("Please enter the number you want to search: ");
    scanf("%d",&key);

    for(int i=0;i<SIZE;i++)
    {
        if(arr[i]==key)
        {
            index=i;
            printf("array index is %d\n",index);
            flag=1;
            
        }
    }
    if(flag==0)
    {
        printf("-1\n");
    }

    return 0;
}