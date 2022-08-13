#include<stdio.h>			//Linear search
int linear(int[],int,int);
int main()
{
	int a[10],key,c,n,pos,i,find;
	printf("Enter number of elements in an array\n");
	scanf("%d",&n);
	printf("Enter %d elements\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter the number to search\n");
	scanf("%d",&key);
	pos=linear(a,n,key);
	
	if(pos==-1)
		printf("%d is not present in array\n",key);
	else
		printf("%d is present at location %d\n",key,pos+1);
	return 0;
}

	int linear(int a[],int n,int key)
	{
		int i;
		for(i=0;i<n;i++)
		{
			if(a[i]==key)
				return i;
		}

		return 1;
	}
