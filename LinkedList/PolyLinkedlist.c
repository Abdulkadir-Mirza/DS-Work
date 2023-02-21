#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node
{
	int Coeff;
	int Exp;
	struct Node* Next;
}*poly=NULL;

void Create()
{
	int n,i;
	struct Node *t,*last;
	printf("Enter the Number of Terms: ");
	scanf("%d",&n);
	printf("Enter Coefficient and Exponent for each term\n");
	for(int i=0;i<n;i++)
	{
		t=(struct Node*)malloc(sizeof(struct Node));
		scanf("%d%d",&t->Coeff,&t->Exp);
		t->Next=NULL;
		if(poly==NULL)
		{
			poly=last=t;
		}
		else
		{
			last->Next=t;
			last=t;
		}
	}
}

void Display(struct Node *p)
{
	while(p)
	{
		printf("%dx%d",p->Coeff,p->Exp);
		if(p->Next!=NULL)
			printf(" + ");
		else
			printf("\n");
		p=p->Next;
	}

}

long EVal (struct Node *p,int x)
{
	long val;
	while(p)
	{
		val+=p->Coeff*pow(x,p->Exp);
		p=p->Next;
	}
	return val;
}

int main()
{

Create();
Display(poly);
printf("\nEvaluation of Polynomial of Value of x=2 is: %ld",EVal(poly,2));
return 0;
}
