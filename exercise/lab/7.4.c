#include <stdio.h>

void cubeByReference(int *nPtr);

int main(void)
{
    int number=5;
    printf("The original number is %d\n",number);

    int *nPtr=&number;

    cubeByReference(nPtr);//pass the address of argument as parameter

    printf("The result is %d\n",number);

    return 0;
}

void cubeByReference(int *nPtr)
{
    int hold=*nPtr;
    *nPtr=hold*hold*hold;
}