#include <stdio.h>
//#include <stdlib.h>

#define DATA_SIZE 1000

int main()
{
    /* Variable to store user content */
    char data[DATA_SIZE];

    /* File pointer to hold reference to our file */
    FILE * fPtr;


    /* 
     * Open file in w (write) mode. 
     * "data/file1.txt" is complete path to create file
     */
    fPtr = fopen("readme.txt", "w");

    /* fopen() return NULL if last operation was unsuccessful */
    if(fPtr == NULL)
    {
        /* File not created hence exit */
        printf("Unable to create file.\n");
        return 1;
    }


    /* Input contents from user to store in file */
    printf("Enter contents to store in file : \n");
    fgets(data, DATA_SIZE, stdin);

    while(!feof(stdin))
    {
        fputs(data, fPtr);
        printf("?");
        fgets(data, DATA_SIZE, stdin);
    }

    ///* Write data to file */

    /* Close file to save file data */
    fclose(fPtr);

    /* Success message */
    printf("File created and saved successfully. 🙂 \n");

    return 0;
}