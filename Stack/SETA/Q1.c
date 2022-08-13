#include<stdio.h>         //Program of stack by static implementation
#define MAX 20
int n;
struct stack
{
	int data[MAX];
	int top;
};

	void init(struct stack *s)
	{
		s->top=-1;
	}

	int isempty(struct stack *s)	
	{
		if(s->top==-1)
			return 1;
		else
			return 0;
	}

	int isfull(struct stack *s)
	{
		if(s->top==MAX-1)
			return 1;
		else
			return 0;
	}

	void push(struct stack *s,int item)
	{
		s->data[++s->top]=item;
	}

	int pop(struct stack *s)
	{
		return(s->data[s->top--]);
	}

	void display(struct stack *s)
	{
		int i=0;
		
		for(i=0;i<=s->top;i++)
		{
			printf("%d\n",s->data[i]);
		}
		printf("\n");
	}
	
	void peek(struct stack *s)
	{
		printf("Element=%d\n",s->data[s->top]);
	}
	
	void main()
	{
		struct stack s1 ;
		int ch;
		init(&s1);
		do{
			printf("1 Push\n2 Pop\n3 Display\n4 Peek\n");
			printf("Enter your choice\n");
			scanf("%d",&ch);
	
			switch(ch)
			{
				case 1: if(isfull(&s1))
						printf("Stack is full\n");
					else
					{
						printf("Enter element to be push into stack\n");
						scanf("%d",&n);
						push(&s1,n);
					}
					break;
	
				case 2: if(isempty(&s1))
						printf("Stack is empty\n");
					else
						printf("Popped element is %d\n",pop(&s1));
					break;

				case 3: display(&s1);

					break;
		
				case 4: peek(&s1);
					break;

				case 5: printf("The program has been terminated\n");
					break;
			}

		}while(ch>0&&ch<5);
	}
 
