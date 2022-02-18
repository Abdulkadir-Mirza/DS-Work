//Abdulkadir Mirza(150245) --- Circular Queue-Enqueue and Dequeue
#include<stdio.h>
#include<stdlib.h>


//Enqueue in circular queue
char enqueue(char Q[],int *f,int *r,int n,char e){

if(*r==n)
	{
	*r=1;
	}
else
	{
	*r=*r+1;
	}
if(*f==*r)
	{
	printf("\nQueue Overflow");
	if(*r==1)
		{
		*r=n;
		}
	else
		{
		*r=*r-1;
		}
	return 0;
	}
Q[*r]=e;
if(*f==0)
*f=1;

return 1;


}

//Dequeue in Circular Queue
char dequeue(char Q[],int *f,int *r,int n){
char c;
if(*f==0)
	{
	printf("\nQueue Underflow");
	return 0;
	}
c=Q[*f];
if(*f==*r)
	{
	*f=0;
	*r=0;
	return c;
	}
if(*f==n)
	{
	*f=1;
	}	
else
	*f=*f+1;

return c;
}


//Main Method
void main(){
int n;
printf("Circular Queue:\n");
printf("Enter the size of queue:");
scanf("%d",&n);
char Q[n];
int front=0,rear=0,ch,x=1;

char en,p,q;
while(x){
printf("\nEnter your choice:\n1.Enqueue\n2.Dequeue\n3.Quit\n");
scanf("%d",&ch);
switch(ch){
	case 1:
		
		printf("\nEnter the value you want to enter:");
		scanf("\n%c",&en);
		p=enqueue(Q,&front,&rear,n,en);
		if(p=='1')
		printf("\nElement inserted in Queue");
		break;

	case 2: 
		q =dequeue(Q,&front,&rear,n);
		if(q!=0)
		printf("\n%c element removed from queue",q);
		break;

	case 3: printf("\nThank you, Quitting you out");
		x=0;
		break;	

	default:
		break;

	}
}	


}
