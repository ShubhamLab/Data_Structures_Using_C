#include<stdio.h>			//implementation of queue statically
#define MAX 5
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
		if(q->front==q->rear)
			return 1;
		else
			return 0;
	}

	int isfull(struct queue *q)
	{
		if(q->rear==MAX-1)
			return 1;
		else
			return 0;
	}

	void insert(struct queue *q,int n)
	{
		q->data[++(q->rear)]=n;
	}

	int delete(struct queue *q)
	{
		return (q->data[++(q->front)]);
	}

	void display(struct queue *q)
	{
		int i;
		printf("Queue contents are:\n");
	
		for(i=q->front+1;i<=q->rear;i++)
			printf("%d\n",q->data[i]);
	}

	void peek(struct queue *q)
	{
		printf("Element present at top=%d\n",q->data[q->front+1]);
	}


	void main()
	{
		struct queue q1;
		int ch,n;
		init(&q1);
		do
		{
			printf("1 Insert\n2 Delete\n3 Display\n4 Peek\n");	
			printf("Enter your choice\n");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1: if(isfull(&q1))
						printf("Queue is full\n");
					else
					{
						printf("Enter element to be inserted\n");
						scanf("%d",&n);
						insert(&q1,n);

					}
					break;

				case 2: if(isempty(&q1))
						printf("Queue is empty\n");
					 else
					 {
						printf("Deleted element is %d\n",delete(&q1));

					 }
					 break;

				case 3: display(&q1);
					break;

				case 4: peek(&q1);
					break;
			}
		}while(ch>0&&ch<4);
	}
	
