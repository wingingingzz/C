#include <stdio.h>

unsigned long long int fibonacci(unsigned int a);

int main(void)
{
    unsigned int s;
    printf("Please enter a sequence: ");
    scanf("%u",&s);
    unsigned long long int rslt=fibonacci(s);
    printf("fibonacci(%u)=%llu",s,rslt);
    
    printf("\n");
    return 0;
}

unsigned long long int fibonacci(unsigned int a)
{
    if (a==0||a==1)
    {
        return a;
    }
    else
    {
        return fibonacci(a-1)+fibonacci(a-2);
    }

}