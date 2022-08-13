#include<stdio.h>     //menu driven program for doubly linked list
#include<stdlib.h>
 struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *head=NULL,*next=NULL,*prev=NULL;
int len,pos;
void create(void);
void insert(void);
int length(void);
void display(void);
void delete(void);


	

int main()
{
	int ch,len;
	while(1)
	{
		printf("Following are the operations\n"); 
		printf("\n\n");
		printf("1 create\n");
		printf("2 insert\n");
		printf("3 length\n");
		printf("4 Display\n");
		printf("5 Delete\n");

		printf("Enter your choice\n");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: create();
				break;
	
			case 2: insert();
				break;
	


			case 3: len=length();
				printf("\n\n\n");
                                printf("LENGTH OF LINKED LIST IS=%d\n",len);
				printf("\n\n\n");
				break;

			case 4: display();
				break;
			
			case 5: delete();
		
				break;

					
		}
		
	}
}





	void create()
	{
		int i,n;
		struct node *newnode=NULL,*last=NULL;
		printf("How many nodes you want to create\n");
		scanf("%d",&n);		
		for(i=1;i<=n;i++)
		{
			newnode=(struct node *)malloc(sizeof(struct node));
		if(newnode==NULL)
			printf("Memory allocation failed\n");
		else
		{
			printf("Enter node data\n");
			scanf("%d",&newnode->data);
			if(head==NULL)
				head=last=newnode;
			else
			{
				last->next=newnode;
				newnode->prev=last;
				last=newnode;
			}
		}
	}		
	}






	

	void insert()
	{
		int i,pos;
		struct node *temp,*newnode=NULL;
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("Enter the position at which you want to insert the newnode\n");
		scanf("%d",&pos);
		if(newnode==NULL)
			printf("Memory allocation failed\n");
		else
		{
			printf("Newnode data\n");
			scanf("%d",&(newnode->data));
			newnode->prev=newnode->next=NULL;
		}
		
		if(pos==1)
		{
		if(head==NULL)
		{
			
			head=newnode;
		}
		else
		{
			newnode->next=head;
			head->prev=newnode;
			newnode=head;
		
			
		}
		}
		else
		{
			temp=head;
			for(i=1;i<pos-1;i++)
			{
				temp=temp->next;
			}
				newnode->next=temp->next;
				newnode->prev=temp;
			
		if(newnode->next!=NULL)
		{
			(newnode->next)->prev=newnode;
			temp->next=newnode;
		}
		}
		}

	




	


int length()
{
	int cnt;
		struct node * p;
	p=head;
	while(p!=NULL)
	{
		cnt++;
		p=p->next;
	}
	return cnt;


}

void display()
{
	struct node *temp=head;
	printf("Linked list is\n");
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}


}



void delete()
{
	int i,pos,cnt;
	struct node *temp=0,*q=0;
	printf("Enter the position\n");
		scanf("%d",&pos);
	temp=head;
	if(pos==1)
	{
		if(head->next==0)
		{
			printf("Deleted element is %d\n",head->data);
			free(head);
			head=0;
			--cnt;
			return head;
		}
		else
		{
			head=head->next;
			head->prev=0;
		}
	}
	else
	{
		q=head;
		for(i=1;i<pos-1;i++)
		{
			q=q->next;
		}
		temp=q->next;
		if(temp->next!=0)
			(temp->next)->prev=q;
		q->next=temp->next;
	}

	printf("Deleted element is %d\n",temp->data);
	temp->prev=temp->next=0;
	free(temp);
	--cnt;
	return head;
	}











