// 20124865 scyqw4 Qingyu Wang

#include <stdio.h>

int clamp(int *max,int *min,int input);

int main(void)
{
    printf("Enter max value: ");
    int maxvalue;
    scanf("%d",&maxvalue);
    printf("Enter min value: ");
    int minvalue;
    scanf("%d",&minvalue);
    int input;

    if(maxvalue<minvalue)
    {
        printf("Impossible overlapping max and min values, exiting.\n");
        return 0;       
    }
    else
    {
        while(1)
        {
            printf("Enter value: ");
            scanf("%d",&input);
            if(input==-9999)
            {
                return 0;
            }
            else
            {
                printf("%d\n",clamp(&maxvalue,&minvalue,input));
            }            
        }        
    }
    return 0;
}
int clamp(int *max,int *min,int input)
{
    int judge=(*min+*max)/2;
    while(1)
    {
        
        if (input>=*max)
        {
            return *max;
        }
        else if(input<=*min)
        {
            return *min;
        }
        else
        {
            if(input>=judge)
            {
                *max=input;
                return *max;
            }
            else
            {
                *min=input;
                return *min;
            }   
        }
    }
}
