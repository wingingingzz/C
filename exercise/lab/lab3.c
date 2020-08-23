#include <stdio.h>

int main(void)
{
    int int1,int2;
    char opr;
    int output;
    while (1)
    {
        printf("please enter i.e. 1+2 or 0r0 to exit： ");
        scanf("%d%c%d",&int1,&opr,&int2);

        if(opr=='+')
        {
            output=int1+int2;
            printf("%d%c%d=%d\n",int1,opr,int2,output);

        }
        else if(opr=='*')
        {
            output=int1*int2;
            printf("%d%c%d=%d\n",int1,opr,int2,output);
        }
        else if(opr=='%')
        {
            output=int1%int2;
            printf("%d%c%d=%d\n",int1,opr,int2,output);
        }
        else if(opr=='r')
        {
            printf("finished");
            break;
        }
        else
        {
            printf("invalid input");
        }
        
    }
    printf("\n");
    return 0;
}