#include <stdio.h>
#include <string.h>

int main(void)
{
    int *arr[3];
    int i,num;
    for(i=0;i<3;i++)
    {
        scanf("%d",&num);
        arr[i] = &num;
    }
    for(i=0;i<3;i++)
    {
        printf("%d\n",*arr[i]);
    }
}