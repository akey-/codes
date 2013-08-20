/* Program    : Tree traversal without recursion and stack
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

Node *createTree(Node *root,int data);
void MorrisTraversal(Node *root);
void preorderMorris(Node *root);

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
	preorderMorris(root);
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

void MorrisTraversal(Node *root)
{
	Node *current,*pre;
	if(root==NULL) return;

	current=root;
	while(current!=NULL)
	{
		if(current->left==NULL)
		{
			printf("%d ",current->data);
			current=current->right;
		}
		else
		{
			pre=current->left;
			
			while(pre->right!=NULL&&pre->right!=current)
			pre=pre->right;
			
			if(pre->right==NULL)
			{
				pre->right=current;
				current=current->left;
			}
			else
			{
				pre->right=NULL;
				printf("%d ",current->data);
				current=current->right;
			}
		}
	}
}

void preorderMorris(Node *root)
{
	if(root==NULL) return ;
	
	while(root!=NULL)
	{
		if(root->left==NULL)
		{
			printf("%d ",root->data);
			root=root->right;
		}
		
		else
		{
			Node *current=root->left;
			
			while(current->right!=NULL&&current->right!=root)
			current=current->right;
			
			if(current->right==NULL)
			{
				printf("%d ",root->data);
				current->right=root;
				root=root->left;
			}
			
			else
			{
				current->right=NULL;
				root=root->right;
			}
		}
	}
}
