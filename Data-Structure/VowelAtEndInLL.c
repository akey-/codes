/* Program to move all vowels at the end of a word represented by a link-list
   Written By : Akey-
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structure of link list
struct node 
{
	char data;
	struct node * link;
}*start=NULL;

//this function will create the link list by adding the element at last
struct node *create(struct node *start,char data)
{
	struct node *p,*tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->data=data;
	if(start==NULL)
	{
		start=tmp;
		tmp->link=NULL;
		return start;
	}
	else
	{
		p=start;
		while(p->link!=NULL)
			p=p->link;
		p->link=tmp;
		tmp->link=NULL;
		return start;
	}
}

//this function will display the list 
void display(struct node *start)
{
	struct node *p=start;
	if(p==NULL) return;

	while(p)
	{
		printf("%c ",p->data);
		p=p->link;
	}
}

//this function will segregate the vowels at the end 
struct node *vowels_at_end(struct node *start)
{
	struct node *ptr,*final_tail,*initial_tail,*prev,*tmp;
	initial_tail=start;
	while(initial_tail->link!=NULL) initial_tail=initial_tail->link; //this wil be our initial tail end of the link list

	final_tail=initial_tail; //this will be our fianl tail end of the link list

	ptr=start;
	while(ptr!=initial_tail)
	{
		if(ptr==start)
		{
			if(ptr->data=='a' || ptr->data=='e' || ptr->data=='i' || ptr->data=='o' || ptr->data=='u')
			{
				start=ptr->link;
				final_tail->link=ptr;
				ptr->link=NULL;
				final_tail=ptr;
				ptr=start;
			}	
			else 
			{
				prev=ptr;
				ptr=ptr->link;
			}
		}
		else
		{
			if(ptr->data=='a' || ptr->data=='e' || ptr->data=='i' || ptr->data=='o' || ptr->data=='u')
			{
				prev->link=ptr->link;
				final_tail->link=ptr;
				ptr->link=NULL;
				final_tail=ptr;
				ptr=prev->link;
			}
			else
			{
				prev=ptr;
				ptr=ptr->link;
			}
		}
		
	}
	return start;
}

//main function
int main(int argc, char const *argv[])
{
	int n,i;
	scanf("%d",&n);
	char data;

	for(i=0;i<n;i++)
	{
		scanf(" %c",&data);
		start=create(start,data);
	}
	display(start);printf("\n");
	start=vowels_at_end(start);
	display(start);
	return 0;
}
