#include <stdio.h>

int main(void)
{
    int a = 2;
    float b = 1.5;
    int c;
    int d=b;
    printf("%d\n", d);
    c=a+b;
    printf("%d\n", c);
    b=c/a;
    printf("%f\n", b);

    float cf=3;
    int af=2;
    int bf=cf/af;
    printf("%d\n",bf);

    float e=a/3;
    printf("%f\n",e);

    return 0;
}