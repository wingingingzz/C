#include <stdio.h>
#include <math.h>

double hypotenuse(double a,double b);

int main(void)
{
    double a,b;//scanf: %lf (long float)
    double result;
    printf("Please enter a number as one side: ");
    scanf("%lf",&a);
    printf("Please enter a number as another side: ");
    scanf("%lf",&b);
    result=hypotenuse(a,b);
    printf("The hypotenuse is %lf\n",result);

    return 0;
}

double hypotenuse(double a,double b)
{
    double rslt;
    rslt=sqrt(a*a+b*b);
    return rslt;
}