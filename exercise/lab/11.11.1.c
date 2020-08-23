#include <stdio.h>

struct person{
    char lastname[15];
    char firstname[15];
    char age[4];
};

void create_file(FILE *fPtr);

int main(void)
{
    FILE *cfPtr;

    if((cfPtr=fopen("nameage.dat","wb"))==NULL)
    {
        printf("File cannot be opened.\n");
    }
    else
    {
        create_file(cfPtr);
    }
    
    fclose(cfPtr);
}

void create_file(FILE *fPtr)
{
    struct person blankperson={"unassigned","","0"};

    for(int i=0;i<100;i++)
    {
        fseek(fPtr,i*sizeof(struct person),SEEK_SET);
        fwrite(&blankperson,sizeof(struct person),1,fPtr);
    }
}