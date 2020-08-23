#include <stdio.h>

struct tool{
    int record;
    char tool_name[20];
    int quantity;
    double cost;
};

int main(void)
{
    FILE* cfPtr;
    if((cfPtr=fopen("toollist.dat","wb"))==NULL)
    {
        printf("File cannot be opened.\n");
    }
    else
    {
        struct tool blank={0,"",0,0.0};

        for(int i=0;i<100;i++)
        {
            fseek(cfPtr,i*sizeof(struct tool),SEEK_SET);
            fwrite(&blank,sizeof(struct tool),1,cfPtr);
        }
    }
    fclose(cfPtr);
}