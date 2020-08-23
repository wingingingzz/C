#include <stdio.h>

struct clientData{
    int acctNum;
    char name[15];
    double balance;
};

void write_data(FILE *fPtr);
void print_file(FILE *fPtr);

int main(void)
{
    FILE *cfPtr;

    if((cfPtr=fopen("accounts.dat","rb+"))==NULL)
    {
        printf("The file is not existent.\n");
    }
    else
    {
        write_data(cfPtr);
        print_file(cfPtr);
    }
    fclose(cfPtr);///////////////////////////////////////////
    return 0;
}

void write_data(FILE *fPtr)
{
    struct clientData client={0,"",0.0};

    printf("Please enter account number: ");
    scanf("%d",&client.acctNum);

    while(client.acctNum!=0)
    {
        printf("Please enter name: ");
        fscanf(stdin,"%s",client.name);

        printf("Please enter balance: ");
        fscanf(stdin,"%lf",&client.balance);

        fseek(fPtr,(client.acctNum-1)*sizeof(struct clientData),SEEK_SET);
        fwrite(&client,sizeof(struct clientData),1,fPtr);

        printf("Please enter account number: ");
        scanf("%d",&client.acctNum);
    }
}

void print_file(FILE *fPtr)
{

}