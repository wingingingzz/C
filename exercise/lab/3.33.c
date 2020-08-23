#include <stdio.h>

int main(void)
{
    int size;
    printf("Please enter a number:");
    scanf("%d",&size);

    if (size<=0)
    {
        printf("invalid input");
    }
    for (int i=0;i<size;i++)
    {
        for (int j=0;j<size;j++)
        {
            if (i==0||i==size-1||j==0||j==size-1)
            {
                printf("*");
            }
            else 
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return 0;
}