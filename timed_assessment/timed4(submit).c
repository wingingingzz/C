#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int is_int(char *arr);

int main()
{
	int i;
	char array[15];
	
	printf("Enter an integer: ");
	for( ; ; )
	{
		scanf("%s", array);
		if(is_int(array))
		{
			i = strtol(array, NULL, 0);
			printf("Value entered %d\n", i);
			break;
		}
		else
			printf("Invalid. Enter again: ");
	}
}

int is_int(char *arr)
{
    int len=strlen(arr);
    int flag;
    char c=arr[0];
    char e=arr[1];
    if(c=='0' && e=='\0')
    {
        return 1;
    }

    if(c=='-'||c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9')
    {
        flag=0;
    }
    else
    {
        return 0;
    }

    if(c=='-' && e=='0')
    {
        return 0;
    }
    

    for(int i=1;i<len;i++)
    {
        char d=arr[i];
        if(d=='-'||d=='0'||d=='1'||d=='2'||d=='3'||d=='4'||d=='5'||d=='6'||d=='7'||d=='8'||d=='9')
        {
            flag=0;       
        }
        else
        {
            flag=1;
            break;    
        }
    }
    if(flag==1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}