#include <stdio.h> 

int main(int argc, char *argv[])
{ 
    FILE *fptr; 
    char c;
    
    if(argv[2]!=NULL)
    {
        printf("Error.\n");
        return 1;
    }
    fptr = fopen(argv[1], "r");
    if (fptr == NULL)
    { 
        printf("Error.\n");
        return 1;
    } 

    c = fgetc(fptr);
    int count=0;
    while (c != EOF) 
    {
        if(c=='s') 
        {
            count++;
        }
        c = fgetc(fptr); 
    } 
    printf("The file contains %d 's' chars.\n",count);

    fclose(fptr);
    return 0; 
}