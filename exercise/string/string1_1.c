#include <stdio.h>
#include <string.h>

void print_string(const char *sPtr);

int main(void)
{
    char string[100];

    int c;
    int i=0;
    while((i<99)&&((c=getchar())!='\n'))
    {
        string[i]=c;
        i++;
    }
    string[i]='\0';

    print_string(string);
    
    return 0;
}

void print_string(const char *sPtr)
{
    int len=strlen(sPtr);
    int i=0;
    while(sPtr[i]!='\0'||i<len)
    {
        if(sPtr[i]==' ')
        {
            printf(" ");
        }
        else
        {
            printf("%c ",sPtr[i]);
        }
        i++;
    }
    printf("\n");
}