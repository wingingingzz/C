#include <stdio.h>
#define SIZE 80

int main(void)
{
    char string[SIZE];
    fgets(string, SIZE, stdin);     //input string from key board
    int count=0;
    while (string[count] != '\0')
    {
        count++;
    }
    printf("%d",count);
    return 0;
}