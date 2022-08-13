#include<stdio.h>		//DFS
#include<stdlib.h>
#define MAX 20
int n;
struct node
{
	int vertex;
	struct node *next;
}*v[10];

struct stack
{
	int data[MAX];
	int top;
};

void ini(struct stack *s)
{
	s->top=-1;
}

int empty(struct stack *s)
{
	if(s->top==-1)
		return 1;
	else
		return 0;
}

int full(struct stack *s)
{
	if(s->top==MAX-1)
		return 1;
	else
		return 0;
}

void push(struct stack *s,int n)
{
	s->data[++s->top]=n;
}

int pop(struct stack *s)
{
	return (s->data[s->top--]);
}

void create(int m[10][10],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	{
		m[i][j]=0;
		if(i!=j)
		{	
			printf("Is there an edge between %d and %d\n",i+1,j+1);
			scanf("%d",&m[i][j]);
		}
	}
}

void display(int m[10][10],int n)
{
	int i,j;
	printf("The adjacency matrix is:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%5d\n",m[i][j]);
	}
}

void createl(int m[10][10],int n)
{
	int i,j;
	struct node *temp,*newnode;
	for(i=0;i<n;i++)
	{
		v[i]=NULL;
		for(j=0;j<n;j++)
		{
			if(m[i][j]==1)
			{
				newnode=(struct node *)malloc(sizeof(struct node));			
				newnode->next=NULL;
				newnode->vertex=j+1;
				if(v[i]==NULL)
					v[i]=temp=newnode;
				else
				{
					temp->next=newnode;
					temp=newnode;
				}
			}
		}
	}
}

void displayl(int n)
{
	struct node *temp;
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d",i+1);
		temp=v[i];
		while(temp)
		{
			printf("v%d->\n",temp->vertex);
			temp=temp->next;
		}
	}
}

int visited[MAX]={0};

void dfs(int m[10][10],int i)
{
	int k;
	visited[i]=1;
	printf("The dfs of graph is:\n");
	printf("%d\n",i+1);
	for(k=0;k<n;k++)
		if(m[i][k]==1 && visited[k]==0)
			dfs(m,k);
}

int main()
{
	struct stack *s;
	int m[10][10];
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	create(m,n);	
	display(m,n);
	createl(m,n);
	displayl(n);
	dfs(m,0);
}
