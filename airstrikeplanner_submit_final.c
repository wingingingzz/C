// 20124865 scyqw4 Qingyu Wang

/* Any user inputs are terminated with '\n', spaces ' ' will not be ignored, except "load a file".
** 
** Main:
**      Display the menu.
**      User input option, and check if user input is valid.
**      If user enters nothing and press ENRER, do nothing and return to main.
**      If the input is invalid, print an error message.
**      Maintain a linked list that stored all targets that is not destroyed until exit the program.
** Load a target file:
**      First, check if the file name entered by user is valid, if valid, next step; else, print an error message.
**      If user enters nothing and press ENRER, do nothing and return to main.
**      Next, check if the file is valid, if invalid, print an error message;
**      If the file is valid, check if the target is conflict with previous targets (distance < 0.1);
**      If not conflict, store the target into linked list.
** Show current targets:
**      First, print all targets in format ("name latitude longitude", one target per line).
**      Next, display a 2D map with all targets.
**      Use the actual number of targets in the same place after rounding off (0 to 9 and '*' for over 9 targets) to represent targets.
**      If the linked list is empty, the empty 2D map will not display.
**      Every time Option 2 is choosed, the 2D map will newly created according to the linked list and will not maintain until the next Option 2,
**      as it is hard to delete a single target from the map, especailly when there are over 9 targets in the same place.
** Search a target:
**      User input target name. If user input nothing and press ENTER, do nothing and return to main.
**      All targets with the entered name will be printed.
**      If no target with such name, a message will be printed.
** Plan an airstrike:
**      User input latitude, longitude of the targeted collision point and ratio. 
**      If user input nothing and press ENTER, do nothing and return to main menu.
**      If user input invalid latitude, longitude (not a positive double, out of the range), or invalid ratio (not a positive double), do nothing and return to main menu.
**      The length of latitude, longitude, or ratio is not limited (Over 15 digits or decimal point is valid).
**      Display all the targets within the damage zone.
**      If the target lies on the boundary of the damage zone, it will also be planned.
** Execute an airstrike:
**      User input latitude, longitude the targeted collision point and ratio.
**      If user input nothing and press ENTER, do nothing and return to main.
**      If user input invalid latitude, longitude (not a positive double, out of the range), or invalid ratio (not a positive double), do nothing and return to main menu.
**      The length of latitude, longitude, or ratio is not limited (Over 15 digits or decimal point is valid).
**      Count the number of targets that are destroyed. Print all destroyed targets.
**      Delete the targets that should be destroyed from the linked list.
**      If the target lies on the boundary of the damage zone, it will also be destroyed.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define SIZE 16
#define BUFFER 100
#define ROW 40
#define COLUMN 80

// self-referential structure
struct target
{
    char targetName[SIZE]; // maximum: 15 chars with a '\0'
    double latitude;
    double longitude;
    struct target *next; // target ptr
};

typedef struct target Target; // synonym for struct target

// display the option menu
void menu(void);
// load the target file
// take a ptr to linked list as an argument
// append all targets to the linked list if the file is valid; do nothing and return to main menu if the target file is invalid
void load_target_file(Target **head);
// check whether file is valid or not
// take a ptr to file as an argument
// return 1 if the file is valid; 0 otherwise
int isvalid_file(FILE *cPtr);
// check whether target name is valid or not
// take a read-only string as an argument
// return 1 if the string only contains letters and digits; 0 otherwise
int isalnum_str(const char *str);
// check whether the string can be converted to a positive double
// take a read-only string as an argument
// return 1 if the string only contains digits and only one '.' (the first or last char is '.' also invalid); 0 otherwise
int isdouble_str(const char *str);
// check whether current target conflicts with previous targets (distance is smaller than the given range)
// return 1 if conflict; 0 otherwise
int conflict(Target *head,double val1,double val2,double range);
// Given a list, append the given value to the list
// exit if append unsuccessful
void append_list(Target **head,char *str,double val1,double val2);
// print the given linked list
void print_list(Target *head);
// display a 80*40 (width*height) 2D map with all the targets in the linked list
void map_2d(Target *head);
// take a 2D map, a str which needs adding to the 2d map, the row r it needs adding to, start of the column c_start it needs adding to as arguments
// return ptr to the 2D map with the added str
char *map_str(char map[ROW][COLUMN],const char *str,int r,int c_start);
// take a 2D map, a linked list with all targets as arguments
// return ptr to the 2D map to which all targets has been added
char *map_target(char map[ROW][COLUMN],Target *head);
// user inputs a target name to search for
// if the target name exists, print all the targets with entered name; otherwise, print a message
// do nothing and return to main menu if user press ENTER without any other chars
void search_target(Target *head);
// user inputs latitude, longitude, ratio to determine the damage zone
// display all the targets within the damage zone (boundaries inclusive)
void plan_airstrike(Target *head);
// user inputs latitude, longitude, ratio to determine the damage zone
// count the number of targets within the damage zone (boundaries inclusive), that are destroyed
// and all targets within the damage zone (boundaries inclusive), that are destroyed
// delete these targets from the linked list
void execute_airstrike(Target **head);
// given a linked list, free all the elements of the list and set the head to NULL
void destroy_list(Target **head);


int main(void)
{
    menu(); // display the menu

    char bufOption[BUFFER]; // store user input Option as a string
    Target *tgt = NULL; // create a ptr to an empty linked list to store targets in valid file
    for(;;)
    {
        printf("Option: ");
        setbuf(stdin, NULL); // clear stdin
        fgets(bufOption, BUFFER-1, stdin);
        // If the user presses ENTER without entering any other chars, then this option will do nothing else
        if(bufOption[0] == '\n')
        {
            continue;
        }
        //find '\n' and replace it using '\0', as '\n' always exists in string attained by fgets
        char *findNewline = strchr(bufOption, '\n');
        if(findNewline)
        {
            *findNewline = '\0'; 
        }
        // check if the option entered by user is invalid; only 1, 2, 3, 4, 5, 6 are valid
        if(bufOption[1] != '\0' || (bufOption[0] < '1' || bufOption[0] > '6'))
        {
            printf("Unknown option.\n");
            continue;
        }

        if(bufOption[0] == '6') // exit if option=6
        {
            break;
        }
        if(bufOption[0] == '1') // load a target file if option=1, store targets in linked list if valid
        {
            load_target_file(&tgt);
        }
        if(tgt == NULL) // continue to prompt for user input Option until valid file is loaded or linked list is not empty
        {
            continue;
        }
        if(bufOption[0] == '2') // only when linked list is not empty, print all targets and display a 2d map containing all targets if option=2
        {
            print_list(tgt); // print all targets stored in the linked list
            map_2d(tgt); // display a 2d map containing all targets 
        }
        if(bufOption[0] == '3') // search a target if option=3
        {
            search_target(tgt);
        }
        if(bufOption[0] == '4') // plan an airstrike if option=4
        {
            plan_airstrike(tgt);
        }
        if(bufOption[0] == '5') // execute an airstrike if option=4
        {
            execute_airstrike(&tgt);
        }
    }
    destroy_list(&tgt);//free allocated memory and set ptr to NULL
    return 0;
}

void menu(void)
{
    printf("1) Load a target file\n2) Show current targets\n3) Search a target\n4) Plan an airstrike\n5) Execute an airstrike\n6) Quit\n");
}

void load_target_file(Target **head)
{
    FILE *cfPtr; // create a file ptr

    char fileName[BUFFER]; // store user input file name as a str
    printf("Enter a target file: ");
    setbuf(stdin, NULL); // clear stdin
    fgets(fileName, BUFFER-1 , stdin);
    // If the user presses ENTER without entering any other chars, then this option will do nothing and return to main menu.
    if(fileName[0] == '\n')
    {
        return;
    }
    //find '\n' and replace it using '\0' as '\n' always exists in string attained by fgets
    char *findNewline = strchr(fileName, '\n');
    if(findNewline)
    {
        *findNewline = '\0';
    }

    // file cannot be opened or file does not exist
    if((cfPtr = fopen(fileName, "r")) == NULL) // open file for read only
    {
        printf("Invalid file.\n");
        return;
    }
    else
    {
        // check if the file is valid
        int isvalid = isvalid_file(cfPtr);
        if(isvalid == 0) // file is invalid
        {
            printf("Invalid file.\n");
            fclose(cfPtr); // close the file
            return;
        }
        else // file is valid
        {
            for(;;)
            {
                char tgtname[SIZE];
                double latitude, longitude;

                fscanf(cfPtr, "%15s%lf%lf", tgtname, &latitude, &longitude); // read target and store into vars from file

                // the last loop will enter nothing into vars, and an empty node should not be appended to linked list
                // so if tgtname is empty, do nothing; else, append the target to linked list
                if(strlen(tgtname) != 0)
                {
                    // check if the new target is conflicted with previous targets (distance<0.1)
                    int feedback_c = conflict(*head, latitude, longitude, 0.1);
                    if(feedback_c == 0) // if not conflict, append the target to linked list
                    {
                        append_list(head,tgtname,latitude,longitude);
                    }
                }
                // end of file
                if(feof(cfPtr))
                {
                    break;
                }
            }
        }
    }
    fclose(cfPtr); // close file
}

// check if file is valid; return 1 if valid, 0 otherwise
int isvalid_file(FILE *fPtr)
{
    // reset fPtr to the start of the file
    int feedback_f;
    if((feedback_f = fseek(fPtr, 0, SEEK_SET)) != 0) // exit if reset is unsuccessful
    {
        exit(-2);
    }

    // check if '\n' exists in the file; the file is invalid if '\n' exists
    char bufChar;
    while ((bufChar = fgetc(fPtr)) != EOF)
    {
        if(bufChar == '\n')
        {
            return 0;
        }
    }

    // reset fPtr to the start of the file
    if((feedback_f = fseek(fPtr, 0, SEEK_SET)) != 0) // exit if reset is unsuccessful
    {
        exit(-2);
    }

    for(;;)
    {
        char bufName[BUFFER]={0}, bufLat[BUFFER]={0}, bufLon[BUFFER]={0};

        fscanf(fPtr,"%99s", bufName);
        fscanf(fPtr,"%99s", bufLat);
        fscanf(fPtr,"%99s", bufLon);

        // check if the target name is valid (only contains letters and digits)
        if(!isalnum_str(bufName))
        {
            return 0;
        }
        // check if it is a complete target (i.e. target name buffer is not empty but latitude or longitude buffer is empty)
        if((strlen(bufName) != 0) && (strlen(bufLon) == 0))
        {
            return 0;
        }
        // check if target name, latitude and longitude is valid (contains no more than 15 chars or digits)
        if(strlen(bufName) > SIZE-1 || strlen(bufLat) > SIZE-1 || strlen(bufLon) > SIZE-1)
        {
            return 0;
        }
        // check if str of latitude and longitude is valid (only contains digits and decimal points)
        // check if they are positive (char cannot be '-')
        // "017.5673" can be converted to positive double correctly, therefore is regarded as a valid input
        if(!isdouble_str(bufLat) || !isdouble_str(bufLon))
        {
            return 0;
        }

        // otherwise, convert str to double and check if latitude or longitude is out of range
        // using function "isdouble_str" to check if the str can be converted to positive double, "atof" is secure
        double latitude, longitude;
        if((latitude = atof(bufLat)) > 100 || (longitude=atof(bufLon)) > 100)
        {
            return 0;
        }

        // end of file
        if(feof(fPtr))
        {
            break;
        }
    }
    // reset fPtr to the start of the file
    if((feedback_f = fseek(fPtr, 0, SEEK_SET)) != 0) // exit if reset is unsuccessful
    {
        exit(-2);
    }

    return 1;
}

int isalnum_str(const char *str)
{
    int len = strlen(str);
    for(int i=0; i<len; i++)
    {
        if(!isalnum(str[i])) // return 0 if the string contains a char that is neither a digit nor a letter
        {
            return 0;
        }
    }
    return 1; // otherwise, return 1
}

int isdouble_str(const char *str)
{
    int len = strlen(str);
    int countPoint = 0; // count the number of decimal point
    for(int i=0; i<len; i++)
    {
        if (str[i] == '.')
        {
            countPoint++;
        }
        // if any char is not a digit or a decimal point, or the first/last char is a decimal point,
        // or more than 1 decimal point, return 0
        if( ((!isdigit(str[i])) && str[i] != '.') || (str[i] == '.' && i==0) || (str[i]=='.' && i==len-1) || (countPoint > 1) )
        {
            return 0;
        }
    }
    return 1; // otherwise, return 1
}

int conflict(Target *head, double val1, double val2, double range)
{
    Target *cur = head;
    // compare the new target with previous targets stored in linked list
    while(cur != NULL) 
    {
        // calculate distance between new target and each previous target
        double powLat = pow((cur->latitude) - val1, 2);
        double powLon = pow((cur->longitude) - val2, 2);
        double distance = sqrt(powLat + powLon);
        //precision is 0.0000000000001 (no more than 15 digits including decimal point)
        if(distance - range < -0.0000000000001) // if distance is smaller than range, return 1
        {
            return 1;
        }
        cur = cur->next;
    }
    return 0; // otherwise, return 0
}

void append_list(Target **head, char *str, double val1, double val2)
{
    Target *newnode = malloc(sizeof(Target)); // allocate memory for new node
    if(newnode == NULL) // return 0 if malloc failing
    {
        printf("Unable to allocate memory.\n");
	    exit(-1); // exit(-1) if unable to allocate memory
    }

    strcpy(newnode->targetName, str); // copy str to newnode->targetName
    newnode->latitude = val1;
    newnode->longitude = val2;

    if(*head == NULL) // if linked list is empty
    {
        newnode->next = NULL;
        *head = newnode;
    }
    else
    {
        Target *cur = *head;
        while(cur->next != NULL)
        {
            cur = cur->next;
        }
        newnode->next = NULL;
        cur->next = newnode;
    }
}

void print_list(Target *head) // print linked list in a specific format; if the linked list is empty, do nothing
{
    Target *cur = head;
    if(cur != NULL) // print until NULL
    {
        printf("%s %lf %lf\n", cur->targetName, cur->latitude, cur->longitude);
        while(cur->next != NULL)
        {
            cur = cur->next;
            printf("%s %lf %lf\n", cur->targetName, cur->latitude, cur->longitude);
        } 
    }
}

void map_2d(Target *head)
{
    if(head == NULL) // if linked list is empty, do nothing and return to main menu
    {
        return;
    }

    char map[ROW][COLUMN]; // 40*80 (height, width)
    memset(map, 0, ROW*COLUMN*sizeof(char)); // initialize 2d str

    // x-coordinate and y-coordinate
    for(int r=2; r <= ROW-3; r++)
    {
        map[r][3] = '|';
    }
    for(int c=4; c <= COLUMN-1; c++)
    {
        map[37][c]='_';
    }

    // add some elements to the coordinate system
    map[38][2] = '0'; // original point
    char *quarter1 = "25";
    map_str(map, quarter1, 28, 0);
    map_str(map,quarter1, 38, 21);
    char *mid = "50";
    map_str(map, mid, 19, 0);
    map_str(map, mid, 38, 40);
    char *quarter2 = "75";
    map_str(map, quarter2, 10, 0);
    map_str(map, quarter2, 38, 59);
    char *range = "100";
    map_str(map, range, 2, 0);
    map_str(map, range, 38, 77);

    char *title = "2D map of planet E";
    map_str(map, title, 0, 30);
    char *lat = "latitude";
    map_str(map, lat, 1, 0);
    char *lon = "longitude";
    map_str(map, lon, 39, 71);

    // add all targets to the map
    map_target(map, head);

    // display the 2d map
    int i, j;
    for(i=0; i<ROW; i++)  
    {  
        for(j=0; j<COLUMN; j++)  
        {  
            // if the byte is 0, print a single space; else, print the char
            if(map[i][j] == 0)
            {
                printf(" ");
            }
            else
            {
                printf("%c", map[i][j]);  
            }
        }
        printf("\n");    
    }
}

// add a str to the given place of the map
char *map_str(char map[ROW][COLUMN], const char *str, int r, int c_start) 
{
    int len = strlen(str);
    // check if spaces between start place and rightmost side of the map is not enough
    // check if arguments r, c_start is valid (within the 2D map)
    // for security reason
    if((c_start+len) > COLUMN || c_start < 0 || r >= ROW || r < 0)
    {
        return (char*)map;
    }
    for(int i=0; i<len; i++)
    {
        if(map[r][c_start] == 0) // the string should not cover any other non-zero byte
        {
            map[r][c_start] = str[i];
            c_start++;
        }
    }
    return (char*)map;
}

char *map_target(char map[ROW][COLUMN], Target *head)
{
    Target *cur = head;
    // add each target that is stored in linked list to the map
    while(cur != NULL)
    {
        //adapt to the unit of map
        double row_d = 37 - 35 * cur->latitude * 0.01;
        double column_d = 3 + 76 * cur->longitude * 0.01;
        //round off
        int row_i = (int) row_d;
        int column_i = (int) column_d;

        // if two or more targets are covered after rounding off
        // use number to describe the number of targets that are located at the same byte ('*' if over 9 targets at same byte)
        if((map[row_i][column_i] <= '9' && map[row_i][column_i] > '0') || map[row_i][column_i] == '*')
        {
            if(map[row_i][column_i] == '9' || map[row_i][column_i] == '*')
            {
                map[row_i][column_i] = '*';
                char *cover = "* over 9 targets!";
                map_str(map, cover, 39, 0);
            }
            else
            {
                map[row_i][column_i]++;
            }
        }
        else
        {
            map[row_i][column_i] = '1'; // use '1' to represent 1 target
        }

        // add calibration lines for each target
        for(int c=4; c <= column_i-1; c++)
        {
            if(map[row_i][c] == 0)
            {
                map[row_i][c] = '.';
            }
        }
        for(int r = row_i+1; r<=36; r++)
        {
            if(map[r][column_i] == 0)
            {
                map[r][column_i] = '.';
            }
        }
        cur = cur->next;
    }
    return (char*) map;
}

void search_target(Target *head)
{
    Target *cur = head;

    char bufName[BUFFER]; // store user input as a string
    printf("Enter the name: "); 
    setbuf(stdin, NULL); //clear stdin
    fgets(bufName, BUFFER-1, stdin);
    // If the user presses ENTER without entering any other chars, then this option will do nothing else and return to main menu.
    if(bufName[0] == '\n')
    {
        return;
    }
    // find '\n' and replace it using '\0', as '\n' always exists in string attained by fgets
    char *findNewline = strchr(bufName, '\n');
    if(findNewline)
    {
        *findNewline = '\0';
    }

    int existTGT=0; // check if any target exists
    while(cur != NULL)
    {
        // compare user input with target name of each target
        int feedback_strcmp = strcmp(bufName, cur->targetName);
        if(feedback_strcmp == 0) // if target exists, print the target
        {
            printf("%s %lf %lf\n", cur->targetName, cur->latitude, cur->longitude);
            existTGT = 1;
        }
        cur = cur->next;
    }
    if(existTGT == 0) // if target dose not exist, print a msg
    {
        printf("Entry does not exist.\n");
    }
}

void plan_airstrike(Target *head)
{
    double latitude, longitude, ratio;
    char bufLat[BUFFER], bufLon[BUFFER], bufRatio[BUFFER]; // store user input as strings

    printf("Enter targeted latitude: ");
    setbuf(stdin, NULL); // clear stdin
    fgets(bufLat, BUFFER-1, stdin);
    // find '\n' and replace it using '\0', '\n' always exists in string attained by fgets
    char *findNewline1 = strchr(bufLat, '\n');
    if(findNewline1)
    {
        *findNewline1 = '\0';
    }
    // check if the user presses ENTER without entering any other chars 
    // or str cannot be converted to a positive double
    // or the latitude is out of range
    if(bufLat[0] == '\0' || !isdouble_str(bufLat) || (latitude=atof(bufLat)) > 100)
    {
        return;
    }

    // ibid
    printf("Enter targeted longitude: ");
    setbuf(stdin, NULL); 
    fgets(bufLon, BUFFER-1, stdin);

    char *findNewline2 = strchr(bufLon, '\n');
    if(findNewline2)
    {
        *findNewline2='\0';
    }
    if(bufLon[0] == '\0' || !isdouble_str(bufLon) || (longitude=atof(bufLon)) > 100)
    {
        return;
    }

    // ibid
    printf("Enter ratio of damage zone: ");
    setbuf(stdin, NULL);
    fgets(bufRatio, BUFFER-1, stdin);

    char *findNewline3 = strchr(bufRatio, '\n');
    if(findNewline3)
    {
        *findNewline3='\0';
    }
    // rario = 0 is invalid
    if(bufRatio[0] == '\0' || !isdouble_str(bufRatio) || (ratio = atof(bufRatio)) <= 0)
    {
        return;
    }

    Target *cur = head;
    while(cur != NULL)
    {
        // calculate the distance between the targeted collision point and each target
        double powLat = pow(cur->latitude - latitude, 2);
        double powLon = pow(cur->longitude - longitude, 2);
        double distance = sqrt(powLat + powLon);
        // boundary inclusive: if the target lies on the boundary of damage zone, it will also be destroyed.
        if(distance - ratio <= 0) // print the target within damage zone
        {
            printf("%s %lf %lf\n", cur->targetName, cur->latitude, cur->longitude);
        }
        cur = cur->next;
    }
}

void execute_airstrike(Target **head)
{
    double latitude, longitude, ratio;
    char bufLat[BUFFER]={0}, bufLon[BUFFER]={0}, bufRatio[BUFFER]={0}; // store user input as strings

    printf("Enter targeted latitude: ");
    setbuf(stdin, NULL); // clear stdin
    fgets(bufLat, BUFFER-1, stdin);
    // find '\n' and replace it using '\0', '\n' always exists in string attained by fgets
    char *findNewline1 = strchr(bufLat, '\n');
    if(findNewline1)
    {
        *findNewline1 = '\0';
    }
    // check if the user presses ENTER without entering any other chars 
    // or str cannot be converted to a positive double
    // or the latitude is out of range
    if(bufLat[0] == '\0' || !isdouble_str(bufLat) || (latitude=atof(bufLat)) > 100)
    {
        return;
    }

    // ibid
    printf("Enter targeted longitude: ");
    setbuf(stdin, NULL); 
    fgets(bufLon, BUFFER-1, stdin);

    char *findNewline2 = strchr(bufLon, '\n');
    if(findNewline2)
    {
        *findNewline2='\0';
    }
    if(bufLon[0] == '\0' || !isdouble_str(bufLon) || (longitude=atof(bufLon)) > 100)
    {
        return;
    }

    // ibid
    printf("Enter ratio of damage zone: ");
    setbuf(stdin, NULL);
    fgets(bufRatio, BUFFER-1, stdin);

    char *findNewline3 = strchr(bufRatio, '\n');
    if(findNewline3)
    {
        *findNewline3='\0';
    }
    // rario = 0 is invalid
    if(bufRatio[0] == '\0' || !isdouble_str(bufRatio) || (ratio = atof(bufRatio)) <= 0)
    {
        return;
    }

    Target *cur = *head;
    Target *prev = NULL;
    int countTGT = 0; // initialize the sum of destroyed targets to 0
    Target *plan = NULL; // create a ptr to an empty linked list to print destroyed targets
    while(cur != NULL)
    {
        // calculate the distance between each target and the targeted collision point
        double powLat = pow(cur->latitude - latitude, 2);
        double powLon = pow(cur->longitude - longitude, 2);
        double distance = sqrt(powLat + powLon); 
        // boundary inclusive: if the target lies on the boundary of damage zone, it will also be destroyed
        if(distance - ratio <= 0)
        {
            // append targets which will be destroyed to linked list pointed by plan and check if append seccessfully
            append_list(&plan,cur->targetName,cur->latitude,cur->longitude);

            countTGT++; // count the number of destroyed targets

            // delete the node containing targets that should be destroyed from the linked list
            if (prev == NULL) // if the first node should be deleted
            {
                Target* temp1=cur->next;
                free(cur);
                *head = temp1;
                cur = temp1;
            }
            else if (prev != NULL && cur->next == NULL) // if the last node should be deleted
            {
                free(cur);
                prev->next = NULL;
                break;
            }
            else
            {
                Target* temp2 = cur->next;
                free(cur);
                cur = temp2;
                prev->next = cur;
            }
        }
        else // if the node should not be deleted, move cur and prev to next nodes
        {
            prev = cur;
            cur = cur->next;
        }
    }

    if(countTGT == 0)
    {
        printf("No target aimed. Mission cancelled.\n");
    }
    else // print the number of destroyed targets and print all targets stored in linked list pointed by plan
    {
        printf("%d target destroyed.\n", countTGT);
        print_list(plan);
    }
    destroy_list(&plan); // free allocated memory
}

void destroy_list(Target **head)
{
    Target *cur = *head;
    while(cur != NULL) // free all nodes in the linked list
    {
        Target *next = cur->next;
        free(cur);
        cur = next;
    }
    *head = NULL;
}