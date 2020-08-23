#include <stdio.h> 
//#include <stdlib.h> // For exit() 

int main(int argc, char *argv[])
{ 
    FILE *fptr; 
    char c;
  
    // Open file 
    fptr = fopen(argv[1], "r"); 
    if (fptr == NULL) 
    { 
        printf("Error.\n"); 
        return 1;
    } 
  
    // Read contents from file 
    c = fgetc(fptr);
    int count=0;
    while (c != EOF) 
    {
        if(c=='s') 
        {
            count++;
        }
        //printf ("%c", c); 
        c = fgetc(fptr); 
    } 
    printf("The file contains %d 's' chars.",count);

    fclose(fptr); 
    return 0; 
}