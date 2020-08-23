#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void alternate(const char* str);

int main(void)
{
    char s[100];

    int i=0;
    int c;                                  //getchar return int
    while((i<99)&&(c=getchar())!='\n')  //encounter '\n', stop input; max input char number is SIZE-1
    {
        s[i++]=c;
    }
    s[i]='\0';

    alternate(s);
    
    return 0;
}

void alternate(const char* str)
{
    int len=strlen(str);
    int i=0;
    int ch;
    for (i=0;i<len;i++)
    {

        if (i%2==0)
        {
            ch=toupper(str[i]);
            printf("%c",ch);
        }
        else
        {
            ch=tolower(str[i]);
            printf("%c",ch);
        }
        
    }
    printf("\n");
}