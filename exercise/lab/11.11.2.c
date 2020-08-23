#include <stdio.h>

struct person{
    char lastname[15];
    char firstname[15];
    char age[4];
};

void write_file(FILE *fPtr);

int main(void)
{
    FILE *cfPtr;

    if((cfPtr=fopen("nameage.dat","rb+"))==NULL)
    {
        printf("The file does not exist.\n");
    }
    else
    {
        write_file(cfPtr);
    }
    fclose(cfPtr);
}

void write_file(FILE *fPtr)
{
    for(int i=0;i<10;i++)
    {
        struct person record={"","","0"};

        printf("Please enter last name: ");
        scanf("%14s",record.lastname);

        printf("Please enter first name: ");
        scanf("%14s",record.firstname);

        printf("Please enter age: ");
        scanf("%3s",record.age);

        fseek(fPtr,i*sizeof(struct person),SEEK_SET);
        fwrite(&record,sizeof(struct person),1,fPtr);
    }
}