/* Program to create doubly linked -list from BST
   Written by : Akey-
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}Node;


int main()
{
	Node *root=NULL,*root1=NULL;
	int n,data,i;
	printf("Enter the no of nodes : ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("Enter value for the node : ");
		scanf("%d",&data);
		root=createTree(root,data);
	}
	
	printf("The tree is : ");
	inorder(root);
	return 0;
}

Node *createTree(Node *root,int data)
{
	Node *ptr=root,*par,*tmp;
	tmp=(Node *)malloc(sizeof(Node));
	tmp->data=data;
	tmp->left=NULL;
	tmp->right=NULL;
	
	if(root==NULL)
	{
		root=tmp;
		return root;
	}
	else
	{
		while(ptr!=NULL)
		{
			par=ptr;
			if(ptr->data>data)
			ptr=ptr->left;
			else if(ptr->data<data)
			ptr=ptr->right;
			else{
			printf("Duplicate keys!!!");}
		}
		
		if(par->data>data)
		par->left=tmp;
		else if(par->data<data)
		par->right=tmp;
		return root;
	}
}

void inorder(struct node *root)
{
	struct node *ptr=root;
	if(ptr==NULL) return ;
	
	inorder(ptr->left);
	printf("%d ",ptr->data);
	inorder(ptr->right);
}

Node *treeToDoubly(Node *root)
{
	Node *head=NULL;
	Node *tail=NULL;
	
	treeToDoublyList(root,head,tail);
}
 
void treeToDoublyList(Node *root,Node *head,Node *tail)
{
	if(root==NULL) return ;
	
	treeToDoublyList(root->left,head,tail);
	
	if(tail==NULL)
	{
		head=root;
		tail=head;
	}
	else
	{
		tail->right=root;
		root->left=tail;
		tail=root;
	}
}
