#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[12]="I am happy!";
    char str2[10]="I am sad.";

    printf("%s\n", strcat(str2, str1));
    printf("%c\n", str2[13]);
}