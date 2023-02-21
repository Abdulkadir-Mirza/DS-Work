#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

void Create(int A[],int n)
{
    int i;
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->prev=NULL;
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
}

void Display(struct Node *p)
{
    printf("\n");
    while (p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }  
    printf("\n");
}

int Length(struct Node *p)
{
    int count=0;
    while(p)
    {
        count++;
        p=p->next;
    }
    return count;
}

void Insert(struct Node *p,int index,int x)
{
    if(index<0 || index>Length(first))
    {
        return;
    }
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    if(index==0)
    {
        t->next=first;
        t->prev=NULL;
        if(first)
            first->prev=t;
        first=t;
    }
    else
    {
        for(int i=0;i<index-1;i++)
        {
            p=p->next;
        }
        t->next=p->next;
        t->prev=p;
        if(p->next)
            p->next->prev=t;
        p->next=t;
    }
    
}

int Delete(struct Node *p,int index)
{
    int x=-1,i;
    struct Node *q;
    if(index<0 || index>Length(first))
    {
        return -1;
    }
    if(index==1)
    {
        first=first->next;
        if(first)first->prev=NULL;
        x=p->data;
        free(p);
    }
    else
    {
        for(int i=0;i<index-1;i++)
            p=p->next;
        p->prev->next=p->next;
        if(p->next)
            p->next->prev=p->prev;
        x=p->data;
        free(p);
    }
    return x;
}

void Reverse(struct Node *p)
{
    struct Node *temp;
    while(p!=NULL)
    {
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if(p!=NULL && p->next==NULL)
            first=p;
    }
}


int main()
{
    int A[]={3,5,7,10,15};
    Create(A,5);
    printf("Length: %d",Length(first));
    Insert(first,2,6);
    Display(first);
    printf("Deleting element from Index 3: %d",Delete(first,3));
    Reverse(first);
    Display(first);
    return 0;
}