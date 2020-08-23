#include <stdio.h>

int main(void)
{
    int i,j;
    for(i=0;i<11;i++)
    {
        for(j=0;j<i;j++)
        {
            printf("%d",i);
        }
        printf("\n");
    }

    return 0;
}