#include <stdio.h>

int main(void)
{
    int weight;
    int height;
    float BMI;
    

    printf("Please enter your weight(in kg):");
    scanf("%d",&weight);
    printf("Please enter your height(in metre):");
    scanf("%d",&height);

    BMI=weight/(height*height);
    printf("Your BMI is %.1f\n",BMI);

    if (BMI<=0)
    {
        printf("invalid input");
    }
    else if (BMI<=18.4)
    {
        printf("Your category is Underweight");
    }
    else if (BMI<24.9)
    {
        printf("Your category is Normal");
    }
    else if (BMI<30.0)
    {
        printf("Your category is Overweight");
    }
    else
    {
        printf("Your category is Obese");
    }
    printf("\n");
    return 0;
}