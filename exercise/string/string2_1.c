#include <stdio.h>
#include <string.h>

void translate(const char *sPtr);
int main(void)
{
    char string[100];

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

void translate(const char *sPtr)
{
    int len=strlen(sPtr);
    for(int i=0;i<len;i++)
    {
        if(sPtr[i]=='c' && sPtr[i+1]=='a' && sPtr[i+2]=='t')
        {
            printf("CAT");
            i=i+2;
        }
        else if(sPtr[i]=='d' && sPtr[i+1]=='o' && sPtr[i+2]=='g')
        {
            printf("DOG");
            i=i+2;
        }
        else
        {
            printf("%c",sPtr[i]);
        }
        
    }
    printf("\n");
}