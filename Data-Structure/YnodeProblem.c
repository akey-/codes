/* Program to check whether two linked-list intersect or not
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

// following function will connect the link-list alternatively

int intersect(struct node *start1,struct node *start2)
{
    int cnt1=_count(start1);
    int cnt2=_count(start2);

    int diff=cnt1>cnt2?(cnt1-cnt2):(cnt2-cnt1);

    if(cnt1>cnt2)
    {
        while(diff--)
            start1=start1->link;
    }
    else
    {
        while(diff--)
            start2=start2->link;
    }

    while(start1 && start2)
    {
        if(start1==start2)
            return 1;
        start1=start1->link;
        start2=start2->link;
    }

    return 0;
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
    m=n-2;
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

    struct node * tmp=start1;
    while(tmp->link!=NULL) tmp=tmp->link;
    tmp->link=start->link->link->link;

    display(start);
    display(start1);

    if(intersect(start,start1)) printf("Linked -List intersect\n");
    else printf("Linked list don't intersect\n");
    return 0;
}
