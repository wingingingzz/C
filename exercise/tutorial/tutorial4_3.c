#include <stdio.h>
#include <string.h>

int main()
{
    char a[100];
    int i;
    printf("Please enter integers (less than 100): ");
    for(i=0;i<100;i++)
    {
        scanf("%s",&a[i]);
        if(a[i]=='\n'||a[i]=='\0')//imp!!! stop scanf wherever I want to stop using \n or \0
        {
            break;
        }
    }
    a[i]='\0';//add '\0'
    printf("You have entered: %s \n", a);

    int space;
    for(int m=0; m<100; m++)
    {
        if(a[m]==' ')
        {
            space++;
            for(int j=m;j<99;j++)//j<99:array[j+1],j+1<100,j<99;
            {
                a[j] = a[j+1];
                m--;
            }
            
        }
        if(a[m]=='\0')
        {
            break;
        }
    }
    printf("Space contained: %d\n", space);
    printf("Reverse string:");
    int size = strlen(a);//strlen
    for(int k=0; k<=size; k++)
    {
        printf("%s",a[k]);
    }
    
    printf("\n");

    return 0;
}