//20124865 Qingyu Wang

#include <stdio.h>

int main(void)
{
    int X;//max value
    int num;
    int i=1;

    printf("Enter max value: ");
    scanf("%d",&X);

    while(i==1)
    {
        printf("Enter number: ");
        scanf("%d",&num);

        if (num<=X-100)
        {
            printf("Too low, enter number greater than %d!\n",X-100);
        }
        else if (num>=X)
        {
            printf("Too high, enter number smaller than %d!\n",X);
        }
        else
        {
            printf("You entered %d.\n",num);
            i=0;//break
        }
    }

    return 0;
}