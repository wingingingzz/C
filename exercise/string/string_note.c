#include <stdio.h>
#define SIZE 80

int main()
{
    //define a single char
    char char1;
    //user input
    scanf("%c%*c",&char1);       //to avoid '\n' remain in input buffer
    //print a single char
    putchar(char1);


    //define string/char array
    //const char *string;//1             
    char string[SIZE];
    const char *string;

    //user input
    fgets(string, SIZE, stdin);     //input string from key board
    scanf("%79s",string);           //allow user to input only 79 chars (without space!!!!) to avoid overflow

    //This one is best!!!!!!!!!!!!
    int i=0;
    int c;                                  //getchar return int
    while((i<SIZE-1)&&(c=getchar())!='\n')  //encounter '\n', stop input; max input char number is SIZE-1
    {
        string[i++]=c;
    }
    string[i]='\0';                         //terminate string

    //print string
    puts(string);                   //a '\n' at the end

    //calculate real length of array(including '\0' !!!!!!!!!!)
    int count=0;
    while (string[count] != '\0')
    {
        count++;
    }
    int len=strlen(string);


    //复制相同大小的内存
    int len=strlen(string);//不包含'\0'
    char* copy = (char*)malloc(len+1);  //复制相同大小的内存;len不包含'\0',要加上'\0'的位置

    int num = atoi(string);             //convert string to int
}