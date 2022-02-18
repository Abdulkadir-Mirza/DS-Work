#include<stdio.h>
#include<stdlib.h>


struct Node{
char data;
struct Node *l;
struct Node *r;

};


//Preorder Traversal
int preorder(struct Node *t){
if(t==NULL){
printf("\nTree Empty!!");
return 0;
}
else
printf("%c ",t->data);

if(t->l!=NULL)
preorder(t->l);
if(t->r!=NULL)
preorder(t->r);

return 1;
}

//Inorder Traversal
int inorder(struct Node *t){
if(t==NULL){
printf("\nTree Empty!!");
return 0;
}



if(t->l!=NULL)
inorder(t->l);

printf("%c ",t->data);

if(t->r!=NULL)
inorder(t->r);

return 1;
}


//Postorder Traversal
int postorder(struct Node *t){
if(t==NULL){
printf("\nTree Empty!!");
return 0;
}

if(t->l!=NULL)
postorder(t->l);
if(t->r!=NULL)
postorder(t->r);

printf("%c ",t->data);
return 1;
}


int main(){
struct Node *first,*second,*third,*fourth,*fifth,*sixth,*seven;
first = (struct Node*)malloc(sizeof(struct Node));
second = (struct Node*)malloc(sizeof(struct Node));
third = (struct Node*)malloc(sizeof(struct Node));
fourth = (struct Node*)malloc(sizeof(struct Node));
fifth = (struct Node*)malloc(sizeof(struct Node));
sixth = (struct Node*)malloc(sizeof(struct Node));
seven = (struct Node*)malloc(sizeof(struct Node));

first->data='A';
first->l=second;
first->r=third;

second->data='B';
second->l=fourth;
second->r=NULL;

fourth->data='C';
fourth->l=NULL;
fourth->r=NULL;

third->data='D';
third->l=fifth;
third->r=sixth;

fifth->data='E';
fifth->l=NULL;
fifth->r=seven;

seven->data='F';
seven->l=NULL;
seven->r=NULL;

sixth->data='G';
sixth->l=NULL;
sixth->r=NULL;

printf("Preorder Traversal:\n");
preorder(first);
printf("\nInorder Traversal:\n");
inorder(first);
printf("\nPostorder Traversal:\n");
postorder(first);
return 0;
}
