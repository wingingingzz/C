#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_string(const char* str);

int main()
{
    char string[100];
    int i=0;
    int c;                                  //getchar return int
    while((i<99)&&(c=getchar())!='\n')  //encounter '\n', stop input; max input char number is SIZE-1
    {
        string[i++]=c;
    }
    string[i]='\0';

    print_string(string);
    return 0;
}

void print_string(const char* str)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] == 0)
            break;
        printf("%c ", str[i]);
    }
    printf("\n");
}
