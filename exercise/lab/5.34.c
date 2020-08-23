#include <stdio.h>

long power(int a,int b);

int main(void)
{
    int base,exp;
    long rslt;
    printf("Please enter base: ");
    scanf("%d",&base);
    printf("Please enter exponent: ");
    scanf("%d",&exp);
    rslt=power(base,exp);
    printf("The result is %ld",rslt);
    printf("\n");

    return 0;
}

long power(int a,int b)
{
    long total=a;
    for(int i=b;i>1;i--)
    {
        total=total*a;
    }
    return total;
}