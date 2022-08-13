#include<stdio.h>		//BFS
#include<stdlib.h>
struct q
{
	int data[20];
	int front,rear;
}q1;

struct node
{
	int vertex;
	struct node *next;
}*v[10];

void add(int n)
{
	q1.rear++;
	q1.data[q1.rear]=n;
}

int del()
{
	q1.front++;
	return (q1.data[q1.front]);
}

void ini()
{
	q1.front=q1.rear=-1;
}

int empty()
{
	return (q1.rear==q1.front);
}

void create(int m[10][10],int n)
{
	int i,j;
	char ans;
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
		{
			printf("%5d",m[i][j]);
		}
		printf("\n");
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

void  displayl(int n)
{
	struct node *temp;
	int i;
	for(i=0;i<n;i++)
	{
		printf("v%d\n",i+1);
		temp=v[i];
		while(temp)
		{
			printf("v%d->",temp->vertex);
			temp=temp->next;
		}
	}
}

void bfs(int m[10][10],int n)
{
	int i,j,v,w;
	int visited[20];
	ini();
	for(i=0;i<n;i++)
		visited[i]=0;
	printf("The BFS traversal is:\n");
	v=0;
	visited[v]=1;
	add(v);
	while(!empty())
	{
		v=del();
		
		printf("\n");
		for(w=0;w<n;w++)
		{
			if((m[v][w]==1)&&(visited[w]==0))
			{
				add(w);
				visited[w]=1;
			}
		}
	}
}

int main()
{
	int m[10][10],n;
	printf("Enter number of vertices\n");
	scanf("%d",&n);
	create(m,n);
	display(m,n);
	createl(m,n);
	displayl(n);
	bfs(m,n);
}
