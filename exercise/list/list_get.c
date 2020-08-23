#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct int_list {
   int value;
   struct int_list *next;
};
typedef struct int_list IntList;

int list_length(IntList *start)
{
    int len = 0;
    IntList *cur = start;
    while(cur != NULL)
    {
        len++;
        cur = cur->next;
    }
    return len;
}

void print_list(IntList *start)
{
    IntList *p=start;
    if(p!=NULL)
    {
        while(p->next!=NULL)
        {
            printf("%d ", p->value);
            p=p->next;
        }
        printf("%d", p->value);
    }
    printf("\n");
}

int list_prepend(IntList **start, int val)
{
   IntList *n = malloc(sizeof(IntList));
   if(n == NULL)
   {
      // error, cannot allocate memory for new list node.
      return 0;
   }
   n->value = val;
   n->next = NULL;

   if(*start == NULL)
   {
      // empty list
      *start = n;
   }
   else
   {
      // existing list
      n->next = *start;
      *start = n;
   }
   return 1;
}

int list_get(IntList *start, int n)
{
    IntList *p=start;
    for(int i=1;i<n;i++)
    {
        p=p->next;
    }
    return p->value;
}

int list_contain(IntList *start, int n)
{
    IntList *p=start;
    int flag=0;
    while(p!=NULL)
    {
        if(p->value==n)
        {
            flag=1;
        }
        p=p->next;
    }
    return flag;
}

int main(int argc, char *argv[])
{  
	int value;
	IntList *p=NULL;
	for(;;)
	{
		printf("Value: ");
		scanf("%d", &value);
		if(value == 0)
            break;
        list_prepend(&p, value);
	}
    print_list(p);

    /*int n;
    int len=list_length(p);
    while(1)
    {
        printf("n: ");
        scanf("%d",&n);
        if(n==0)
        {
            break;
        }
        if(n>len || n<0)
        {
            printf("Invalid input!\n");
        }
        else
        {
            printf("The number is %d\n",list_get(p,n));
        }
    }*/

    int key;
    while(1)
    {
        printf("contain: ");
        scanf("%d",&key);
        if (key==0)
        {
            return 0;
        }
        int contain=list_contain(p,key);
        //printf("%d",list_contain(p,key));
        if(contain==0)
        {
            printf("Not contain.\n");
        }
        else
        {
            printf("Contain.\n");
        }
    }
    return 0;
}