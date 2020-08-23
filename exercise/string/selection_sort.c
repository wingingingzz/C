#include <stdio.h>
#define SIZE 5

int main(void)
{
    int arr[SIZE]={7,3,5,2,6};
    int i,j,c;

    for(i=0;i<SIZE;i++)
    {
        int k=i;
        for(j=i+1;j<SIZE;j++)
        {
            
            if(arr[j]<arr[k])
            {
                k=j;
            }
            
        }
        //printf("%d\n",temp1);
        //printf("%d\n",temp2);
        int temp=arr[k];
        arr[k]=arr[i];
        arr[i]=temp;
        
    }

    for(c=0;c<SIZE;c++)
    {
        printf("%d\n",arr[c]);
    }

    return 0;
}