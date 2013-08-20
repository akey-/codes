/* program to delete nth node from last of a linked-list
   Written by : Akey-
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *create(struct node * start,int data);
void display(struct node *start);

int count(struct node *start)
{
    struct node * ptr=start;
    int count=0;

    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->link;
    }
    return count;
}

struct node *deleteNthFromLast(struct node * start,int n)
{
    struct node *first=start,*second=start;

    if(n>count(start))
        return NULL;

    while(n--)
        first=first->link;

    while(first->link!=NULL)
    {
        first=first->link;
        second=second->link;
    }

    struct node *tmp=second->link;
    second->link=tmp->link;
    free(tmp);
    return start;
}

int main()
{
    struct node *start=NULL;
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        int data;
        scanf("%d",&data);
        start=create(start,data);
    }
    display(start);
    start=deleteNthFromLast(start,3);
    display(start);
    return 0;
}

struct node * create(struct node *start,int data)
{
    struct node *ptr=start,*tmp;
    tmp=(struct node *)malloc(sizeof (struct node));
    tmp->data=data;

    if(start==NULL)
    {
        start=tmp;
        tmp->link=NULL;
        return start;
    }
    else
    {
        ptr=start;
        while(ptr->link!=NULL)
            ptr=ptr->link;
        ptr->link=tmp;
        tmp->link=NULL;
        return start;
    }
}

void display(struct node *start)
{
    struct node *ptr=start;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    printf("\n");
}
