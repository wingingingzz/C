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

int reversebetween(int m, int n, IntList **start)
{
    IntList *p=*start;
    IntList *pre=NULL;
    if(m>=n || p==NULL || p->next==NULL)
    {
        return 0;
    }

    int len=list_length(*start);
    if(m>len || n>len)
    {
        printf("invalid input!\n");
        return 0;
    }

    IntList *temptail=NULL;
    IntList *temphead=NULL;
    IntList *temp=NULL;
    IntList *tempp=NULL;

    if(1==m)
    {
        temptail=p;
    }
    for(int i=1; i<=n; i++)
    {
        temp=p->next;

        if(m==i && m!=1)
        {
            temptail=p;
            pre->next=NULL;
            tempp=pre;
        }

        if(i>m && i<=n)
        {
            if(i==n)
            {
                temphead=p;
            }
            p->next=pre;
        }
        pre=p;
        p=temp;
    }

    if(m==1)
    {
        temptail->next=temp;
        *start=temphead;
        /*printf("head %d\n",temphead->value);
        printf("tail %d\n",temptail->value);
        printf("temp %d\n",temp->value);*/
    }
    else
    {
        temptail->next=temp;
        tempp->next=temphead;
    }
    return 1;
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

    int m;
    printf("m: ");
    scanf("%d",&m);
    int n;
    printf("n: ");
    scanf("%d",&n);
    int a=reversebetween(m,n,&p);
    if(a==0)
    {
        printf("Not reverse.\n");
    }
    
    print_list(p);
}