#include<stdio.h>

void main(){
int base, i;
printf("Enter the base address:");
scanf("%d",&base);
printf("\nEnter the index of element:");
scanf("%d",&i);
printf("\n The Address of ith element is:%d",base+(4*(i-1)));
}

