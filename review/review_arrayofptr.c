#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[10]="Hello\0";
    char str2[10]="Hello";
    char *str3="Hello";
    
    printf("%s\n",str1);
    printf("%s\n",str2);

    printf("%d\n",sizeof(str2));
    printf("%d\n",sizeof(str3));

    printf("%d\n",strlen(str2));
    printf("%d\n",strlen(str2));

    return 0;
}