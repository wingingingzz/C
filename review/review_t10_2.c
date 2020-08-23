#include<stdio.h>
int initializer(void)
{
    return 50;
}

int main()
{
    static int i = initializer(); // 不是constant
    printf(" value of i = %d", i );
    getchar ();
    return 0;
}