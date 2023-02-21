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

void RDisplay(struct Node *p)
{
    if (p!=NULL)
    {
        printf("%d ",p->data);
        RDisplay(p->next);
    }  
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

int Sum(struct Node *p)
{
    int Sum=0;
    while (p!=NULL)
    {
        Sum+=p->data;
        p=p->next;
    }  
    return Sum;
}

int Max(struct Node *p)
{
    int max= INT_MIN;
    while (p)
    {
        if(p->data>max)
            max=p->data;
        p=p->next;
    }  
    return max;
}

struct Node* LinearSearch(struct Node *p,int key)
{
    while (p)
    {
        if(p->data==key)
            return p;
        p=p->next;
    }  
    return NULL;
}

void InsertFirst(struct Node *p,int x)
{
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->next=first;
    first=t;
}

void InsertAtPosition(struct Node *p,int pos,int x)
{
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    for(int i=0;i<pos-1;i++)
    {
        p=p->next;
    }
    t->next=p->next;
    p->next=t;
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

int IsSorted(struct Node *p)
{
    int x=INT_MIN;
    while(p)
    {
        if(p->data<x)
        {
            return 0;
        }
        x=p->data;
        p=p->next;
    }
    return 1;
}

void Reverse1(struct Node *p)
{
    struct Node *q=p;
    int *A;
    int i=0;
    A=(int *)malloc(sizeof(int)*Count(first));
    while(q)
    {
        A[i++]=q->data;
        q=q->next;
    }
    q=p;
    i--;

    while (q)
    {
        q->data=A[i--];
        q=q->next;
    }
    
}

void Reverse2(struct Node *p)
{
    struct Node *q=NULL,*r=NULL;
    while(p)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

void Reverse3(struct Node *q,struct Node *p)
{
    if(p)
    {
        Reverse3(p,p->next);
        p->next=q;
    }
    else{
        first=q;
    }
}

int IsLoop(struct Node *f)
{
    struct Node *p,*q;
    p=q=f;
    do
    {
        p=p->next;
        q=q->next;
        q=q?q->next:q;
    }while(p && q && p!=q);
    if(p==q)
        return 1;
    else    
        return 0;
}

int main()
{
    int A[]={3,5,7,10,15};
    Create(A,5);
    RDisplay(first);
    printf("\nNo of nodes in List: %d",Count(first));
    printf("\nSum of nodes in List: %d",Sum(first));
    printf("\nMaximum of nodes in List: %d",Max(first));
    printf("\n5 is found at : %p\n",LinearSearch(first,5));
    InsertFirst(first,2);
    InsertAtPosition(first,4,8);
    RDisplay(first);
    SortedInsert(first,4);
    printf("\n");
    Display(first);
    printf("\nDeleted term at postion 3: %d\n",Delete(first,3));
    Display(first);
    printf("\nIs the List Sorted: %d",IsSorted(first));
    Reverse2(first);
    Display(first);
    Reverse3(NULL,first);
    Display(first);
    printf("\nIs the List in Loop: %d",IsLoop(first));
    return 0;
}