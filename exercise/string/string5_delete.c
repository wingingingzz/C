#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 80

void delete(const char *str,int key);

int main(void)
{
    const char *string="I am happy.";
    char a='a';
    delete(string,a);

    return 0;
}

void delete(const char *str,int key)
{
    int len=strlen(str);
    char *copy=(char*)malloc(len+1);

    int i=0;
    int j=0;
    for(i=0;i<len;i++)
    {
        if(str[i]==key)
        {
            continue;
        }
        else
        {
            copy[j]=str[i];
            printf("%c",str[i]);
            j++;
        }       
    }
    copy[j]='\0';
    printf("%s",copy);
}