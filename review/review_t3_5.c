#include <stdio.h>
int main() 
{ 
    // output相同
    for(int i=0; i<1; i++)
    {
        printf("%d\n", i);
    }

    int j=0;
    while(j<1)
    {
        printf("%d\n",j);
        j++;
    }

    int m=0;
    do
    {
        printf("%d\n",m);
        m++;
    } while (m<1);

    int k=0;
    while(k<1)
    {
        k++;
        printf("%d\n",k);
    }

    return 0;
}