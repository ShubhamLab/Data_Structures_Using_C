#include<stdio.h>              //program to convert  inflix to postfix expression
#include<ctype.h>
struct stack
{
	char data[20];
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

	void push(struct stack *s,char n)
	{
		s->top++;
		s->data[s->top]=n;
	}

	char pop(struct stack *s)
	{
		if(s->top==-1)
			return -1;
		else
			return s->data[s->top--];
	}

	int priority(char n)
	{
		if(n=='(')
			return 0;
		else if(n=='+'||n=='-')
			return 1;
		else if(n=='*'||n=='/')
			return 2;
		else if(n=='^'||n=='$')
			return 3;
		else
			return -1;
	}

	int main()
	{
		struct stack s1;
		char exp[20],n;
		int i;
		init(&s1);
		printf("Enter the infix expression:\n");
		scanf("%s",exp);
		i=0;
		while(exp[i]!='\0')
		{
			if(isalnum(exp[i]))
				printf("%c",exp[i]);
			else if(exp[i]=='(')
				push(&s1,exp[i]);
			else if(exp[i]==')')
			{
				while((n=pop(&s1))!='(')
					printf("%c",n);
			}
			else
			{
				while(priority(s1.data[s1.top])>=priority(exp[i]))
					printf("%c",pop(&s1));
				push(&s1,exp[i]);
			}
			i++;
		}
	
		while(!isempty(&s1))
		{
			
			printf("%c",pop(&s1));
		}

		return 0;
	}
