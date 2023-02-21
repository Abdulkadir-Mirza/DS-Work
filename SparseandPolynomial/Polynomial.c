#include <stdio.h>
#include <stdlib.h>

struct Terms
{
    int coeff;
    int exp;
};

struct Poly
{
    int n;
    struct Terms *terms;
};

void Create(struct Poly *p)
{
    int i;
    printf("Enter the number of terms:");
    scanf("%d",&p->n);
    p->terms=(struct Terms *)malloc(p->n*sizeof(struct Terms));
    printf("\nEnter Terms:\n");
    for(i=0;i<p->n;i++)
    {
        scanf("%d%d",&p->terms[i].coeff,&p->terms[i].exp);
    }
}

void Display(struct Poly p)
{
    int i;
    for(i=0;i<p.n;i++)
    {
        printf("%d*x^%d",p.terms[i].coeff,p.terms[i].exp);
        if(i+1!=p.n)
            printf(" + ");
        else
            printf("\n");
            
    }
}

struct Poly *add(struct Poly p1,struct Poly p2)
{ 
    int i,j,k;
    i=j=k=0;  
    struct Poly *sum;
    sum=(struct Poly *)malloc(sizeof(struct Poly));
    sum->terms=(struct Terms *)malloc((p1.n+p2.n)*sizeof(struct Terms));
    while (i<p1.n && j<p2.n)
    {
        if(p1.terms[i].exp>p2.terms[j].exp)
        {
            sum->terms[k++]=p1.terms[i++];
        }
        else if(p1.terms[i].exp<p2.terms[j].exp)
        {
            sum->terms[k++]=p2.terms[j++];
        }
        else
        {
            sum->terms[k].exp=p1.terms[i].exp;
            sum->terms[k++].coeff=p1.terms[i++].coeff+p2.terms[j++].coeff;
        }
    }
    for(;i<p1.n;i++)
        sum->terms[k++]=p1.terms[i++];
    for(;j<p2.n;j++)
        sum->terms[k++]=p2.terms[j++];
    sum->n=k;
    return sum;
    
}

int main()
{
    struct Poly p1;
    Create(&p1);
    Display(p1);
    struct Poly p2;
    Create(&p2);
    Display(p2);
    struct Poly *p3;
    p3=add(p1,p2);
    Display(*p3);
    return 0;
}