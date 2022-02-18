#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "stackchar.h"

int check(char []);

int main() {
char a[10];
printf("Enter a string\n");
scanf("%s",a);
if(check(a)) {
printf("It's valid\n");
}
else{printf("Not valid\n");}
return 0;
}

int check(char a[]){
int i=0,b=0,length=0,top=0;
int count=0;
char *stack;
length = strlen(a);
stack = (char*)malloc(length * sizeof(char));
b = length*sizeof(char);
for(i=0;i<length;i++)
{

	while(a[i]!='b'){
	push(stack,&top,a[i],b);
	count++;
	}
	while(a[i] != '\0'){
	char c = pop(stack,&top);
	count--;
	}
}
if(count!=0)
return 0;

return 1;
}
