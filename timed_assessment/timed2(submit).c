// 20124865 scyqw4 Qingyu Wang

#include <stdio.h>

int main(void)
{
    int size;
    
    printf("Enter number of values: ");
    scanf("%d",&size);
    if(size<=0)
    {
        printf("Invalid array length!\n");
        return 0;
    }
    int arr[size];

    for(int i=0;i<size;i++)
    {
        printf("Enter position %d value: ",i);
        scanf("%d",&arr[i]);

        while(arr[i]<0)
        {
            printf("Enter position %d value: ",i);
            scanf("%d",&arr[i]);
        }
    }

    int hold=0;
    for(int j=0;j<size;j++)
    {
        if(arr[j]>arr[hold])
        {
            hold=j;
        }
    }
    printf("%d\n",arr[hold]);

    return 0;
}