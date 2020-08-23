#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void delete(const char *str,const char *key);

int main(void)
{
    const char *string="I am happy.";
    char a='a';
    const char *dlt="happy";
    delete(string,dlt);

    return 0;
}

void delete(const char *str,const char *key)
{
    int len=strlen(str);
    printf("before=%d\n",len);
    char *copy=(char*)malloc(len+1);

    int i=0;
    int j=0;
    int k=0;
    for(i=0;i<len;i++)
    {
        char ch1=str[i];
        char ch2=key[k];
        if(ch1==ch2)                //不能str[i]==str[k]
        {
            //printf("%c",key[k]);
            k++;
            continue;
        }
        else
        {
            copy[j]=ch1;
            //printf("%c",str[i]);
            j++;
        }       
    }
    copy[j]='\0';

    int lenaf=strlen(copy);
    printf("after=%d\n",lenaf);
    printf("%s\n",copy);
}