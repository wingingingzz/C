#include <stdio.h>

int main(void)
{
    FILE *cfPtr=fopen("sequentialFile.txt","r");
    if(cfPtr==NULL)
    {
        printf("open error!\n");
        return 1;
    }

    char read[257];

    while(fgets(read,257,cfPtr)!=NULL)
        printf("%s",read);

    fclose(cfPtr);
    return 0;
}