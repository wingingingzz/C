#include <stdio.h>

unsigned long long int fibonacci(unsigned int a);

int main(void)
{
    unsigned int s;
    printf("Please enter the sequence: ");
    scanf("%u",&s);
    unsigned long long int rslt=fibonacci(s);
    printf("fibonacci(%u)=%llu",s,rslt);
    
    printf("\n");
    return 0;
}

unsigned long long int fibonacci(unsigned int a)
{
    unsigned long long int hold1=0;
    unsigned long long int hold2=1;
    unsigned long long int num;
    for(int i=3;i<=a;i++)
    {
        //int temp;
        num=hold1+hold2;
        hold1=hold2;
        hold2=num;
    }
    return num;
}