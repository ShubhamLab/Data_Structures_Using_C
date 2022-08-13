#include<stdio.h>
#define MAX 10
struct queue
{
	int data[MAX];
	int front,rear;
};
	
	void init(struct queue *q)
	{
		q->front=q->rear=-1;
	}

	int isempty(struct queue *q)
	{
		return (q->front==-1);
	}

	int isfull(struct queue *q)
	{
		if((q->front==0&&q->rear==MAX-1)||(q->front==q->rear+1))
			return 1;
		else
			return 0;
	}

	void insert(struct queue *q,int x)
	{
		if(q->front==-1)
			q->front=q->rear=0;
		else
		{
			if(q->rear==MAX-1)
				q->rear=0;
			else
				q->rear++;
		}
		q->data[q->rear]=x;
	}

	int delete(struct queue *q)
	{
		int x=q->data[q->front];
		if(q->front==q->rear)
			q->front=q->rear=-1;
		else
		{
			if(q->front==MAX-1)
				q->front=0;
			else
				q->front++;
		}
	}

	void display(struct queue *q)
	{
		int i,j;
		i=q->front;
		j=q->rear;
		printf("Queue contents are:\t");
		if(i<=j)
		{
			while(i<=j)
				printf("%d\t",q->data[i++]);
		}
		else
		{
			while(i<=MAX-1)
				printf("%d\t",q->data[i++]);
		

		i=0;
		
		while(i<=j)
			printf("%d\t",q->data[i++]);
		}
	}


	void peek(struct queue *q)
	{
		printf("Element present at the top is %d\n",q->data[q->front]);
	}
	void main()
	{
		struct queue q;
		int ch,x;
		init(&q);
		do
		{
			printf("1 Insert\n2 Delete\n3 Display\n4 Peek\n");
			printf("Enter your choice\n");
			scanf("%d",&ch);

			switch(ch)
			{
				case 1: if(isfull(&q))
						printf("Queue is full\n");
					else
					{
						printf("Enter the element\n");
						scanf("%d",&x);
						insert(&q,x);
					}
					break;
			
				case 2: if(isempty(&q))
						printf("Queue is empty\n");
					else
					{
						delete(&q);
						
					}

					break;
	
				case 3: display(&q);
					break;
	
				case 4: peek(&q);
					break;

				}
			}while(ch>0&&ch<5);
		}
