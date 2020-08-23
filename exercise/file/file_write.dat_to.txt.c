#include <stdio.h>

struct clientData{
    int acctNum;
    char name[15];
    double balance;
};

void write_dat_to_txt(FILE *fPtr);

int main(void)
{
    FILE *cfPtr;

    if((cfPtr=fopen("accounts.dat","rb"))==NULL)
    {
        printf("The file is not existent.\n");
    }
    else
    {
        write_dat_to_txt(cfPtr);
    }
    
    fclose(cfPtr);
    return 0;
}

void write_dat_to_txt(FILE *readPtr)
{
    FILE *writePtr;

    if((writePtr=fopen("accounts.txt","w"))==NULL)
    {
        printf("File cannot be opened.\n");
    }
    else
    {
        rewind(readPtr);

        while(!feof(readPtr))
        {
            struct clientData client={0,"",0.0};

            int result=fread(&client,sizeof(struct clientData),1,readPtr);
            if(result!=0 && client.acctNum!=0)
            {
                fprintf(writePtr,"%d %s %lf\n",client.acctNum,client.name,client.balance);
            }
        }
    }
}