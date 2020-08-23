#include <stdio.h>
#define MONTH 12

int main(void)
{
    int arr1[MONTH];
    //int rainfall;

    for(size_t i=0;i<MONTH;i++)
    {
        printf("Please enter the %d month of rainfall: ",i+1);
        scanf("%d",&arr1[i]);
    }
    char arr2[MONTH]={'J','F','M','A','M','J','J','A','S','O','N','D'};//imp!!

    puts("Result");
    
    printf("Month       Rainfall");

    for(int j=0;j<MONTH;j++)
    {
        printf("%6s%17d\n",arr2[j],arr1[j]);
    }

    int sum=0;
    for(int k=0;k<MONTH;k++)
    {
        sum=sum+arr1[k];
    }
    int average=sum/12;
    printf("Average is: %d\n",average);

    return 0;
}