#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*Head=NULL;

void Create(int A[],int n)
{
    int i;
    struct Node *t,*last;
    Head=(struct Node *)malloc(sizeof(struct Node));
    Head->data=A[0];
    Head->next=Head;
    last = Head;
    for(i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}

void Display(struct Node *h)
{
    printf("\n");
    do
    {
        printf("%d ",h->data);
        h=h->next;
    }while (h!=Head);
    printf("\n");
}

void RDisplay(struct Node *h)
{
    static int flag=0;
    if(h!=Head || flag==0)
    {
        flag=1;
        printf("%d ",h->data);
        RDisplay(h->next);
    } 
    flag=0; 
}

int Length(struct Node *p)
{
    int count=0;
    do
    {
        count++;
        p=p->next;
    }while(p!=Head);
    return count;
}

void Insert(struct Node *p,int index,int x)
{
    if(index<0 || index>Length(Head))
    {
        return;
    }
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    if(index==0)
    {
        if(Head==NULL)
        {
            Head=t;
            Head->next=Head;
        }
        else
        {
            while (p->next!=Head)
            {
                p=p->next;
            }
            p->next=t;
            t->next=Head;
            Head=t;
        }
    
    }
    else
    {
        for(int i=0;i<index-1;i++)
        {
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
    
}

int Delete(struct Node *p,int index)
{
    int x=-1;
    struct Node *q;
    if(index<0 || index>Length(Head))
    {
        return -1;
    }
    if(index==1)
    {
        while (p->next!=Head)
        {
            p=p->next;
        }
        x=Head->data;
        if(p==Head)
        {
            free(Head);
            Head=NULL;
        }
        else
        {
            p->next=Head->next;
            free(Head);
            Head=p->next;
        } 
    }
    else
    {
        for(int i=0;i<index-2;i++)
        {
            p=p->next;
        }
        q=p->next;
        p->next=q->next;
        x=q->data;
        free(q);
    }
    return x;
}

int main()
{
    int A[]={3,5,7,10,15};
    Create(A,5);
    printf("\nLength : %d\n",Length(Head));
    Insert(Head,3,9);
    RDisplay(Head);
    printf("\nDeleting element at index 4: %d\n",Delete(Head,4));
    Display(Head);
    return 0;
}