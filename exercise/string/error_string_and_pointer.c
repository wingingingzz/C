#include <stdio.h>
#include <string.h>

int main(void)
{
    const char *str;
    printf("Please enter a string: ");
    scanf("%s",str);

    int count;
    int len=strlen(*str);
    for(int i=0;i<len;i++)
    {
        if(*str==' ')
        {
            printf("The len is %d\n",count);
            count=0;
        }
        else
        {
            count=count+1;
        }
    }
    
    return 0;
}