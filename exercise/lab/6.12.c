#include <stdio.h>
#define SIZE 20

int main(void)
{
    double arr[SIZE];
    for (int i=0;i<SIZE;i++)
    {
        scanf("%lf\n",arr[i]);
    }

    double arr[75]={0};
    for(int j=0;j<75;j++)
    {
        arr[j]=arr[j]+1000;
    }

    return 0;
}