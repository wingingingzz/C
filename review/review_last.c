#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[100]="paul";
    char str2[10]="paul likes";
    strcpy(str1,str2);
    printf("%s\n",str1);
}