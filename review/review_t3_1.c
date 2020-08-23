#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    bool a;
    int b;
    for (a=0; a<10; a++)
    {
        b++;
        printf("%d %d\n", a, b);
    }
}