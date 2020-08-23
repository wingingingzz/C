#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 80

char *deletespace(const char *sPtr);

int main(void)
{
    char string[SIZE];
    printf("Please enter a string: ");

    int i=0;
    int c;                                  //getchar return int
    while((i<SIZE-1)&&(c=getchar())!='\n')  //encounter '\n', stop input; max input char number is SIZE-1
    {
        string[i++]=c;
    }
    string[i]='\0';
    int len=strlen(string);
    printf("%d\n",len);
    
    deletespace(string);
    return 0;
}

char *deletespace(const char *sPtr)
{
    int len=strlen(sPtr);
    printf("%d\n",len);
    int start=0;
    int end=0;
    int i=0;
    int k=len-1;

    while(1)
    {
        if(sPtr[i]==' ')
        {
            i++;
        }
        else
        {
            start=i;
            break;
        }       
    }
    printf("%d\n",start);

    while(1)
    {
        if(sPtr[k--]==' ')
        {
            k--;
        }
        else
        {
            end=k+1;
            break;
        }       
    }
    printf("%d\n",end);

    char* copy = (char*)malloc(len+1);
    /*if(NULL==copy)
    {
        exit(0);
    }*/

    int j;
    for(j=start;j<=end;j++)
    {
        copy[j-start]=sPtr[j];
        printf("%c",sPtr[j]);
    }
    printf("\n");
    return copy;
    free(copy);
}