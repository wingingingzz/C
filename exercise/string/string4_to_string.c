#include <stdio.h>

void to_string(const int* arr, int size, char* output);

int main(void)
{
    int num;
    printf("Please enter a number: ");
    scanf("%d",&num);

    int array[num];
    for(int i=0;i<num;i++)
    {
        printf("Please enter %d element: ",i);
        scanf("%d",&array[i]);
    }

    char str[512];

    to_string(array,num,str);

    printf("%s\n",str);
    return 0;
}

void to_string(const int* arr,int size,char* output)
{
    char buf[128];//用于保存每个arr中的元素
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        sprintf(buf, "%d,", arr[i]);//将格式化的字符串arr[i]输入一个目的字符串buf; "%d,"为format,按 format 保存
        for (int j = 0; j < buf[j]; j++)
        {
            output[count] = buf[j];
            count++;
        }
    }
    output[count] = '\0';
}