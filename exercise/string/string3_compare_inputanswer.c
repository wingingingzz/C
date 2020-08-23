#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compare(const char* str);

int main(void)
{
    char string[100];

    while (1)
    {
        printf("Please enter my birth month: ");

        int i=0;
        int c;                                  //getchar return int
        while((i<99)&&(c=getchar())!='\n')      //encounter '\n', stop input; max input char number is SIZE-1
        {
            string[i++]=c;
        }
        string[i]='\0';

        //printf("%s",string);
        if (strcmp(string,"-1")==0)
        {
            return 0;
        }
        compare(string);
    }

    return 0;
}

void compare(const char* str)
{
    int i=0;
    if(strcmp(str,"Jan")==0 || strcmp(str,"January")==0 || strcmp(str,"1")==0)
    {
        printf("yes\n");
        exit(0);
    }
    else
    {
        printf("no");    
    }
        
    printf("\n");
}