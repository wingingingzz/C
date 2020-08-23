#include <stdio.h>
#include <stdlib.h>
int sum(int nums[], int nums_size)
{
    int *total=0;
    if((total=(int*)malloc(sizeof(int)))==NULL)
    {
        exit(1);
    }
    for (int i = 0; i < nums_size; i++)
    {
        *total+=nums[i];
    }
    int t= *total;
    free(total);
    return t;
}

int main(void)
{
    int nums[5]={3,3,3,4,5};
    int result=sum(nums, 5);
    printf("%d\n", result);
}