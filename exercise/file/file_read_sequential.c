#include <stdio.h>

int main(void)
{
    FILE *cfPtr;

    if((cfPtr=fopen("sequentialFile.txt","r"))==NULL)
    {
        printf("File cannot be opened.\n");
    }
    else
    {
        int acctNum;
        char name[30];
        double balance;

        fscanf(cfPtr,"%d%29s%lf",&acctNum,name,&balance);

        while(!feof(cfPtr))
        {
            printf("%-10d%-13s%7.2f\n",acctNum,name,balance);
            fscanf(cfPtr,"%d%29s%lf",&acctNum,name,&balance);
        }
    }
    fclose(cfPtr);
}
