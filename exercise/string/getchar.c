#include <stdio.h>

int main(void)
{
    char myString[10]={'\0'};

    printf("Enter:");
    scanf("%[^\n]", myString);
    printf("%s\n",myString);
    printf("Enter:");
    scanf("%[abc ]", myString);//non sense

    printf("%s\n", myString);
    return 0;
}
