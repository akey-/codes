/*Program    : Binary Tree creation and some operation
  Written by : Akey-
  
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}Node;

int MAX=0;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}

Node *createTree(Node *root,int data);
void inorder(Node *root);
void deleteTree(Node *root);
int identicalTree(Node *a,Node *b);
void mirror(Node *root);
void rootToLeafPath(Node *root,int a[],int len);
int maxRootToLeafPath(Node *root,int sum);
Node *LCA(Node *root,Node *a,Node *b);
Node *leastCommanAncestor(Node *root,Node *a,Node *b);

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
	printf("\n");
	/*printf("\nEnter the no of nodes : ");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		printf("Enter value for the node : ");
		scanf("%d",&data);
		root1=createTree(root1,data);
	}
	printf("The tree is : ");
	inorder(root1);
	if(identicalTree(root,root1)) printf("Trees are same\n");
	else printf("Not same");
	printf("\nHeight of the Tree is %d\n ",Height(root));
    mirror(root);
	inorder(root);
	int a[100];*/
	//printf("%d :",maxRootToLeafPath(root,0));
	root=LCA(root,root->right->right->left->right,root->right->right->right);
	printf("%d ",root->data);
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

void inorder(Node *root)
{
	Node *ptr=root;
	if(ptr==NULL)
	return ;

	inorder(ptr->left);
	printf("%d ",ptr->data);
	inorder(ptr->right);
}

// function to calculate the height of the tree

int Height(Node *root)
{
	Node *ptr=root;
	if(ptr==NULL)
	return 0;

	int left=Height(ptr->left);
	int right=Height(ptr->right);

	return (left>right?left+1:right+1);
}

// function to delete the entire tree

void deleteTree(Node *root)
{
	if(root==NULL)
	return ;

	deleteTree(root->left);
	deleteTree(root->right);

	free(root);
}

// function to check whether the two tree are identical

int identicalTree(Node *a,Node *b)
{
	if(a==NULL&&b==NULL) return 1;

	else if(a!=NULL && b!=NULL)
	{
		return (a->data==b->data && identicalTree(a->left,b->left) && identicalTree(a->right,b->right));
	}
	else return 0;
}

// function to create the mirror of the tree

void mirror(Node *root)
{
	if(root==NULL) return;
	else
	{
		Node *tmp;

		mirror(root->left);
		mirror(root->right);

		tmp=root->left;
		root->left=root->right;
		root->right=tmp;
	}
}

//function to find the all root to leaf path in the tree

void rootToLeafPath(Node *root,int a[],int len)
{
	if(root==NULL) return ;

	a[len++]=root->data;

	if(root->left==NULL && root->right==NULL)
	{
		int i;
		for(i=0;i<len;i++) printf("%d ",a[i]);printf("\n");
	}

	else
	{
		rootToLeafPath(root->left,a,len);
		rootToLeafPath(root->right,a,len);
	}
}

// function to find the maximum root to leaf path in the tree

int maxRootToLeafPath(Node *root,int sum)
{
	if(root==NULL) return ;

	sum+=root->data;
	MAX=MAX>sum?MAX:sum,printf("%d ",sum);

	if(root->left==NULL && root->right==NULL)
	{
		//printf("%d ",sum);printf("\n");
	}

	else
	{
		maxRootToLeafPath(root->left,sum);
		maxRootToLeafPath(root->right,sum);
	}
	return MAX;
}

// function to find the least common ancestor of the two nodes in the tree

Node *LCA(Node *root,Node *a,Node *b)
{
	if(root==NULL||a==NULL||b==NULL||root==a||root==b) return NULL;

	while(root!=NULL)
	{
		Node *tmp=root;

		if(a->data<root->data && b->data>root->data || a->data>root->data && b->data<root->data)
		return root;

		else if(a->data<root->data && b->data<root->data)
		{
			tmp=root;
			root=root->left;
		}

		else if(a->data>root->data && b->data>root->data)
		{
			tmp=root;
			root=root->right;
		}

		else if(a->data==root->data && b->data==root->data)
		return tmp;
	}
}

Node *leastCommanAncestor(struct node* root, Node *n1,Node *n2)
{
	if(root == NULL || n1 == NULL || n2 == NULL)
		return NULL;

	if(root->data==n1->data || root->data==n2->data) return root;

	if((root->right != NULL) && (root->right->data == n1->data || root->right->data == n2->data))
		return root;
	if((root->left != NULL) && (root->left->data == n1->data || root->left->data == n2->data))
		return root;

	if(root->data > n1->data && root->data < n2->data)
		return root;
	if(root->data > n1->data && root->data > n2->data)
		return leastCommanAncestor(root->left, n1, n2);
	if(root->data < n1->data && root->data < n2->data)
		return leastCommanAncestor(root->right, n1, n2);
}
