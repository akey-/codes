/* Program to delete n nodes after m nodes in a linked list
   Written By : Akey-
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};

// following function will create the link-list

struct node * create(struct node *start,int data)
{
    struct node *ptr,*tmp;
    tmp=(struct node *)malloc(sizeof(struct node));
    tmp->info=data;
    tmp->link=NULL;

    if(start==NULL)
    {
        start=tmp;
        return start;
    }
    else
    {
        ptr=start;
        while(ptr->link!=NULL)
            ptr=ptr->link;

        ptr->link=tmp;
        return start;
    }
}

int _count(struct node *start)
{
    int cnt=0;
    while(start!=NULL)
    {
        cnt++;
        start=start->link;
    }
    return cnt;
}

//this function will delete n nodes of a linked list after m nodes

struct node *deleteNafterMnodes(struct node *start,int m,int n)
{
    struct node *ptr=start,*tmp,*q;
    int i;

    while(ptr)
    {
        for(i=1;i<m && ptr!=NULL;i++)
            ptr=ptr->link;

        if(ptr==NULL) return start;

        for(i=0;i<n && ptr!=NULL;i++)
        {
            tmp=ptr->link;
            ptr->link=tmp->link;
            free(tmp);
        }
        ptr=ptr->link;

    }

    return start;
}

//here is the display function

void display(struct node *start)
{
    struct node *ptr=start;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->info);
        ptr=ptr->link;
    }
    printf("\n");
}

//here is the main function begins
int main()
{
    struct node * start=NULL,*start1=NULL;
    int data,n,i,j;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&data);
        start=create(start,data);
    }
    display(start);
    scanf("%d%d",&i,&j);
    start=deleteNafterMnodes(start,i,j);
    display(start);
    return 0;
}
