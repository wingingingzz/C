#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void converse(const char *str);

int main(void)
{
    char s[100];

    int i=0;
    int c;
    while((i<99)&&(c=getchar())!='\n')
    {
        s[i++]=c;
    }
    s[i]='\0';

    int num = atoi(s);                  //convert string to int
    printf("%d\n",num);
    return 0;
}
/*
void converse(const char *str)
{
    char *ptr=str;
    double result=strtod(str,*ptr);
}*/