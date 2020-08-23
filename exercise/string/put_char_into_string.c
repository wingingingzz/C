#include <stdio.h>

void input(char * sPtr, char a, char b);

int main(void)
{
    char string[3];

    char a;
    char b;

    while(1)
    {
        printf("Enter a: ");
        scanf("%c%*c",&a);         // %c%*c; if %c, '\n' will remain in input buffer and be read by b

        if (a=='q')
        {
            break;
        }
        printf("Enter b: ");
        scanf("%c%*c",&b);

        input(string, a, b);
    }

    return 0;
}

void input(char * sPtr, char a, char b)
{
    *sPtr=a;
    *(sPtr+1)=b;
    *(sPtr+2)='\0';
    puts(sPtr);
    //printf("1\n");
}