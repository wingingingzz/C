#include <stdio.h>
#include <string.h>
#define SIZE 80

void reverse(const char *sPtr);

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
    //scanf("%79s",string);
    reverse(string);
    //printf("%s",string);
    return 0;
}

void reverse(const char *sPtr)
{
    int count=strlen(sPtr);
    char r[SIZE];
    int end=count-1;
    int begin=0;
    for(begin=0;begin<count;begin++)
    {
        r[begin]=sPtr[end];
        end=end-1;
    }
    r[begin]='\0';
    //for(int i=0;)
    printf("%s\n",r);
}