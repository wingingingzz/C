#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* Split(const char* text);

int main(void)
{
    char a[] = "hello,world,good,morning";
    char *copy=Split(a);
    printf("%s\n",copy);
    return 0;
}

char* Split(const char* text)
{
    int len=strlen(text);
    char* copy=(char*)malloc(len+1);
    if(NULL==copy)
    {
        exit(0);
    }
    for(int i=0;i<len;i++)
    {
        if(text[i]=='\0')
        {
            break;
        }
        if(text[i]==',')
        {
            copy[i]='\n';
        }
        else
        {
            copy[i]=text[i];
        }
        
    }
    printf("%s\n",copy);
    return copy;
    free(copy);
}

