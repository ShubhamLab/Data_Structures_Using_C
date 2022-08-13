#include<stdio.h>   //menu driven program for singly circular linked list
#include<stdlib.h>
 struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;
struct node *tail=NULL;
int len;
void append(void);
void addatbegin(void);
void addinbetween(void);
int length(void);
void display(void);
void delete(void);
void search(void);


int main()
{
	int ch,n;
	while(1)
	{
		printf("Following are the operations\n");
		printf("1 Create or Append\n");
		printf("2 Add at begining\n");
		printf("3 Add in between\n");
		printf("4 Length of list\n");
		printf("5 Display the string\n");
		printf("6 Delete\n");
		printf("7 Search\n");		

		printf("Enter your choice\n");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: append();
				break;

			case 2: addatbegin();
				break;
			
			case 3: addinbetween();
				break;
		
			case 4: len=length();
				printf("\n\n\n");
                                printf("LENGTH OF LINKED LIST IS=%d\n",len);
				printf("\n\n\n");
				break;

			case 5: display();
				break;
			
			case 6: delete();
				break;
				
			case 7: search();
				break;
			
		}
		
	}
}

	void append()
	{
	struct node* new;
	{
		int n,i;
		printf("How many nodes you want to apend\n");
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			new=(struct node *)malloc(sizeof(struct node));
			printf("Enter node data\n");			
			scanf("%d",&new->data);
			new->next=NULL;
			if(head==NULL)
			{
				head=tail=new;
			}
			else
			{
				tail->next=new;
				tail=new;
				tail->next=head;
			}
		}
	}
	}
	void addatbegin()
	{
		struct node * temp;
		temp=(struct node*)malloc(sizeof(struct node));
		printf("Enter the value of new node\n");
		scanf("%d",&(temp->data));
		temp->next=NULL;
		temp->next=head;
		tail->next=temp;
		head=temp;
	}

	void addinbetween()
	{
		struct node *temp,*p;
		int len,pos,i=1;
		printf("Enter the position at which you want to insert the newnode\n");
		scanf("%d",&pos);
			
		len=length();
		if(pos>len)	
			printf("Error\n");
		else
		{
			p=head;
			while(i<pos-1)
			{
				p=p->next;
				i++;
			}
		temp=(struct node *)malloc(sizeof(struct node));
		printf("Enter the data of new node\n");
		scanf("%d",&(temp->data));
		
		temp->next=NULL;
		temp->next=p->next;
		p->next=temp;
		}
	}

	int length()
	{
		int cnt=0;
		struct node *p;
		p=head;
		do{
			cnt++;	
			p=p->next;
		}while(p->next!=head->next);
		return cnt;
	}

	void display()
	{
		struct node *temp;
		temp=head;
		if(temp==0)
		{
			printf("List is empty\n");
		}
		else
		{
			do{
				printf("Elements=%d\n",temp->data);
				temp=temp->next;
		}while(temp->next!=head->next);
		printf("\n\n");
		}
	}
	
	void delete()
	{
		int i;
		struct node *q=NULL,*r=NULL;
		q=head;
		int pos;
		printf("Enter the position at which you want to delete\n");
		scanf("%d",&pos);
		if(pos==1)
		{
			head=head->next;
		}
		else
		{
			r=head;
			for(i=1;i<pos-1;i++)
			{
				r=r->next;
			}			
				q=r->next;
				r->next=q->next;	
		}		
		printf("Deleted element is %d\n",q->data);
		q->next=NULL;
		free(q);
	
	}
	

	void search()
	{
		int s,t,i=0,pos;
		struct node *a=head,*b=head;
		
		
			printf("Enter a value you want to search\n");
			scanf("%d",&t);
			do
			{
				i++;
			if(t==a->data)
			{
				printf("\n");
				printf("\nValue %d is at position %d\n",a->data,i);
				printf("\n");
			
			}	

			a=a->next;		
			}while(a!=b);
	}	






















	




	

