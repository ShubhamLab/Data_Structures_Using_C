#include<stdio.h>	//menu driven program for doubly linked list
#include<stdlib.h>
int cnt;
struct node
{
	struct node *prev;
	int data;
	struct node *next;
};
struct node *last;
struct node *create(struct node*);
struct node *insert(struct node*,int pos);
void display(struct node *head);
struct node *delete(struct node *,int pos);

int main()
{       
	int pos=0,ch,val=0;
	struct node *head=0;
	while(1)
	{	
	printf("Operations on doubly circular linked list are\n1 Create/append\n2 insert at given position\n3 Display\n4 Delete\n");
	printf("Enter the operation you want to do\n");		
	scanf("%d",&ch);
	
	switch(ch)
	{
		case 1: head=create(head);
			break;
		case 2: 
				do{
				printf("At which position u want to insert node\n");
				scanf("%d",&pos);
				}while(pos<=0||pos>=(cnt+1));
				head=insert(head,pos);
		case 3: if(head==0)
				printf("Linked list is empty\n");
			else
				display(head);
			break;
		case 4: do{
				printf("At which position do you want to delete the node\n");
				scanf("%d",&pos);
				}while(pos<=0||pos>=(cnt+1));
				head=delete(head,pos);
				break;
	}
}
}
	struct node *create(struct node *head)
	{
		int n,i,cnt;
		struct node *p;
		
			printf("How many nodes you want to create\n");
			scanf("%d",&n);
		
	
		for(i=1;i<=n;i++)
		{
			p=(struct node *)malloc(sizeof(struct node));
			if(p==NULL)
				printf("Memory allocation failed\n");
			else
			{
				printf("Enter the value of node %d\n",i);
				scanf("%d",&p->data);
				p->next=0;
				p->prev=0;
				if(head==NULL)
				{
					last=head=p;
					p->next=p->prev=head;
				}
				else
				{
					p->next=head;
					p->prev=last;
					last->next=p;
					head->prev=p;
					last=p;
				}
			cnt++;
		}
		
		}
	return head;
	}

	void display(struct node *head)
	{
		struct node *temp;
		temp=head;
		if(temp==NULL)
		{
			printf("Linked list is empty\n");
		}
		else
		{
			do
			{
				printf("\n\n\n");
				printf("Linked list is %d\n",temp->data);
				temp=temp->next;
			}while(temp->next!=head->next);
		}	
		printf("\n\n\n");
	}

	struct node *insert(struct node *head,int pos)
	{
	}

	struct node *delete(struct node *head,int pos)
	{
	}	
	

