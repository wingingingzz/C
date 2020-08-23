#include <stdio.h>

struct clientData{
    int acctNum;
    char name[15];
    double balance;
};

void update_file(FILE *fPtr);

int main(void)
{
    FILE *cfPtr;
    if((cfPtr=fopen("accounts.dat","rb+"))==NULL)
    {
        printf("The file is not existent.\n");
    }
    else
    {
        update_file(cfPtr);
    }
    
    fclose(cfPtr);
}

void update_file(FILE *fPtr)
{
    struct clientData client={0,"",0.0};

    int accountnum;
    printf("Please enter the account number: ");
    scanf("%d",&accountnum);

    fseek(fPtr,(accountnum-1)*sizeof(struct clientData),SEEK_SET);
    int result_r=fread(&client,sizeof(struct clientData),1,fPtr);

    if(result_r!=0)
    {
        if(client.acctNum==0)
        {
            printf("the record does not exist.\n");
        }
        else
        {
            printf("Original record: %d %s %lf\n",client.acctNum,client.name,client.balance);

            double balance;
            printf("Please enter the current balance: ");
            scanf("%lf",&balance);

            client.balance=balance;

            fseek(fPtr,(accountnum-1)*sizeof(struct clientData),SEEK_SET);
            int result_w=fwrite(&client,sizeof(struct clientData),1,fPtr);

            if(result_w!=0)
            {
                printf("Updated record: %d %s %lf\n",client.acctNum,client.name,client.balance);
            }
        }
    }
}