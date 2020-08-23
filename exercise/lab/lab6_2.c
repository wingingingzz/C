#include <stdio.h>
#include <time.h>
#include <string.h>

void randWord(char string1[]);

int main(void)
{
    int num;
    printf("Number of words: ");
    scanf("%d",&num);

    char word[100];
    for(int i=0;i<num;i++)
    {
        printf("Enter word: ");
        scanf("%s",&word[i]);
    }
    printf("\n");



    return 0;
}


void randWord(char string1[]){
    strand(time(NULL));
    int c=strlen(string1)-1;
    int testlen;
    int live=5;
    for(int i=1;i<=5;i++)
    {
        printf("Word:");
        int j=1;
        char s;
        while(j<=c)
        {
            int seq=1+rand()%c;
            if(j==seq)
            {
                printf(" %c",string1[seq-1]);
            }
            else
            {
                printf(" _");
            }
            j=j+1;
        }
        printf("Guess (%d lives): ",6-i);
        scanf("%c",s);
        for(int k=0;k<c;k++)
        {
            if(s==string1[k])
            {

            }
        }
        
    }
}