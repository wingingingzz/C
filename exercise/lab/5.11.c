#include <stdio.h>
#include <time.h>
#include <stdlib.h>

enum Status {WON,LOST,CONTINUE};
int rolldice(void);

int main(void)
{
    srand(time(NULL));

    int myPoint;
    enum Status gameStatus;
    int sum=rolldice();//first time to roll dice

    switch (sum)
    {
    case 7:
    case 11:
        gameStatus=WON;
        break;

    case 2:
    case 3:
    case 12:
        gameStatus=LOST;
        break;

    default:
        myPoint=sum;
        gameStatus=CONTINUE;
        break;
    }

    while (gameStatus==CONTINUE)
    {
        sum=rolldice();

        if (sum==myPoint)
        {
            gameStatus=WON;
        }
        else if(sum==7)
        {
            gameStatus=LOST;
        }
    }

    if(gameStatus==WON)
    {
        printf("Win!");
    }
    else if(gameStatus==LOST)
    {
        printf("Lost:(");
    }
    
    printf("\n");
    return 0;
}

int rolldice(void)
{
    int die1=1+(rand()%6);
    int die2=1+(rand()%6);

    printf("player rolled %d+%d=%d\n",die1,die2,die1+die2);
    return die1+die2;
}