	#include <stdio.h>
	#include <stdlib.h>

	struct node
	{
	int data; //node will store an integer
	struct node *right_child; // right child
	struct node *left_child; // left child
	};


//Search a tree
	struct node* search(struct node *root, int x)
	{
	if(root==NULL || root->data==x) //if root->data is x then the element is found
	return root;
	else if(x>root->data) // x is greater, so we will search the right subtree
	return search(root->right_child, x);
	else //x is smaller than the data, so we will search the left subtree
	return search(root->left_child,x);
	}

//function to find the minimum value in a node
	struct node* find_minimum(struct node *root)
	{
	if(root == NULL)
	return NULL;
	else if(root->left_child != NULL) // node with minimum value will have no left child
	return find_minimum(root->left_child); // left most element will be minimum
	return root;
	}


//Create a node
	//function to create a node
	struct node* new_node(int x)
	{
	struct node *p;
	p = malloc(sizeof(struct node));
	p->data = x;
	p->left_child = NULL;
	p->right_child = NULL;

	return p;
	}

//Insert an element
	struct node* insert(struct node *root, int x)
	{
		//searching for the place to insert
		if(root==NULL)
		return new_node(x);
		else if(x>root->data) // x is greater. Should be inserted to right
		root->right_child = insert(root->right_child, x);
		else // x is smaller should be inserted to left
		root->left_child = insert(root->left_child,x);
		return root;
	}

// funnction to delete a node
	struct node* delete(struct node *root, int x)
	{
		//searching for the item to be deleted
		if(root==NULL)
		return NULL;
		if (x>root->data)
		root->right_child = delete(root->right_child, x);
		else if(x<root->data)
		root->left_child = delete(root->left_child, x);
		else
		{
		//No Children
		if(root->left_child==NULL && root->right_child==NULL)
		{
		    free(root);
		    return NULL;
		}

		//One Child
		else if(root->left_child==NULL || root->right_child==NULL)
		{
		    struct node *temp;
		    if(root->left_child==NULL)
			temp = root->right_child;
		    else
			temp = root->left_child;
		    free(root);
		    return temp;
		}

		//Two Children
		else
		{
		    struct node *temp = find_minimum(root->right_child);
		    root->data = temp->data;
		    root->right_child = delete(root->right_child, temp->data);
		}
		}
		return root;
	}


//Inorder Traversal
	void inorder(struct node *root)
	{
	if(root!=NULL) // checking if the root is not null
	{
	inorder(root->left_child); // visiting left child
	printf(" %d ", root->data); // printing data at root
	inorder(root->right_child);// visiting right child
	}
	}


//MAIN Method
int main()
	{
	struct node *root;
	root = NULL;
	int n,i,x;
	struct node *temp;
	printf("Enter the number of elements you want to enter:");
	scanf("%d",&n);
	int a[n];
	printf("Enter the elements:");
	for(i=0; i<n; i++){
	scanf("%d",&a[i]);
	}

	for(i=0; i<n; i++){
	root= insert(root,a[i]);
	}
	
	//Printing the inserted tree
	inorder(root);
	
	//Searching in the tree
	printf("\nEnter the element you want to search from in tree:");
	scanf("%d",&x);	
	temp = search(root,x);
	if(temp!=NULL)
	printf("\nElement %d found!!!",temp->data);
	else
	printf("\nElement not found!!!");
	

	//Deleting an element from the tree
	int ch;
	printf("\nDo you want to delete an element, Press 1 to delete: ");
	scanf("%d",&ch);
	if(ch==1)
	{
	printf("\nEnter the element you want to delete:");
	scanf("%d",&x);
	temp = delete(root,x);
	if(temp!=NULL){
		printf("\n%d element deleted from tree\n",x);
		inorder(root);
		}
	else
	printf("\nElement could not be deleted!!!");
	}
	return 0;
	}
