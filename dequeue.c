//Abdulkadir Mirza(150245) --- Double Ended Queue
#include<stdio.h>
#include<stdlib.h>


//Enqueue
char enqueue(char Q[],int *f,int *r,int n,char e){
if(*r>=n)
	{
	printf("\nQueue Overflow");
	return 0;
	}
*r=*r+1;
Q[*r]=e;
if(*f==0)
	*f=1;

return 1;
}

//Dequeue
char dequeue(char Q[],int *f,int *r){
if(*f==0)
	{
	printf("\nQueue Underflow");
	return 0;
	}
char c=Q[*f];
if(*f==*r){
	*f=0;
	*r=0;
	}
else
*f=*f+1;
return c;

}


//Enqueue-with-Front
char enqueue_front(char Q[],int *f,int *r,int n,char e){
if(*f==0)
	{
	printf("\nQueue Empty");
	return -1;
	}	
if(*f==1)
	{
	printf("\nOverflow");
	return 0;
	}
*f=*f-1;
Q[*f]=e;
return 1;
}


//Dequeue-with-Rear
char dequeue_rear(char Q[],int *f,int *r){
if(*r==0)
	{
	printf("\nUnderflow");
	return 0;
	}
char c=Q[*r];
if(*r==*f)
	{
	*r=0;
	*f=0;
	}
else
	*r=*r-1;
return c;
}




//MAIN METHOD
void main(){
int n;
printf("Double Ended Queue:\n");
printf("Enter the size of queue:");
scanf("%d",&n);
char Q[n];
int front=0,rear=0,ch,x=1;

char en,p,q,en1,p1,q1;
while(x){
printf("\nEnter your choice:\n1.Enqueue\n2.Dequeue\n3.Enqueue-with FRONT\n4.Dequeue-with-rear\n5.Quit\n");
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
		q =dequeue(Q,&front,&rear);
		if(q!=0)
		printf("\n%c element removed from queue",q);
		break;

	case 3:
		printf("\nEnter the element you want to enter:");
		scanf("\n%c",&en1);
		p1=enqueue_front(Q,&front,&rear,n,en1);
		if(p1=='1')
		printf("\nElement inserted in Queue");
		break;

	case 4: 
		q1 =dequeue_rear(Q,&front,&rear);
		if(q1!=0)
		printf("\n%c element removed from queue",q1);
		break;

	case 5: printf("\nThank you, Quitting you out");
		x=0;
		break;	

	default:
		break;

	}
}	




}
