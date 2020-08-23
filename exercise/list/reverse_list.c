/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode IntList;

//[11,1,2,3,4]
IntList * initLink(void){
    IntList * p=malloc(sizeof(IntList));//创建一个头结点
    //initialization
    p->val=11;
    p->next=NULL;
    IntList * temp=p;//声明一个指针指向头结点，用于遍历链表
    //生成链表
    for (int i=1; i<5; i++) {
        IntList *a=(IntList*)malloc(sizeof(IntList));
        a->val=i;
        a->next=NULL;
        temp->next=a;
        temp=temp->next;
    }
    return p;
}

void print_list(IntList *start)
{
    IntList *p=start;
    if(p!=NULL)
    {
        while(p->next!=NULL)
        {
            printf("%d ", p->val);
            p=p->next;
        }
        printf("%d", p->val);
    }
    printf("\n");
}

IntList * list_append(int size)
{
    if (size==0)
    {
        return NULL;
    }
    IntList *start=NULL;
    IntList *p=NULL;
    for(int i=0;i<size;i++)
    {
        IntList *new=malloc(sizeof(IntList));
        int value;
        printf("Please enter a value: ");
        scanf("%d",&value);

        new->val=value;
        new->next=NULL;
        if(start==NULL)
        {
            start=new;
            p=new;
        }
        else
        {
            p->next=new;
            p=new;
        }
    }
    return start;
}

IntList * list_reverse(IntList **start)
{
    IntList *p1=*start;
    if(p1==NULL || p1->next==NULL)
    {
        return p1;
    }
    IntList *p2=p1->next;
    p1->next=NULL;
    while(p2!=NULL)
    {
        IntList *p3=p2->next;
        p2->next=p1;
        p1=p2;
        p2=p3;
    }
    return p1;
}

IntList *list_prepend(int size)
{
    IntList *p=NULL;
    for(int i=0; i<size; i++)
    {
        IntList *new=malloc(sizeof(IntList));
        printf("Value: ");
        int value;
        scanf("%d", &value);
        new->val=value;
        if(p==NULL)
        {
            new->next=NULL;
            p=new;
        }
        else
        {
            new->next=p;
            p=new;
        }
        
    }
    return p;
}

int main(void)
{
    printf("The length of linked list you want to create: ");
    int len;
    scanf("%d", &len);
    //IntList *p1=list_append(len);
    IntList *p2=list_prepend(len);

    //print_list(p1);
    print_list(p2);

    //IntList *rp1=list_reverse(&p1);
    IntList *rp2=list_reverse(&p2);

    print_list(rp2);
    return 0;
}