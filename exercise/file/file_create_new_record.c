#include <stdio.h>

struct clientData{
    int acctNum;
    char name[15];
    double balance;
};

void create_new_record(FILE *fPtr);

int main(void)
{
    FILE *cfPtr;

    if((cfPtr=fopen("accounts.dat","rb+"))==NULL)
    {
        printf("The file does not exist.\n");
    }
    else
    {
        create_new_record(cfPtr);
    }
    
    fclose(cfPtr);
}

void create_new_record(FILE *fPtr)
{
    struct clientData client={0,"",0.0};

    int accountnum;
    printf("Please enter account number: ");
    scanf("%d",&accountnum);

    fseek(fPtr,(accountnum-1)*sizeof(struct clientData),SEEK_SET);
    int result=fread(&client,sizeof(struct clientData),1,fPtr);

    if(client.acctNum!=0 && result!=0)
    {
        printf("Record exists.\n");
    }
    else
    {
        printf("Please enter name: ");
        scanf("%14s",client.name);

        printf("Please enter balance: ");
        scanf("%lf",&client.balance);

        client.acctNum=accountnum;
        
        fseek(fPtr,(client.acctNum-1)*sizeof(struct clientData),SEEK_SET);
        int result_w=fwrite(&client,sizeof(struct clientData),1,fPtr);

        if(result==1)
        {
            printf("New record: %d %s %lf\n",client.acctNum,client.name,client.balance);
        }
    }   
}