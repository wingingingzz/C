#include <stdio.h>

struct clientData{
    int acctNum;
    char name[15];
    double balance;
};

void read_record(FILE *fPtr);

int main(void)
{
    FILE* cfPtr;

    if((cfPtr=fopen("accounts.dat","rb"))==NULL)
    {
        printf("The file does not exist.\n");
    }
    else
    {
        read_record(cfPtr);
    }
    
    fclose(cfPtr);
}

void read_record(FILE *fPtr)
{
    struct clientData client={0,"",0.0};

    int accountnum;
    printf("Please enter account number: ");
    scanf("%d",&accountnum);

    if(accountnum<=0 || accountnum>100)
    {
        printf("Invalid input!\n");
        return;
    }

    fseek(fPtr,(accountnum-1)*sizeof(struct clientData),SEEK_SET);
    int result_r=fread(&client,sizeof(struct clientData),1,fPtr);

    if(result_r==1)
    {
        if(client.acctNum==0)
        {
            printf("No record exists.\n");
        }
        else
        {
            printf("%d %s %lf\n",client.acctNum,client.name,client.balance);
        }
    }
}