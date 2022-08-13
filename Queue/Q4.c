#include<stdio.h>
#include<stdlib.h>
struct queue
{
	int data;
	struct queue *next;
};
struct queue *rear=NULL;
struct queue *front=NULL;
int cnt;



	int add(int n)	
	{
		
		struct queue *temp;
		temp=(struct queue *)malloc(sizeof(struct queue));
		if(rear==NULL && front==NULL)
		{
			temp->data=n;
			front=rear=temp;
			temp->next=front;
		}
		else
		{
			temp->data=n;
			rear->next=temp;
			rear=temp;
		}
		cnt++;
	}


	int delete()
	{
		struct queue *temp=front;
		if(front==NULL)
			printf("LOLLL\n");
		else
		{
			front=front->next;
			free(temp);
		}
		cnt--;
	}
	
	int isempty()
	{
		if(front==NULL)
			printf("Empty\n");
		else
			printf("Not empty\n");
	}
	
	void display()
	{
		
		struct queue *temp=front;
		printf("Queue contents are:\n");
		while(temp)
		{
			printf("%d\n",temp->data);
			temp=temp->next;
		}
	}


	
	void main()
	{
		int ch,x;
		

			struct queue *list=NULL;
			
		do
		{
			printf("1 Insert\n2 Delete\n3 Display\n4 Peek\n");
			scanf("%d",&ch);
			
			switch(ch)		
			{
				case 1: printf("Enter element to be inserted\n");
					scanf("%d",&x);
					add(x);
				
					break;
			
				case 2: if(front==NULL)
						printf("Queue is empty\n");
					else
					{
						delete();
						
					}
					break;
					
				case 3: display();
					break;

				case 4: if(front==NULL)
						printf("No elements present in queue\n");
					else
						printf("Element present at the top = %d\n",front->data);
			}
		}while(ch>0&&ch<5);
	}
	
