#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    bool a = true;  // true == 1 
    char x = 'A';   // 'A' == 65
    int b = 2;
    float c = 3;
    double d = 3.1415926;

    b = b/3*c;
    printf("%d\n", b);
    c = a/2.0*c;
    printf("%f\n", c);
    d = d*2/a;
    printf("%f\n", d);
    printf("%d\n", a);
    a=a+1;
    printf("%d\n", a);
    x = x+1;
    printf("%c\n", x);

    return 0;
}