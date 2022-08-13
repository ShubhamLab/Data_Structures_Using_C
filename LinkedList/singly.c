#include<stdio.h>   //menu driven program for singly linked list
#include<stdlib.h>
 struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL,*next=NULL;
int len;
void apppend(void);
void addatbegin(void);
void addinbetween(void);
int length(void);
void display(void);
void delete(void);
void search(void);
void reverse(void);

	

int main()
{
	int ch,len;
	while(1)
	{
		printf("Following ae the operations\n");
		printf("1 Append and create\n");
		printf("2 Add at begining\n");
		printf("3 Add in between\n");
		printf("4 Length of list\n");
		printf("5 Display the string\n");
		printf("6 Delete by position\n");	
		printf("7 Search\n");
		printf("8 Reverse\n");

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
			
			case 8: reverse();
				break;			
				
		}
		
	}
}

	void append()
	{
		struct node *temp,*p=NULL,*next=NULL;
		int n,i;
		printf("How many nodes you want to enter\n");
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
		temp=(struct node*)malloc(sizeof(struct node));
		printf("Enter node data\n");
		scanf("%d",&(temp->data));
		
		temp->next=NULL;
		if(head==NULL)
		{
			head=temp;
		}
		else
		{
			struct node *p;
			p=head;
			while(p->next!=NULL)
			{
				p=p->next;
			}
			p->next=temp;
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
		struct node *temp;
		temp=head;
		if(temp==NULL)
		{
			printf("Linked list is empty\n");
		}
		else
		{
			while(temp!=NULL)
			{
				printf("\n\n\n");
				printf("Linked list is %d\n",temp->data);
				temp=temp->next;
			}
		}	
		printf("\n\n\n");
	}	

	void delete()	
	{	
	
		int i,pos;
		struct node *temp=NULL,*q=NULL;
		temp=head;
		printf("Enter the position\n");
		scanf("%d",&pos);
		if(pos==1)
			head=head->next;
		else
		{
			q=head;
			for(i=1;i<pos-1;i++)
				q=q->next;
			temp=q->next;
			q->next=temp->next;
		}
	printf("Deleted element is %d\n",temp->data);
	temp->next=NULL;
	return head;
	
	

	}
		
	void search()
	{
		int s,t,i=0,pos;
		printf("Search:\n1 By value\n2 By position\n");
		scanf("%d",&s);
		if(s==1)
		{
			printf("Enter a value you want to search\n");
			scanf("%d",&t);
			while(head!=NULL)
			{
				i++;
			if(head->data==t)
			{
				printf("\nValue %d is at position %d\n",head->data,i);
			}
			head=head->next;
			}
		}

		if(s==2)
		{
			printf("Enter a position you want to search(1-%d)\n",length);
			scanf("%d",&pos);	
			for(i=0;i<pos;i++)
			{
				head=head->next;
			}
			printf("At position %d, the value is %d\n",i,head->data);
		}

	}

	void reverse()
	{
		int i,j,k,len,temp;
		struct node *p,*q;
		p=head;
		len=length();
		i=0;
		j=len-1;
		p=q=head;
		while(i<j)
		{
			k=0;
			while(k<j)
			{
				q=q->next;
				k++;
			}
		temp=p->data;
		p->data=q->data;	
		q->data=temp;
		i++;
		j--;
		p=p->next;
		q=head;
		}
	}
















	

