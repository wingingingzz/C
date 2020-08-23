#include <stdio.h>

int main(void)
{
    printf("%c%c\n", "message"[4], *("message"+4));
}