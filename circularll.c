#include<stdio.h>
#include<stdlib.h>


struct Node
{
int data;
struct Node *next;
};


//Add a node to empty list.
struct Node *addToEmpty(struct Node *last, int data)
{

if (last != NULL)
return last;

// Creating a node dynamically.
struct Node *temp = (struct Node*)malloc(sizeof(struct Node));

// Assigning the data.
temp -> data = data;
last = temp;

// Creating the link.
last -> next = last;

return last;
}


//Insert at first
struct Node *addBegin(struct Node *last, int data)
{
if (last == NULL)
return addToEmpty(last, data);

struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

temp -> data = data;
temp -> next = last -> next;
last -> next = temp;

return last;
}


//Insert at End
struct Node *addEnd(struct Node *last, int data)
{
if (last == NULL)
return addToEmpty(last, data);

struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

temp -> data = data;
temp -> next = last -> next;
last -> next = temp;
last = temp;

return last;
}


//Printing list
void traverse(struct Node *last)
{
struct Node *p;

// If list is empty, return.
if (last == NULL)
{
printf( "List is empty." );
return;
}

// Pointing to first Node of the list.
p = last -> next;

// Traversing the list.
do
{
printf("%d " , p -> data );
p = p -> next;

}
while(p != last->next);

}


//Deleting a node
struct Node* deleteNode(struct Node* last, int key)
{
struct Node * curr = last->next, *prev;
prev = last;
if(last == last->next){
return NULL;
}
while(curr!=last){
if(curr->data == key){
prev-> next = curr->next;
free(curr);
return last;
}
prev = curr;
curr = curr->next;
}


if(curr->data == key){
prev-> next = curr->next;
free(curr);
return prev;
}
printf("Not Found \n");
return last;

}



// Driver Program
int main()
{
struct Node *last = NULL;

last = addToEmpty(last, 6);
last = addBegin(last, 4);
last = addBegin(last, 2);
last = addEnd(last, 8);
last = addEnd(last, 12);
traverse(last);
last = deleteNode(last, 6);
traverse(last);

return 0;
}
	
	
	

