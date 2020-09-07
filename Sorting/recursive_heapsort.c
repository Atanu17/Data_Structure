#include<stdio.h>
void swap(int *p, int *q)
{
	int t;
	t=*p;
	*p=*q;
	*q=t;
}
void heapify(int arr[], int n, int i)
{
	int largest,left,right;
	largest=i;
	left=2*i+1;
	right=2*i+2;
	if(left<n && arr[left]>arr[largest])
	 largest=left;
	if(right<n && arr[right]>arr[largest])
	 largest=right;
	 
	if(largest!=i)
	{
		swap(&arr[i], &arr[largest]);
		heapify(arr,n,largest);
	}
	 	
}
void heapsort(int arr[], int n)
{
	int i;
	for(i=n/2-1;i>=0;i--)
	 heapify(arr,n,i);
	 
	for(i=n-1;i>=0;i--)
	{
		swap(&arr[0],&arr[i]);
		heapify(arr,i,0);
	}
}
void main()
{
	int a[100],n,i;
	printf("Enter the order ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("Enter the number ");
		scanf("%d",&a[i]);
	}
	
	heapsort(a,n);
	printf("\n After sorting \n");
	for(i=0;i<n;i++)
	{
		printf(" %d",a[i]);
	}
	
}
