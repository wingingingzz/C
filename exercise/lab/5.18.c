#include <stdio.h>

int isEven(int a);

int main(void)
{
    int a;
    int rslt;//variable name in main function must be different from function name
    printf("Please enter an integer: ");
    scanf("%d",&a);
    rslt=isEven(a);
    if(rslt==1)
    {
        printf("%d is even",a);
    }
    else
    {
        printf("%d is odd",a);
    }
    printf("\n");
    
    return 0;
}

int isEven(int a)
{
    if(a%2==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    

}