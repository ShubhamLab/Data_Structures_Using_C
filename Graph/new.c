//DFS
#include<stdio.h>
#define MAX 20
struct stack 
{
	int data[MAX];
	int top;
};
void dfs(int m[10][10],int n,struct stack *s);
void init(struct stack *s);
void push(struct stack *s,int ele);
int pop(struct stack *s);
void init(struct stack *s)
{
	s->top=-1;
}
void push(struct stack *s,int ele)
{
	if(s->top!=MAX-1)
		s->data[++s->top]=ele;
	else
		printf("STACK is full\n");
} 
int pop(struct stack *s)
{
	if(s->top!=-1)
	{
		int n;
		n=s->data[s->top--];
		return n;
	}
	else
		printf("Stack is empty\n");
}
void main()
{
	struct stack *s;
	int m[10][10],n,i,j;
	printf("\nEnter the number of vertices\n");
	scanf("%i",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			m[i][i]=0;
			if(i!=j)
			{
				printf("\nIs there a edge between %d  and  %d\n",i+1,j+1);
				scanf("%d",&m[i][j]);
			}
		}
	printf("\n\tTHE AJACENCY MATRIX IS AS:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d\t",m[i][j]);
		printf("\n");
	}
	dfs(m,n,s);
}

void dfs(int m[10][10],int n,struct stack *s)
{
	
	int i,v,w,visited[31]={0};
	init(s);
	v=0;
	visited[v]=1;
	push(s,v);
	printf("\nV%d-->",v+1);
	
	while(1)
	{
		for(w=0;w<n;w++)
		{
			if((m[v][w]==1) && (visited[w]==0))
			{
				push(s,w);
				printf("V%d-->",w+1);
				visited[w]=1;
			}
		}
		if(s->top==-1)
			break;
		else
			v=pop(s);
	}
}
