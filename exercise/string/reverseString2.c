#include <stdio.h>
#define SIZE 80

void reverse(char * sPtr);

int main()
{
    char s[SIZE];
    
    printf("Input a string: ");
    fgets(s, SIZE-1, stdin);
    
    reverse(s);
    printf("%s\n", s);
    
    return 0;
}

void reverse(char * sPtr)
{
    // Calculating string length
    int count = 0;
    while (sPtr[count]!='\0')
    {
        count++;
    }

    int begin;
    int end=count-1;

    char r[SIZE];

    for (begin = 0; begin < count; begin++) {
        r[begin] = sPtr[end];
        end--;
    }    
    r[begin]='\0';
    
    for (int i=0;i<count;i++)
    {
        sPtr[i]=r[i];
    }
}