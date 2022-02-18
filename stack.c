#include<stdio.h>


int n=4,top=0;
int s[4];

void main(){
int x;
while(1){
printf("Enter element to be pushed:\n");
scanf("%d",&x);
int i=push(x);
	if(i==0)
	{
		for(int j=n; j>0;j--)
		{
		printf("%d ",s[j]);
		}	
	break;
	}
	else
	printf("\nElement pushed..");
	}
}


int push(int x){
if(top<n){
	top=top+1;
	s[top]=x;
	return 1;
	}
else	{
	printf("\nStack Overflow");
	return 0;
	}
}
