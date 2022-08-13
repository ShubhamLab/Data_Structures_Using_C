#include<stdio.h>			//Bubble Sort
#define MAX 20
void bubble(int A[MAX],int n);
int display(int A[MAX],int n,int i);
void main()
{
	int A[MAX],n,i;
	printf("Enter the number of elements in the array:\n");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(i=0;i<n;i++)
	{
		printf("Array[%d]=",i);
		scanf("%d",&A[i]);
	}
	bubble(A,n);	
	display(A,n,i);
}

	void bubble(int A[MAX],int n)
	{
		int i,j,temp;
		for(i=0;i<n-1;i++)
		{
			for(j=0;j<n-1;j++)
			{
				if(A[j]>A[j+1])
				{
					temp=A[j];
					A[j]=A[j+1];
					A[j+1]=temp;
				}
			}
		}
	}

	int display(int A[MAX],int n,int i)
	{
		printf("Sorted array is:\n");
		for(i=0;i<n;i++)
		{
			printf("%d\t",A[i]);
		}
	}
