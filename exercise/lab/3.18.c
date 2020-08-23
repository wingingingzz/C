#include <stdio.h>

int main(void)
{
    float sales;
    float grossSalary;
    
    while(1)
    {
        printf("Enter sales in dollars (-1 to end): ");
        scanf("%f",&sales);

        if(sales==-1)
        {
            break;
        }
        else if(sales>=0)
        {
            grossSalary=sales*0.09+200;
            printf("Salary is: $%.2f\n\n",grossSalary);
        }
        else
        {
            printf("Invalid Input\n\n");
        }
        
        
    }

    return 0;
}