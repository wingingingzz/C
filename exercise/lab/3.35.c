#include <stdio.h>
#include <math.h>

int main(void)
{
    int input;
    int decimal=0;
    printf("Please enter a number: ");
    scanf("%d",&input);
    
    for(int i=5;i>=0;i--)
    {
        int x;
        x=pow(10,i);
        decimal=decimal+(input/x)*pow(2,i);
        input=input%x;
    }
    printf("%d\n",decimal);

    return 0;
}