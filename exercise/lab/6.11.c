#include <stdio.h>
#define SIZE 5

void swap(int a,int b);

int main(void)
{
    int arr[SIZE]={3,9,8,2,5};
    
    for (int j=0;j<SIZE;j++)
    {
        int i;
        int temp1=arr[i];
        int temp2=i;//inside the iteration

        for (i=j;i<SIZE;i++)
        {
            
            if (arr[i]<temp1)
            {
                temp1=arr[i];
                temp2=i;
            }
            
            
        }
        swap(arr[j],temp1);
        
    }

    for(int p=0;p<SIZE;p++)
    {
        printf("%d\n",arr[p]);
    }

    return 0;
}

void swap(int a,int b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}
    
