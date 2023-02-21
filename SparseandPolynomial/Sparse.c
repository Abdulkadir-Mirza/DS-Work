#include <stdio.h>
#include <stdlib.h>

struct Element
{
    int i;
    int j;
    int x;
};

struct Sparse
{
    int m;
    int n;
    int num;
    struct Element *e;
};

void CreateSparseMatrix(struct Sparse *s)
{
    int i;
    printf("Enter Dimensions(i,j): ");
    scanf("%d%d",&s->m,&s->n);   
    printf("\nEnter Number of Non-zero elements: ");
    scanf("%d",&s->num);
    s->e=(struct Element *)malloc(s->num*(sizeof(struct Element)));
    printf("\nEnter all Non-zero elements:");
    for(i=0;i<s->num;i++)
    {
        scanf("%d%d%d",&s->e[i].i,&s->e[i].j,&s->e[i].x);
    }
}

void Display(struct Sparse s)
{
    int i,j,k=0;
    for(i=0;i<s.m;i++)
    {
        for(j=0;j<s.n;j++)
        {
            if(i==s.e[k].i&&j==s.e[k].j)
            {
                printf("%d ",s.e[k].x);
                k++;
            }
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{
    struct Sparse s;
    CreateSparseMatrix(&s);
    Display(s);
    return 0;
}