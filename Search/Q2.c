#include<stdio.h>			//Binary search
int binary(int[],int,int);
int main()
{
	int a[10],key,c,n,pos=0,i;
	printf("Enter number of elements in an array\n");
	scanf("%d",&n);
	printf("Enter numbers\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter the number to search\n");
	scanf("%d",&key);
	pos=binary(a,key,n);
	
	if(pos==-1)
		printf("%d is not present in array\n",key);
	else
		printf("%d is present at location %d\n",key,pos+1);
	return 0;
}

	int binary(int a[],int key,int n)
	{	
		int mid,high,low=0;
		high=n-1;
		while(high>=low)
		{
			mid=(low+high)/2;
			if(key<a[mid])
				high=mid-1;
			else if(key>a[mid])
				low=mid+1;
			else if(key==a[mid])
				return mid;
			
	
		}

		return -1;

	}
