#include <stdio.h>

int main(void)
{
    int *arr[3];
    int i, p[3]={10,20,30};
    for(i=0;i<3;i++)
    {
        arr[i]=&p[i];
        printf("%d\n",*arr[i]);
    }
}
