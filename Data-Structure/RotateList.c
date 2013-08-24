/* Program to rotate linked list counter -clockwise by k node
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

//this function will rotate the link list anti-clockwise

struct node *rotateList(struct node *start,int k)
{
    struct node *ptr,*tail=start;
    int i;
    while(tail->link!=NULL) tail=tail->link;

    for(i=0;i<k;i++)
    {
        ptr=start;
        start=start->link;

        tail->link=ptr;
        ptr->link=NULL;
        tail=ptr;
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
    int data,n,i;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&data);
        start=create(start,data);
    }
    display(start);
    scanf("%d",&i);
    start=rotateList(start,i);
    display(start);
    return 0;
}
