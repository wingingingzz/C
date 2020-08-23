#include <stdio.h>
#define SIZE 80

void reverse(const char * const sPtr);

int main(void)
{
    char sentence[SIZE];
    puts("Please enter a string: ");    //puts add '\n' automatically

    fgets(sentence, SIZE, stdin);       //input string from key board

    printf("\n%s","The reverse of the sentence is: ");
    reverse(sentence);
    
    return 0;
}

void reverse(const char * const sPtr)
{
    if(sPtr[0]=='\0')
    {
        return;
    }
    else
    {
        reverse(&sPtr[1]);
        putchar(sPtr[0]);
    }
}