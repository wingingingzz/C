#include <stdio.h>
#include <string.h>

int main(void)
{
    char *arr[3];
    int i;
    arr[0]="This is";
    arr[1]="a new";
    arr[2]="msg";
    for(i=0;i<3;i++)
    {
        printf("%s %c\n", arr[i],*arr[i]);
    }
}