/* Program that connect two link-list alternatively
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

// following function will connect the link-list alternatively

struct node *connectAlternatively(struct node *start1,struct node *start2)
{
    struct node *ptr1=start1,*ptr2=start2,*tmp1,*tmp2;
    while(ptr1 && ptr2)
    {
        tmp1=ptr1->link;
        tmp2=ptr2->link;

        ptr1->link=ptr2;
        ptr2->link=tmp1;

        ptr1=tmp1;
        ptr2=tmp2;
    }
    return start1;
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
    int data,n,m;
    scanf("%d",&n);
    m=n;
    while(n--)
    {
        scanf("%d",&data);
        start=create(start,data);
    }

    while(m--)
    {
        scanf("%d",&data);
        start1=create(start1,data);
    }

    display(start);
    display(start1);
    start=connectAlternatively(start,start1);
    display(start);
    return 0;
}
