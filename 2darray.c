#include<stdio.h>

void main(){
char major;
int n,m,base,i,j;

printf("Row-Major or Column-Major(r/c):");
scanf("%c",&major);
printf("\nEnter base address:");
scanf("%d",&base);

printf("\nEnter total no. of rows:");
scanf("%d",&m);
printf("\nEnter total no. of columns:");
scanf("%d",&n);

printf("\nEnter no. of row(i):");
scanf("%d",&i);
printf("\nEnter no. of column(j):");
scanf("%d",&j);

if(major=='r'){
	printf("Address of (%d,%d)th element is: %d",i,j,base+(4*(((i-1)*m)+(j-1))));

	}
if(major=='c'){
	printf("Address of (%d,%d)th element is: %d",i,j,base+(4*(((j-1)*n)+(i-1))));

	}
}
