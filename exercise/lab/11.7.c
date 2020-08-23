#include <stdio.h>

struct clientData{
    int acctNum;
    char name[15];
    double balance;
};

void create_test_data(void);

int main(void)
{
    create_test_data();
    return 0;
}

void create_test_data(void)
{
    FILE *fPtr;

    if((fPtr=fopen("testdata.dat","wb"))==NULL)
    {
        printf("The file cannot be opened.\n");
    }
    else
    {
        int i=1;
        while(1)
        {
            struct clientData client={0,"",0};

            printf("Please enter account number: ");
            scanf("%d",&client.acctNum);

            if(client.acctNum==0)
            {
                break;
            }

            printf("Please enter Name: ");
            scanf("%15s",&client.name);

            printf("Please enter balance: ");
            scanf("%lf",&client.balance);

            fwrite(&client,(i-1)*sizeof(struct clientData),1,fPtr);
            i++;            
        }
    }

    fclose(fPtr);
}