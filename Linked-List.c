/*
Program   : Programs of Link-list  
written by: Akey- 
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
}*start=NULL;

struct node *create(struct node *start,int value);
void display(struct node *start);
struct node *reverse_three_pointer(struct node *start);
struct node *reverse_two_pointer(struct node *start);
struct node *reverse_iterative(struct node *start);
void delete_single_node(struct node *ptr);
int middle(struct node *start);
int middle_element(struct node *start);
struct node *nthfromlast(struct node *start,int n);
int hasLoop(struct node *start);
struct node *delete_all(struct node *start);
struct node *swapFirstAndLastKthNode(struct node *start,int k);
struct node *sortList(struct node *start);
struct node *sort012(struct node *start);
struct node *getUnion(struct node *start1,struct node *start2);
struct node *getIntersection(struct node *start1,struct node *start2);
int isPresent(struct node *start,int data);
void removeLoop(struct node *start);
struct node *segregateEvenOdd(struct node *start);
struct node *interchangeFirstTwoNode(struct node *start);
struct node *addTwoList(struct node *start1,struct node *start2);
struct node *pairWiseSwap(struct node *start);
struct node *sortedMerge(struct node *a,struct node *b);

int main()
{
	int n;
	printf("Enter no of nodes :");
	scanf("%d",&n);
	int value,i;
	
	for(i=0;i<n;i++)
	{
		printf("Enter the value :");
		scanf("%d",&value);
		start=create(start,value);
	}
	printf("The list is :");
	display(start);
	printf("Enter no of nodes :");
	scanf("%d",&n);
	struct node *start2=NULL,*ptr;
	for(i=0;i<n;i++)
	{
		printf("Enter the value :");
		scanf("%d",&value);
		start2=create(start2,value);
	}
	printf("The list is :");
	display(start2);
	/*start=reverse_iterative(start);
	printf("The list after reverse :");
	display(start);
	delete_single_node(start->link->link);
	int val=middle_element(start);
	printf("middle element is %d ",val);
	start2=reverse_iterative(start2);
	printf("The list after reverse :");
	display(start2);*/
	ptr=sortedMerge(start,start2);
	printf("Lists is :");
	display(ptr);
	/*if(hasLoop(start)) printf("List has loop\n");
	else printf("Doesn't contain loop\n");
	struct node *tmp=start;
	while(tmp->link!=NULL)
	{
		tmp=tmp->link;
	}
	tmp->link=start->link->link;
	if(hasLoop(start)) printf("List ha loop\n");
	else printf("Doesn't contain loop\n");
	display(start);
	start=pairWiseSwap(start);
	display(start);*/
	return 0;
}

struct node *create(struct node *start,int value)
{
	struct node *p,*temp;
	temp=(struct node *)malloc (sizeof(struct node));
	temp->data=value;
	temp->link=NULL;
	
	if(start==NULL)
	{
		start=temp;
		return start;
	}
	else
	{
		p=start;
		while(p->link!=NULL)
		p=p->link;
		
		p->link=temp;
		temp->link=NULL;
		return start;
	}
}

void display(struct node *start)
{
	struct node *p=start;
	if(p==NULL)
	{
		printf("The list is empty\n");
		return ;
	}
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->link;
	}
	printf("\n");
}

struct node *reverse_three_pointer(struct node *start)
{
	struct node *prev,*curr,*next;
	prev=NULL;
	curr=start;
	while(curr!=NULL)
	{
		next=curr->link;
		curr->link=prev;
		prev=curr;
		curr=next;
	}
	start=prev;
	return start;
}

struct node *reverse_two_pointer(struct node *start)
{
	struct node *temp;
	if(start==NULL)
	return NULL;
	
	if(start->link==NULL)
	return start;
	
	temp=reverse_two_pointer(start->link);
	start->link->link=start;
	start->link=NULL;
	return temp;
}

struct node *reverse_iterative(struct node *start)
{
	struct node *p,*q;
	p=start;
	q=p->link;
	p->link=NULL;
	
	while(q)
	{
		q = (struct node *) ((int)p ^ (int)q ^ (int)q->link ^ (int)(q->link=p) ^ (int)(p=q));
	}
	start=p;
	return start;
}

void delete_single_node(struct node *ptr)
{
	struct node *temp=ptr->link;
	ptr->data=temp->data;
	ptr->link=temp->link;
	free(temp);
	
}

int middle(struct node *start)
{
	struct node *slow=start,*fast=start;
	
	if(start!=NULL)
	{
		while((fast->link!=NULL)&&(fast->link->link!=NULL))
		{
			fast=fast->link->link;
			slow=slow->link;
		}
	}
	return slow->data;
}

int middle_element(struct node *start)
{
	int count=0;
	struct node *mid=start;
	
	while(start->link!=NULL)
	{
		if(count&1)
		mid=mid->link;
		
		count++;
		start=start->link;
	}
	
	if(mid!=NULL)
	return mid->data;
}

struct node *nthfromlast(struct node *start,int n)
{
	struct node *ptr=start,*temp=start;
	while(n--)
	{
		temp=temp->link;
	}
	
	while(temp!=NULL)
	{
		temp=temp->link;
		ptr=ptr->link;
	}
	
	return ptr;
}

int hasLoop(struct node *start)
{
	struct node *slow=start,*fast=start;
	while(slow&&fast&&fast->link)
	{
		slow=slow->link;
		fast=fast->link->link;
		if(slow==fast)
		return 1;
	}
	
	return 0;
}

struct node *delete_all(struct node *start)
{
	struct node *ptr,*temp;
	ptr=start;
	
	while(ptr!=NULL)
	{
		temp=ptr->link;
		free(ptr);
		ptr=temp;
	}
	start=ptr;
	return start;
}

int countNode(struct node *start)
{
	struct node *ptr=start;
	int count =0;
	if(start==NULL)
	return 0;
	
	while(ptr!=NULL)
	{
		count++;
		ptr=ptr->link;
	}
	
	return count;
}
struct node *swapFirstAndLastKthNode(struct node *start,int k)
{
	int n=countNode(start),i;
	
	if(k>n)
	return start;
	
	if(k==(n-k+1))
	return start;
	
	struct node *first=start;
	struct node *first_prev=NULL;
	for(i=1;i<k;i++)
	{
		first_prev=first;
		first=first->link;
	}
	
	struct node *last=start;
	struct node *last_prev=NULL;
	for(i=1;i<(n-k+1);i++)
	{
		last_prev=last;
		last=last->link;
	}
	
	first_prev->link=last;
	last_prev->link=first;
	
	struct node *tmp=first->link;
	first->link=last->link;
	last->link=tmp;
	
	return start;
}

/*struct node *sortList(struct node *start)
{
	struct node *tmp=NULL,*tmp1=NULL;
	struct ndoe *begin[3]={NULL,NULL,NULL};
	struct ndoe *end[3]={NULL,NULL,NULL};
	
	for(tmp=start;tmp!=NULL;)
	{
		tmp1=tmp;
		tmp=tmp->link;
		
		if(begin[tmp1->data]==NULL)
		{
			begin[tmp1->data]=tmp1;
			end[tmp1->data]=tmp1;
			tmp1->link=NULL;
		}
		else
		{
			tmp1->link=begin[tmp1->data];
			begin[tmp->data]=tmp1;
		}
	}
	
	end[0]->link=begin[1];
	end[1]->link=begin[2];
	return begin[0];
}*/

struct node *sort012(struct node *start)
{
	if(start==NULL||start->link==NULL)
	return start;
	
	int noOfNodes=countNode(start);
	
	struct node *tail=start;
	struct node *ptr=start;
	struct node *prev=start;
	
	while(tail->link!=NULL) tail=tail->link;
	int i;
	
	for(i=0;i<noOfNodes;i++)
	{
		struct node *tmp=ptr;
		ptr=ptr->link;
		
		if(tmp->data==0)
		{
			if(prev!=tmp)
			{
				tmp->link=start;
				start=tmp;
				prev->link=ptr;
			}
		}
		
		else if(tmp->data==2)
		{
			tail->link=tmp;
			tmp->link=NULL;
			tail=tmp;
			
			if(prev==tmp) start=prev=ptr;
			else prev->link=ptr;
		}
		
		else
		{
			if(prev!=tmp)
			prev=prev->link;
		}
	}
	return start;
}

int isPresent(struct node *start,int data)
{
	struct node *ptr=start;
	while(ptr!=NULL)
	{
		if(ptr->data==data)
		return 1;
		
		ptr=ptr->link;
	}
	return 0;
}

struct node *getUnion(struct node *start1,struct node *start2)
{
	if(start1==NULL)
	return start2;
	
	if(start2==NULL)
	return start1;
	
	struct node *Union=NULL;
	
	while(start1!=NULL)
	{
		Union=create(Union,start1->data);
		start1=start1->link;
	}
	
	while(start2!=NULL)
	{
		if(!isPresent(Union,start2->data))
		Union=create(Union,start2->data);
		
		start2=start2->link;
	}
	
	return Union;
}

struct node *getIntersection(struct node *start1,struct node *start2)
{
	if(start1==NULL)
	return start2;
	
	if(start2==NULL)
	return start1;
	
	struct node *intersection=NULL;
	
	while(start1!=NULL)
	{
		if(isPresent(start2,start1->data))
		intersection=create(intersection,start1->data);
		
		start1=start1->link;
	}
	
	return intersection;
}

void removeLoop(struct node *start)
{
	struct node *slow=start,*fast=start,*tmp=start;
	
	while(tmp->link!=NULL)
	{
		tmp=tmp->link;
	}
	tmp->link=start->link->link;
	
	if(hasLoop(start)) printf("List ha loop\n");
	else printf("Doesn't contain loop\n");
	
	while(slow&&fast&&fast->link)
	{
		slow=slow->link;
		fast=fast->link->link;
		if(slow==fast)
		{
			slow=start;
			fast=fast->link;
			while(slow->link!=fast)
			{
				slow=slow->link;
				fast=fast->link;
			}
			
			fast->link=NULL;
		}
	}
	
	if(hasLoop(start)) printf("List ha loop\n");
	else printf("Doesn't contain loop\n");
}

struct node *segregateEvenOdd(struct node *start)
{
	struct node *tmp,*ptr=start,*last=start,*prev;
	
	while(last->link!=NULL) last=last->link;
	struct node *begin=last;
	
	while(ptr->link!=begin)
	{
		if(ptr->data%2)
		{
			start=ptr->link;
			tmp=ptr;
			tmp->link=NULL;
			last->link=tmp;
			last=tmp;
			ptr=start;
		}
		
		else
		{
			prev=ptr;
			ptr=ptr->link;
		
			if(ptr->data%2)
			{
				tmp=ptr;
				prev->link=ptr->link;
				tmp->link=NULL;
				last->link=tmp;
				last=tmp;
				ptr=prev;
			}
		}
	}
	return start;
}

struct node *interchangeFirstTwoNode(struct node *start)
{
	struct node *tmp=start,*ptr;
	start=start->link;
	ptr=start;
	
	tmp->link=ptr->link;
	ptr->link=tmp;
	
	return start;
}

struct node *addTwoList(struct node *start1,struct node *start2)
{
	struct node *result=NULL;
	int carry=0;
	
	while(start1!=NULL||start2!=NULL)
	{
		int sum=carry+(start1?start1->data:0)+(start2?start2->data:0);
		carry=(sum>10)?1:0;
		sum=sum%10;
		result=create(result,sum);
		
		if(start1) start1=start1->link;
		if(start2) start2=start2->link;
	}
	
	if(carry)
	result=create(result,carry);
	
	return result;
}

struct node *pairWiseSwap(struct node *start)
{
	struct  node *ptr=start,*tmp,*tmp1,*newHead=start->link;
	
	while(ptr!=NULL&&ptr->link!=NULL)
	{
		tmp=ptr->link->link;
		ptr->link->link=ptr;
		
		if(tmp!=NULL)
		{
			if(tmp->link!=NULL)
			ptr->link=tmp->link;
			else
			ptr->link=tmp;
		}
		else
		ptr->link=NULL;
		
		ptr=tmp;
	}
	return newHead;
}

struct node *sortedMerge(struct node *a,struct node *b)
{
	struct node tmp;
	struct node *tail=&(tmp);
	
	while(1)
	{
		if(a==NULL)
		{
			tail->link=b;
			break;
		}
		if(b==NULL)
		{
			tail->link=a;
			break;
		}
		
		if(a->data <= b->data)
		{
			tail->link=a;
			tail=tail->link;
			a=a->link;
		}
		else
		{
			tail->link=b;
			tail=tail->link;
			b=b->link;
		}	
	}
	
	return tmp.link;
}
