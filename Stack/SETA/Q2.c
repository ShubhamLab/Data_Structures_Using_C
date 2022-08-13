#include<stdio.h>        //program for stack dynamically
struct stack
{
	int data;
	struct stack *next;
}*top=NULL;

	void push(int n)
	{
		struct stack *newnode=NULL;
		newnode=(struct stack *)malloc(sizeof(struct stack));
		if(newnode==NULL)
			printf("Memory allocation failed\n");
		else
		{
			newnode->data=n;
			newnode->next=NULL;
			newnode->next=top;
			top=newnode;
		}

	}

	void pop()
	{
		struct stack *temp;
		if(top==NULL)
			printf("No element present\n");
		else
		{
			temp=top;
			printf("Popped element is %d\n",temp->data);
			top=top->next;
			free(temp);


		}


	}

	void display()
	{
		struct stack *temp;
		if(top==NULL)
			printf("Stack is empty\n");
		else
		{
			temp=top;
			while(temp!=NULL)
			{
				printf("Data is %d\n",temp->data);
				temp=temp->next;
			}
			free(temp);
		}
	}

	void peek()
	{	
		if(top==NULL)
			printf("No top element is present in the stack\n");
		else
			printf("Element present at the top is %d\n",top->data);

	}	




	void main()
	{

               
		int ch,n;
                do
                {
		printf("Enter the operations you want to perform\n");
		printf("1 Push\n2 Pop\n3 Display\n4 Peek\n");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: printf("Enter the data\n");
				scanf("%d",&n);
				push(n);
				break;
			
			case 2: pop();
				break;

			case 3: printf("Elements present in stack are\n");
				display();
				break;
	
			case 4: peek();
				break;
		}

		}while(ch!=4);
	}


	
