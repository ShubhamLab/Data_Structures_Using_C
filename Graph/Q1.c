
#include<stdio.h>
int a[10][10],n,i,j;
int main()
{
	void display(int m[10][10],int n);
	void in_out_degree(int m[10][10],int n);
	
	printf("Enter Number of Vertices \n");
	scanf("%d",&n);
	printf("Enter the Edges in an matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			a[i][i]=0;
			if(i!=j)
			{
				printf("Is there an edge between %d and %d\n",i+1,j+1);
					scanf("%d",&a[i][j]);
			}
		}
	}
	display(a,n);
	in_out_degree(a,n);
}
 void display(int m[10][10],int n)
{
		printf("Display The Adjacency Matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d \t",m[i][j]);
		}
			printf("\n");
	}


}

void in_out_degree(int m[10][10],int n)
{
	int insum=0,outsum=0,v;
	for(v=0;v<n;v++)
{
	insum=0,outsum=0;

	for(j=0;j<n;j++)
{
	insum=insum+m[v][j];
}
	
	for(i=0;i<n;i++)
{
	outsum=outsum+m[v][i];
}
	printf("Indegree of vertex %d is %d\n ",v+1,insum);
	printf("Outdegree of vertex %d is %d\n ",v+1,outsum);

}
}
