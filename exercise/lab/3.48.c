#include <stdio.h>
#include <math.h>

int main(void)
{
    int input;
    int digit=0;
    float output;
    int i;

    printf("Please enter a four-digit: ");
    scanf("%d",&input);

    for(i=3;i>0;i--)
    {
        int x;
        x=pow(10,i);
        digit=digit+(input/x+7)*x;
        input=input%x;
        
    }
    output=digit/10;
    printf("%f\n",output);
    return 0;
}