#include<stdio.h>    //intersection of 2 linked list
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};

struct node *create(struct node *,int n);
void display(struct node *);
struct node * intersection(struct node *,struct node *);
int main()
{
	int n,i;
	struct node *h1=0,*h2=0,*h3=0;
	h1=create(h1,n);
	h2=create(h2,n);
	printf("Elements in linked list 1 are\n");
	display(h1);
	printf("Elements in linked list 2 are\n");	
	display(h2);
	printf("Intersection of linked list is\n");
	h3=intersection(h1,h2);
	display(h3);
}

	struct node *create(struct node *h,int n)
	{
		int i;
		struct node *p=0,*l=0;
		
			printf("How many nodes you want in linked list\n");
			scanf("%d",&n);
			
		
	
		for(i=0;i<n;i++)
		{
			p=(struct node *)malloc(sizeof(struct node));
			if(p==0)
				printf("Failed\n");
			else
			{
				printf("Enter node data\n");
				scanf("%d",&(p->data));
				p->next=0;
			}

			if(h==0)
				h=l=p;
			else
			{
				l->next=p;
				l=p;
			}
		
		}
		return h;
	}
	
	struct node *intersection(struct node *h1,struct node *h2)
	{
		struct node *newnode,*h3=0,*l3,*first,*second;
		for(first=h1;first!=0;first=first->next)
		{
			for(second=h2;second!=0;second=second->next)
			{
				if(first->data==second->data)
				{newnode=(struct node *)malloc(sizeof(struct node));
				newnode->next=0;
				newnode->data=second->data;
				if(h3==0)
					h3=l3=newnode;
				else
				{	
					l3->next=newnode;
					l3=newnode;
				}
				}
			}
		}
		return h3;
		
	}
	

	void display(struct node *h)
	{
		while(h!=0)
		{
			printf("%d",h->data);
			h=h->next;
		}
		printf("\n");
		
	}				
