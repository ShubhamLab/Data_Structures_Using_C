#include<stdio.h>		//Quick Sort
void quick(int [],int,int);
void main()
{
	int low,high,pivot,t,n,i,j,a[10];
	printf("How many elements you want to sort\n");
	scanf("%d",&n);
	printf("Enter elements for an array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}

	low=0;
	high=n-1;
	quick(a,low,high);
	printf("After sorting the elements are:\t");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
}

	void quick(int a[],int low,int high)
	{
		int pivot,t,i,j;
		if(low<high)
		{
			pivot=a[low];
			i=low+1;
			j=high;
			while(i<j)
			{
				while(pivot>=a[i]&&i<=high)
				{
					i++;
				}
				while(pivot<a[j]&&j>=low)
				{
					j--;
				}
				if(i<j)
				{
					t=a[i];
					a[i]=a[j];
					a[j]=t;
				}
			}
			a[low]=a[j];
			a[j]=pivot;
			quick(a,low,j-1);
			quick(a,j+1,high);
		}
	}
