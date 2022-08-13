#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 30
struct stack
{
        int data[MAX];
	int top;
};

	void init(struct stack *s)
	{
		s->top=-1;
	}

	void push(struct stack *s,int num)
	{
		s->data[++s->top]=num;
	}

	int pop(struct stack *s)
	{
		return (s->data[s->top--]);
	}

	void evaluate(struct stack *s,char op, int num1,int num2)
	{
		int ans;	
		switch(op)
		{
			case '+': ans=num1+num2;
				  break;
	
			case '-': ans=num1-num2;
				  break;
					
			case '*': ans=num1*num2;
				  break;

			case '/': ans=num1/num2;
				  break;

			/*case '^': 

			case '$': ans=pow(num1,num2);
				  break;*/
		}
		push(s,ans);
	}

	int gettype(char ch)
	{
		switch(ch)
		{
			case '+':
			case '-':
			case '*':
			case '/':
			case '$':
			case '^': return 1;
			default: return 0;
		}
	}

	void main()
	{
		char postfix[MAX];
		int num1,num2,element,i,ans;
		struct stack s;
		init(&s);
		printf("\nEnter postfix expression\n");
		scanf("%s",postfix);
		
		for(i=0;postfix[i]!='\0';i++)
		{
			switch(gettype(postfix[i]))
			{
				case 0: push(&s,postfix[i]-'0');
					break;
		
				case 1: num2=pop(&s);
					num1=pop(&s);
					evaluate(&s,postfix[i],num1,num2);
			}
		}
		
		printf("The answer of %s=%d",postfix,s.data[s.top]);
	} 
