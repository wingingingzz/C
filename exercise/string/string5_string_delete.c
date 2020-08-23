#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 80

void delete(const char *sPtr,char key);

int main(void)
{
    char string[SIZE];
    printf("Please enter a string: ");

    int i=0;
    int c;                                  //getchar return int
    while((i<SIZE-1)&&(c=getchar())!='\n')  //encounter '\n', stop input; max input char number is SIZE-1
    {
        string[i++]=c;
    }
    string[i]='\0';
    printf("%s\n",string);

    char dlt;
    printf("Please enter the number which should be deleted: ");
    scanf("%c%*c",&dlt);

    delete(string,dlt);
    
    return 0;
}

void delete(const char *sPtr, char key) //不建议直接在sPtr里删除（被删除的元素后的每个元素前移一位），耗内存
{
    int len = strlen(sPtr);
    //printf("len=%d\n",len);
    char* copy = (char*)malloc(len+1);  //复制相同大小的内存
    if(NULL!=copy)
    {
        exit(0);
    }

    int i=0;
    int j=0;

    for(i=0;i<len;i++)
    {
        if(sPtr[i]==key)
        {
            i=i+1;
        }
        else
        {
            copy[j]=sPtr[i];
            printf("%c",sPtr[i]);
            j=j+1;
        }
        
    }

    copy[j]='\0';
    printf("%s\n",sPtr);
    free(copy);
    
}