#include <stdio.h>

struct person{
    char lastname[15];
    char firstname[15];
    char age[4];
};

void delete_file(FILE *fPtr);

int main(void)
{
    FILE *cfPtr;

    if((cfPtr=fopen("nameage.dat","rb+"))==NULL)
    {
        printf("The file does not exist!\n");
    }
    else
    {
        delete_file(cfPtr);
    }
    fclose(cfPtr);
}

void delete_file(FILE *fPtr)
{
    char lastname[15];
    printf("Please enter last name: ");
    scanf("%14s",lastname);

    int f=0;
    struct person blank={"unassigned","",""};

    for(int i=0;i<100;i++)
    {
        struct person record={"","",""};
        fseek(fPtr,i*sizeof(struct person),SEEK_SET);
        fread(&record,sizeof(struct person),1,fPtr);

        int flag=0;
        for(int compare=0;compare<15;compare++)
        {
            if(lastname[compare]==record.lastname[compare])
            {
                flag=1;
            }
            else
            {
                flag=0;
                break;
            }
            if(lastname[compare]=='\0')
            {
                break;
            }
        }
        
        if(flag==1)
        {
            printf("Original: %s %s %s\n",record.lastname,record.firstname,record.age);

            fseek(fPtr,i*sizeof(struct person),SEEK_SET);
            fwrite(&blank,sizeof(struct person),1,fPtr);
            printf("Delete successful!\n");
            f=1;
        }
    }
    if(f==0)
    {
        printf("No record exists.\n");
    }
}