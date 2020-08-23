

#include <stdio.h>

int main(void)
{
    int a = 3;
    int b = 2;
    if(a!=b) 
    { 
        if(a>b) 
            printf("a>b\n"); 
        else if(a=0) 
            printf("a=0\n");
    } 
    else if(a==0) 
        printf("a=b=0\n"); 
    else 
        printf("a=%d\n",a);
}