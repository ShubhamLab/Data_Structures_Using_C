#include<stdio.h>		//Merge Sort
void disp();
void merge(int,int,int);
void sort(int,int);
int a[50],n;

void main()
{
	int i;
	printf("Enter the value of n\n");
	scanf("%d",&n);
	printf("Enter the elements for an array:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Before sorting the elements are:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	sort(0,n-1);
	printf("After sorting the elements are:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
}


	void merge(int low,int mid,int high)
	{
		int t[50],i,j,k;
		i=low;
		j=mid+1;
		k=low;
		while((i<=mid)&&(j<=high))
		{
			if(a[i]>=a[j])
				t[k++]=a[j++];
			else
				t[k++]=a[i++];
		}
	
		while(i<=mid)
		{
			t[k++]=a[i++];
		}

		while(j<=high)
		{
			t[k++]=a[j++];
		}

		for(i=low;i<=high;i++)
		{
			a[i]=t[i];
		}
	}



	void sort(int low,int high)
	{
		int mid;
		if(low!=high)
		{
			mid=((low+high)/2);
			sort(low,mid);
			sort(mid+1,high);
			merge(low,mid,high);
		}
	}
