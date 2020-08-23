#include<stdio.h>
void func()
{
    static int value = 0;
    value++;
    printf("value: %d\n",value);
}
int main()
{
    for(int i =0;i<5;i++)
    {
        func();
    }
}