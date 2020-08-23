#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void translate(const char* str);

int main()
{
    char string[100];
    printf("Please enter a string: ");

    int i=0;
    int c;                                  //getchar return int
    while((i<99)&&(c=getchar())!='\n')  //encounter '\n', stop input; max input char number is SIZE-1
    {
        string[i++]=c;
    }
    string[i]='\0';

    translate(string);
    return 0;
}

void translate(const char* str)
{
    const char *p=str;
    char ch=*p;
    while (*p)
    {
        if (ch=='\0')
        {
            break;
        }
        
        if (ch=='a')
        {
            printf("@-@");
        }
        else if (ch=='b')
        {
            printf("QAQ");
        }
        else
        {
            printf("%c",ch);
        }
        p++;
        ch=*p;
    }
    printf("\n");
}