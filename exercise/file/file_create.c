#include <stdio.h>

struct clientData{
    int acctNum;
    char name[15];
    double balance;
};

void create_file(void);

int main(void)
{
    create_file();
    return 0;
}

void create_file(void)
{
    FILE *cfPtr;

    if((cfPtr=fopen("accounts.dat","wb"))==NULL)
    {
        printf("File could not opened.\n");
    }
    else
    {        
        struct clientData blankClient={0,"",0.0};
        
        for(int i=0;i<100;i++)
        {
            fwrite(&blankClient,sizeof(struct clientData),1,cfPtr);
        }
        fclose(cfPtr);
    }
    
}