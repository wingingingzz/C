#include <stdio.h>

int main(void)
{
    int size;

    printf("Please enter a number:");
    scanf("%d",&size);
    if (size<=0)
    {
        printf("Invalid Input");
    }
    else
    {
        for (int i=0; i<size; i++)
        {
            for (int j=0; j<size; j++)
            {
                printf("*");
            }
        printf("\n");
        } 
    }
    return 0;
}