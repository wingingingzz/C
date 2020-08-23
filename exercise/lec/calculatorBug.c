#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char opr;
    int a,b;
    int i;
    
    do
    {
        printf("Please enter two integers and operator,only+,-,*(i.e. 1 + 2):");
        scanf("%d %s %d",&a,&opr,&b);
        if (opr='+')
        {
            printf("The answer is %d\n",a+b);
        }
        else if (opr='-')
        {
            printf("The answer is %d\n",a-b);
        }
        else if (opr='*')
        {
            printf("The answer is %d\n",a*b);
        }
        else
        {
            printf("invalid input");
        }
        
    } while (i=1);
    
    return 0;
}