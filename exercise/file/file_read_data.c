#include <stdio.h>

struct clientData{
    int acctNum;
    char name[15];
    double balance;
};

void read_data(FILE *fPtr);

int main(void)
{
    FILE *cfPtr;

    if((cfPtr=fopen("accounts.dat","rb"))==NULL)
    {
        printf("The file is not existent.\n");
    }
    else
    {
        read_data(cfPtr);
    }
    return 0;
}

void read_data(FILE *fPtr)
{

    while(!feof(fPtr))
    {
        struct clientData client={0,"",0.0};

        int result=fread(&client,sizeof(struct clientData),1,fPtr);

        if(result!=0 && client.acctNum!=0)
        {
            printf("%d %s %lf\n",client.acctNum,client.name,client.balance);
        }
    }
}