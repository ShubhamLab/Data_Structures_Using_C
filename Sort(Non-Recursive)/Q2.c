
#include<stdio.h>		//Insertion Sort
#define MAX 20
void insert(int A[MAX],int n);
void main()
{
	int A[MAX],i,n;
	printf("How many elements you want to sort\n");
	scanf("%d",&n);
	printf("Enter the elements into an array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	
	insert(A,n);
	
	printf("Elements after sorting are:\t");
	for(i=0;i<n;i++)
	{
		printf("%d\t",A[i]);
	}
}

	void insert(int A[MAX],int n)
	{
		int i,j,key;
		for(i=1;i<n;i++)	
		{
			key=A[i];
			for(j=i-1;(j>=0)&&(key<A[j]);j--)
			{
				A[j+1]=A[j];
			}

			A[j+1]=key;
		}
	}
