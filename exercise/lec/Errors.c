#include <stdio.h>

int main(void)
{
    int a=2;
    float b=1.5;
    int c;
    c=a+b;
    b=c/a;
    printf("%d,%.2f\n", c, b);

    return 0;
}