#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *S;
};

void Create(struct Stack *st)
{
    printf("Enter the size of Stack: ");
    scanf("%d",&st->size);
    st->top=-1;
    st->S=(int *)malloc(st->size*sizeof(int));
}

void Display(struct Stack st)
{
    for(int i=st.top;i>=0;i--)
    {
        printf("%d ",st.S[i]);
    }
    printf("\n");
}

void Push(struct Stack *st,int x)
{
    if(st->top==st->size-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        st->top++;
        st->S[st->top]=x;
    }
}

int Pop(struct Stack *st)
{
    int x=-1;
    if(st->top==-1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        x=st->S[st->top--];
    }
    return x;
}

int Peek(struct Stack st, int index)
{
    int x=-1;
    if(st.top-index+1<0)
        printf("Invalid Index\n");
    else
        x=st.S[st.top-index+1];
    return x;
}

int isEmpty(struct Stack st)
{
    if(st.top==-1)
        return 1;
    return 0;
}

int isFull(struct Stack st)
{
    if(st.top==st.size-1)
        return 1;
    return 0;
}

int StackTop(struct Stack st)
{
    if(!isEmpty(st))
        return st.S[st.top];
    return -1;
}

int main()
{
    struct Stack st;
    Create(&st);
    Push(&st,10);
    Push(&st,20);
    Push(&st,30);
    Push(&st,40);
    Push(&st,50);
    Display(st);

    printf("Pop returns: %d\n",Pop(&st));
    Display(st);
    
    return 0;
}