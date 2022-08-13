#include<stdio.h>
struct stack
{
	char data;
	int top;
}s;
void init(struct stack *s)
	{
		s->top=-1;
	}

void push(struct stack *s,int item)
	{
		s->data[++s->top]=item;
	}

int pop(struct stack *s)
	{
		return(s->data[s->top--]);
	}


int isempty(struct stack *s)	
	{
		if(s->top==-1)
			return 1;
		else
			return 0;
	}
void reverse(char str[20])
{
	struct stack s;
	int i;
	initstack(&s);
	for(i=0;i<strlen(str);i++)
		push(&s,str[i]);
	while(!isempty(&s))
		str[i]=pop(&s);
	printf("Reversed string is:\n");
	puts(str);
}
	
int main()
{
	char str;
	printf("Enter a string\n");
	scanf("%s",str);
	printf("Reversed string is:\n");
	reverse(&s);
}
