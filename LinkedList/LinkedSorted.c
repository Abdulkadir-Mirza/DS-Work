#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node *next;
}*first=NULL;

void Create(int A[],int n)
{
    int i;
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
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

int Count(struct Node *p)
{
    int count=0;
    while (p!=NULL)
    {
        count++;
        p=p->next;
    }  
    return count;
}

void SortedInsert(struct Node *p,int x)
{
    struct Node *t,*q;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    if(p==NULL)
    {
        first=t;
        return;
    }
    q=NULL;
    while(p && p->data<x)
    {

        q=p;
        p=p->next;
    }
    
    if(p==first)
    {
        t->next=first;
        first=t;
    }
    else
    {
        t->next=q->next;
        q->next=t;
    }
    
}

int Delete(struct Node *p,int pos)
{
    int x=-1;
    if(pos<1 || pos >Count(p))
    {
        return -1;
    }
    if(pos==1)
    {
        first=first->next;
        x=p->data;
        free(p);
    }
    else
    {
        struct Node *q=NULL;
        for(int i=0;i<pos-1 && p;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        free(p);
    }
    return x;

}

void RemoveDuplicates(struct Node *p)
{
    struct Node *q=p->next;
    while (q)
    {
        if(p->data!=q->data)
        {
            q=q->next;
            p=p->next;
        }
        else
        {
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }
    
}

int main()
{
    int A[]={3,5,5,7,7,10,10,10,15};
    Create(A,9);
    SortedInsert(first,4);
    Display(first);
    printf("\nDeleted term at postion 3: %d\n",Delete(first,3));
    Display(first);
    RemoveDuplicates(first);
    Display(first);
    return 0;
}