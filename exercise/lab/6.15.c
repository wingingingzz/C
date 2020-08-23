#include <stdio.h>
#define SIZE 10

int main(void)
{
    int arr[SIZE];
    int flag=0;

    for(int i=0;i<(SIZE/2);i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int x=(SIZE/2);x<SIZE;x++)
    {
        scanf("%d",&arr[x]);
    }

    for(int j=0;j<(SIZE/2);j++)
    {
        for(int c=(SIZE/2);c<SIZE;c++)
        {
            if(arr[j]==arr[c])
            {
                printf("Same element: %d\n",arr[c]);
                flag=1;
            }
            else
            {
                continue;
            }
            
        }
    }
    if(flag==0)
    {
        printf("No intersection element\n");
    }

    return 0;
}