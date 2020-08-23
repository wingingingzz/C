#include <stdio.h>

void function1(int arr[]);
void function2(int *arr);

int main(void)
{
    int array[3]={1,2,3};
    int *ptr=array;

    function1(array);
    printf("%d",array[1]);

    function2(array);
    printf("%d",array[1]);

    function1(ptr);
    printf("%d",array[1]);

    function2(ptr);
    printf("%d",array[1]);
    
    return 0;
}

void function1(int arr[])
{
    *(arr+1)=5;
}

void function2(int *arr)
{
    arr[1]=5;
}