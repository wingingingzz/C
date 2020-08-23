#include <stdio.h>

struct tool{
    int record;
    char tool_name[20];
    int quantity;
    double cost;
};

int menu(void);
void input(FILE* fPtr);
void print(FILE *fPtr);
void delete(FILE* fPtr);
void update(FILE* fPtr);

int main(void)
{
    FILE *cfPtr;

    if((cfPtr=fopen("toollist.dat","rb+"))==NULL)
    {
        printf("File cannot be opened.\n");
        return 0;
    }

    int choice;
    while((choice=menu())!=0)
    {
        switch (choice)
        {
        case 1:
            input(cfPtr);
            break;

        case 2:
            print(cfPtr);
            break;

        case 3:
            delete(cfPtr);
            break;

        case 4:
            update(cfPtr);
            break;
        
        default:
            printf("Invalid input!\n\n");
            break;
        }
    }
    fclose(cfPtr);
}

int menu(void)
{
    printf("Option 1: input.\n");
    printf("Option 2: list all.\n");
    printf("Option 3: delete.\n");
    printf("Option 4: update.\n");
    printf("Option 0: exit.\n");

    int choice;
    printf("Please enter your choice: ");
    scanf("%d",&choice);

    return choice;
}

void input(FILE* fPtr)
{
    int record;
    printf("Please enter the record: ");
    scanf("%d",&record);

    struct tool toolrecord={0,"",0,0.0};
    fseek(fPtr,(record-1)*sizeof(struct tool),SEEK_SET);
    int result=fread(&toolrecord,sizeof(struct tool),1,fPtr);

    if(result==1)
    {
        if(toolrecord.record==0)
        {
            //printf("Info exists.\n");
            // /return;
            toolrecord.record=record;

            printf("Please enter toolname: ");
            scanf("%19s",toolrecord.tool_name);
            //fgets(toolrecord.tool_name,20,stdin);

            printf("Please enter quantity: ");
            scanf("%d",&toolrecord.quantity);

            printf("Please enter cost: ");
            scanf("%lf",&toolrecord.cost);

            fseek(fPtr,(toolrecord.record-1)*sizeof(struct tool),SEEK_SET);
            fwrite(&toolrecord,sizeof(struct tool),1,fPtr);
        }
        else
        {
            printf("Record exists.\n");
        }
    }
    printf("\n");
}

void print(FILE *fPtr)
{
    for(int i;i<100;i++)
    {
        struct tool toolrecord={0,"",0,0.0};

        fseek(fPtr,i*sizeof(struct tool),SEEK_SET);
        int result=fread(&toolrecord,sizeof(struct tool),1,fPtr);

        if(toolrecord.record!=0 && result==1)
            printf("%d %s %d %lf\n",toolrecord.record,toolrecord.tool_name,toolrecord.quantity,toolrecord.cost);
    }
    printf("\n");
}

void delete(FILE* fPtr)
{
    int record;
    printf("Please enter the record: ");
    scanf("%d",&record);

    struct tool toolrecord={0,"",0,0.0};
    struct tool blank={0,"",0,0.0};

    fseek(fPtr,(record-1)*sizeof(struct tool),SEEK_SET);
    int result=fread(&toolrecord,sizeof(struct tool),1,fPtr);

    if(result==1)
    {
        if(toolrecord.record==0)
        {
            printf("No record exists.\n");
            return;
        }
        printf("%d %s %d %lf\n",toolrecord.record,toolrecord.tool_name,toolrecord.quantity,toolrecord.cost);

        fseek(fPtr,(record-1)*sizeof(struct tool),SEEK_SET);
        int result_w=fwrite(&blank,sizeof(struct tool),1,fPtr);
        if(result_w==1)
        {
            printf("Delete successfully.\n");
        }
    }
    printf("\n");
}

void update(FILE* fPtr)
{
    struct tool toolrecord={0,"",0,0.0};

    int record;
    printf("Please enter the record: ");
    scanf("%d",&record);

    fseek(fPtr,(record-1)*sizeof(struct tool),SEEK_SET);
    int result=fread(&toolrecord,sizeof(struct tool),1,fPtr);

    if(result==1)
    {
        if(toolrecord.record==0)
        {
            printf("Record does not exist.\n");
            return;
        }
        printf("Original: %d %s %d %lf\n",toolrecord.record,toolrecord.tool_name,toolrecord.quantity,toolrecord.cost);

        printf("Please enter tool name: ");
        scanf("%19s",toolrecord.tool_name);

        printf("Please enter quantity: ");
        scanf("%d",&toolrecord.quantity);

        printf("Please enter cost: ");
        scanf("%lf",&toolrecord.cost);

        fseek(fPtr,(toolrecord.record-1)*sizeof(struct tool),SEEK_SET);
        int result_w=fwrite(&toolrecord,sizeof(struct tool),1,fPtr);

        if(result_w==1)
        {
            printf("Updated: %d %s %d %lf\n",toolrecord.record,toolrecord.tool_name,toolrecord.quantity,toolrecord.cost);
        }
    }
    printf("\n");
}
