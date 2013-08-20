/* Program tp print the boundary of a BST
   Written by : Akey-
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create(struct node *root,int data)
{
    if(root==NULL)
    {
        struct node *tmp;
        tmp=(struct node *)malloc(sizeof(struct node));
        tmp->data=data;
        tmp->left=tmp->right=NULL;
        root=tmp;
    }
    else if(data>root->data)
        root->right=create(root->right,data);
    else if(data<=root->data)
        root->left=create(root->left,data);
    return root;
}

void display(struct node *root)
{
    struct node *ptr=root;
    if(ptr==NULL) return;
    display(ptr->left);
    printf("%d ",ptr->data);
    display(ptr->right);
}

// here are the function which will print the boundary of a binary tree
void printLeftBoundary(struct node *root)
{
    if(root==NULL) return ;

    if(root->left)
    {
        printf("%d ",root->data);
        printLeftBoundary(root->left);
    }

    else if(root->right)
    {
        printf("%d ",root->data);
        printLeftBoundary(root->right);
    }
}

void printLeaf(struct node * root)
{
    if(root)
    {
        printLeaf(root->left);
        if(root->left==NULL && root->right==NULL)
            printf("%d ",root->data);
        printLeaf(root->right);
    }
}

void printRightBoundary(struct node *root)
{
    if(root==NULL) return ;

    if(root->right)
    {
        printRightBoundary(root->right);
         printf("%d ",root->data);
    }

    else if(root->left)
    {
        printRightBoundary(root->left);
         printf("%d ",root->data);
    }
}

void printBoundary(struct node * root)
{
    if(root)
    {
        printf("%d ",root->data);
        printLeftBoundary(root->left);
        printLeaf(root);
        printRightBoundary(root->right);
    }
}

// here the function main starts

int main()
{
    struct node *root=NULL;
    int n,i;
    scanf("%d",&n);

    for( i=0;i<n;i++)
    {
        int data;
        scanf("%d",&data);
        root=create(root,data);
    }
    display(root);printf("\n");
    printBoundary(root);
}
