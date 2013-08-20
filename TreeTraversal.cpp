/* Program    : Various tree traversal
   Written By : Akey-
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
using namespace std;

struct node
{
    int data;
    struct node *l;
    struct node *r;
};

void printGivenLavel(struct node *root,int level,int ltr);

// functio nto create the node of the tree

struct node *create(struct node *root,int data)
{
    struct node *ptr=root,*par,*tmp;
    tmp=(struct node *)malloc (sizeof(struct node));
    tmp->data=data;
    tmp->l=tmp->r=NULL;

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
            if(data>ptr->data)
                ptr=ptr->r;
            else if(data <= ptr->data)
                ptr=ptr->l;
        }

        if(data<par->data)
            par->l=tmp;
        else if(data>par->data)
            par->r=tmp;

        return root;
    }
}

// recursive function to print the inordre traversal of the tree

void inorder(struct node *root)
{
    struct node *ptr=root;
    if(ptr==NULL)
        return ;
    inorder(ptr->l);
    printf("%d ",ptr->data);
    inorder(ptr->r);
}

// function to print the inordre traversal of the tree using stack

void traversalStack(struct node *root)
{
    stack<struct node *>mystack;
    struct node *ptr=root;
    bool done=false;
    while(!done)
    {
        if(ptr!=NULL)
        {
            mystack.push(ptr);
            ptr=ptr->l;
        }
        else
        {
            if(!mystack.empty())
            {
                ptr=mystack.top();
                printf("%d ",ptr->data);
                mystack.pop();
                ptr=ptr->r;
            }
            else
                done=true;
        }

    }
}

// function to calculate the height of the tree using recursion

int height(struct node *root)
{
    if(root==NULL)
        return 0;

    else
    {
        int lh=height(root->l);
        int rh=height(root->r);

        return (lh>rh?lh+1:rh+1);
    }
}

// recursive functio nto print the spiral level order of the tree

void lavelOrder(struct node *root)
{
    int h=height(root);
    int i;
    bool ltr;
    for(i=1;i<=h;i++)
    {
        printGivenLavel(root,i,ltr);
        ltr=!ltr;
    }
}

void printGivenLavel(struct node *root,int level,int ltr)
{
    if(root==NULL)
        return;
    if(level==1)
        printf("%d ",root->data);

    else if(level>1)
    {
        if(ltr)
        {
            printGivenLavel(root->l,level-1,ltr);
            printGivenLavel(root->r,level-1,ltr);
        }
        else
        {
            printGivenLavel(root->r,level-1,ltr);
            printGivenLavel(root->l,level-1,ltr);
        }
    }
}

// function to print reverse level order traversal of the tree

void reverseLevelOrder(struct node * root)
{
    stack<struct node *> st;
    queue<struct node *> qu;
    qu.push(root);

    while(!qu.empty())
    {
        root=qu.front();
        qu.pop();
        st.push(root);

        if(root->r)
            qu.push(root->r);

        if(root->l)
            qu.push(root->l);
    }

    while(!st.empty())
    {
        root=st.top();
        cout<<root->data<<" ";
        st.pop();
    }
}

// function to print iterative level order traversal of the tree

void queueLevelOrder(struct node * root)
{
    queue<struct node *>qu;
    qu.push(root);

    while(!qu.empty())
    {
        root=qu.front();
        qu.pop();
        cout<<root->data<<" ";

        if(root->l)
            qu.push(root->l);

        if(root->r)
            qu.push(root->r);
    }
}

// function to print the spiral level order of the tree using two stacks

void printSpiral(struct node *root)
{
    stack<struct node *>s1;
    stack<struct node *>s2;

    s1.push(root);

    while(!s1.empty() || !s2.empty())
    {
        while(!s1.empty())
        {
            struct node *tmp=s1.top();
            s1.pop();
            cout<<tmp->data<<" ";

            if(tmp->r)
                s2.push(tmp->r);
            if(tmp->l)
                s2.push(tmp->l);
        }

        while(!s2.empty())
        {
            struct node *tmp=s2.top();
            s2.pop();
            cout<<tmp->data<<" ";

            if(tmp->l)
                s1.push(tmp->l);
            if(tmp->r)
                s1.push(tmp->r);
        }
    }
}

// function to calculate the diameter of the given tree

int diameter(struct node *root)
{
    if(root==NULL)
        return 0;

    int lh=height(root->l);
    int rh=height(root->r);

    int ld=diameter(root->l);
    int rd=diameter(root->r);

    return max((lh+rh+1),(max(ld,rd)));
}

//function to calculate the diameter of the tree in O(n)

int diameterE(struct node *root,int *height)
{
    int lh=0,rh=0;
    int ld=0,rd=0;

    if(root==NULL)
    {
        *height=0;
        return 0;
    }

    ld=diameterE(root->l,&lh);
    rd=diameterE(root->r,&rh);

    *height=max(lh,rh) +1;

    return max(lh+rh+1,max(ld,rd));
}

// the main function begins from here

int main()
{
    struct node *root=NULL;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int data;
        scanf("%d",&data);
        root=create(root,data);
    }
    inorder(root);
    printf("\n");
    reverseLevelOrder(root);
    printf("\n");
    queueLevelOrder(root);
    printf("\n");
    printSpiral(root);
    int h;
    printf("\nDiameter of the tree is :%d",diameterE(root,&h));
    return 0;
}
