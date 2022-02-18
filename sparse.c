#include<stdio.h>


void main(){

int m,n,i=0,j=0,count=0;
printf("Enter No. of rows and columns in the Matrix:");
scanf("%d %d",&m,&n);
int A[m][n];
for(i=1;i<=m;i++){
	for(j=1;j<=n;j++){
	printf("Enter %d*%d element:",i,j);
	scanf("%d",&A[i][j]);
	}
	}
for(i=1;i<=m;i++){
	for(j=1;j<=n;j++){
	printf("%d\t",A[i][j]);
	}
	printf("\n");
	}
for(i=1;i<=m;i++){
	for(j=1;j<=n;j++){
	if(A[i][j]!=0)
	count++;
	}
	}
printf("%d\n",count);
int p=3,q=count,x=1,y=1;
int B[p][q];
for(i=1;i<=m;i++){
	for(j=1;j<=n;j++){
		if(A[i][j]!=0)
		{	if(x>count)
			break;
			B[1][x]=i;
			B[2][x]=j;
			B[3][x]=A[i][j];
			x++;
		}
	}
	}
for(i=1;i<=p;i++){
	if(i==1)
	printf("Row:    ");
	if(i==2)
	printf("Column: ");
	if(i==3)
	printf("Value:  ");
	for(j=1;j<=q;j++){
	printf("%d  ",B[i][j]);
	}
	printf("\n");
	}







}
