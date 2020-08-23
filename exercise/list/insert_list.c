#include <stdio.h>
#include <stdlib.h>

struct list
{
    int value;
    struct list *next;
};
typedef struct list List;

int delete(List **start)
{
    if(*start==NULL)
    {
        printf("The linked list is empty!\n");
        return 0;
    }

    int value;
    printf("Value be deleted: ");
    scanf("%d",&value);

    List *p=*start;
    List *delete=NULL;

    /*int len = 0;
    List *cur = *start;
    while(cur != NULL)
    {
        len++;
        cur = cur->next;
    }*/
    while(p->value==value && p!=NULL)
    {
        delete=p;
        p=p->next;
        *start=p;
        free(delete);
        //len=len-1;
    }

    p=p->next;
    List *pre=*start;
    int flag=0;

    while(p!=NULL)
    {
        if(p->value==value){
            delete=p;
            p=p->next;
            pre->next=p;
            free(delete);
            //len=len-1;
            flag=1;
        }
        else
        {
            pre=p;
            p=p->next;
        }
        
    }
    if(flag==0)
    {
        printf("No element is deleted!\n");
        return 0;
    }
    else
    {
        return 1;
    }
    
}

int insert(List **start)
{
    int value;
    printf("Value be inserted: ");
    scanf("%d",&value);

    int n;
    printf("Position: ");
    scanf("%d",&n);

    List *new=malloc((sizeof(List)));
    if(new==NULL || n<=0)
    {
        return 0;
    }

    new->value=value;
    new->next=NULL;

    if(n==1)
    {
        if (*start==NULL)
        {
            new->next=NULL;
        }
        else
        {
            new->next=*start;
            *start=new;
            return 1;
        }
    }
    else
    {
        List* pre=*start;
        List* p=pre->next;
        int c=0;
        while(p!=NULL && c<n-2)
        {
            c++;
            pre=p;
            p=p->next;
        }
        pre->next=new;
        new->next=p;
        return 1;
    }
    
}

int list_length(List *start)
{
   int len = 0;
   List *cur = start;
   while(cur != NULL)
   {
      len++;
      cur = cur->next;
   }
   return len;
}

List* create(void)
{
    printf("Please enter the size: ");
    int size;
    scanf("%d",&size);
    if(size==0)
    {
        return NULL;
    }

    List* p=NULL;
    List* start=NULL;
    for(int i=0;i<size;i++)
    {
        List* new=malloc(sizeof(List));
        int value;
        printf("Value: ");
        scanf("%d",&value);
        new->value=value;
        if(start==NULL)
        {
            new->next=NULL;
            p=new;
            start=new;
        }
        else
        {
            p->next= new;
            new->next=NULL;
            p=new;
        }
    }
    return start;
}

void print_list(List *start)
{
    List *p=start;
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

int main(void)
{
    List *p=create();
    print_list(p);
    int a=delete(&p);
    /*int a=insert(&p);
    if(a==1)
    {
        print_list(p);
        printf("The length is %d\n",list_length(p));
    }*/
    if(a==1)
    {
        print_list(p);
        printf("Length is %d\n",list_length(p));
    }
    return 0;
}