#include<stdio.h>			//implementation of queue dynamically
#include<stdlib.h>
struct queue
{
	int data;
	struct queue *next;
}*front,*rear;

	void insert(int n)
	{
		struct queue *temp;
		temp=(struct queue *)malloc(sizeof(struct queue));
		temp->data=n;
		temp->next=NULL;
		if(front==NULL)
			rear=front=temp;
		else
		{
			rear->next=temp;
			rear=temp;
		}
	}

	int delete()
	{	
		int x;
		struct queue *temp=front;
		x=front->data;
		if(front==rear)
			front=rear=NULL;
		else
			front=front->next;
		free(temp);
		return(x);
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
		do
		{
			printf("1 Insert\n2 Delete\n3 Display\n4 Peek\n");
			scanf("%d",&ch);
			
			switch(ch)		
			{
				case 1: printf("Enter element to be inserted\n");
					scanf("%d",&x);
					insert(x);
					
					break;
			
				case 2: if(front==NULL)
						printf("Queue is empty\n");
					else
					{
						printf("Deleted element is %d\n",delete());
						
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
