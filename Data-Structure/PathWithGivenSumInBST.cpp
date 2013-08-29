/* Program to find path in BST equal to given sum
   Written By : Akey-
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

bool pathWithGivenSum(struct node *root,int sum);
void allPathWithGivenSum(struct node *root,int expectedSum);
void findPath(struct node *root,int expectedSum,vector<int>&path,int currSum);

//this function will create BST
struct node *create(struct node *root,int data)
{
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    t->data=data;
    t->left=t->right=NULL;

    if(root==NULL)
    {
        root=t;
    }
    else if(root->data>data)
        root->left=create(root->left,data);
    else if(root->data<=data)
        root->right=create(root->right,data);

    return root;
}

//this function will display the inorder traversal of a BST
void inorder(struct node *root)
{
    struct node *ptr=root;
    if(ptr==NULL) return;

    inorder(ptr->left);
    printf("%d ",ptr->data);
    inorder(ptr->right);
}

//this is our main function
int main()
{
    struct node *root=NULL;
    int n,data,i;
    scanf("%d",&n);
    for( i=0;i<n;i++)
    {
        scanf("%d",&data);
        root=create(root,data);
    }
    inorder(root);
    int sum;scanf("%d",&sum);
    if(pathWithGivenSum(root,sum)) printf("Path is Present\n");
    else printf("Path is not present\n");
    allPathWithGivenSum(root,sum);
    return 0;
}

//this function will check whether there exists a path with given sum or not
bool pathWithGivenSum(struct node *root,int sum)
{
    if(root==NULL)
        return(sum==0);

    else
    {
        int subSum=sum-root->data;

        return pathWithGivenSum(root->left,subSum)|| pathWithGivenSum(root->right,subSum);
    }
}

// this fucntion will find all path whose sum is equal to given sum
void allPathWithGivenSum(struct node *root,int expectedSum)
{
    if(root==NULL) return;
    vector<int>path;
    int currSum=0;
    findPath(root,expectedSum,path,currSum);
}

void findPath(struct node *root,int expectedSum,vector<int>&path,int currSum)
{
    currSum+=root->data;
    path.push_back(root->data);

    bool isLeaf=root->left==NULL && root->right==NULL;
    if(currSum==expectedSum)
    {
        printf("Path Found :\n");
        vector<int>::iterator it=path.begin();
        for(;it!=path.end();it++) printf("%d ",*it);printf("\n");
    }

    if(root->left)
        findPath(root->left,expectedSum,path,currSum);

    if(root->right)
        findPath(root->right,expectedSum,path,currSum);

    path.pop_back();
}
