#include <stdio.h>
int main(void)
{
    int a = 2;
    char b = 'A';
    float c = 1.5;
    double d = 3.1415926;

    float x = a+b+c+d;
    printf("%f\n", x);
    printf("%lf\n", x); //会把float转成double吗

    
    d=a*a*d;
    printf("%lf\n", d);
    b++;
    printf("%c\n", b);

    return 0;
}