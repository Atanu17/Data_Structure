#include<stdio.h>
#include<stdlib.h>
void sort(int [], int, int);
void merge(int [], int , int , int,int);
void main()
{
	int *a,n,i,num,k;
	printf("\nEnter the order ");
	scanf("%d",&n);
	a=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter No.");
		scanf("%d",&a[i]);
	}
	sort(a,0,n-1);
	printf("\n number after sort");
	for(i=0;i<n;i++)
	 printf(" %d",a[i]);
	
	
}
void sort(int a[], int l, int u)
{
	if((u-l+1)<=1)
		return;
	int m=(l+u)/2;
	sort(a,l,m);
	sort(a,m+1,u);
	merge(a,l,m,m+1,u);
		
}

void merge(int a[], int l1, int u1 , int l2,int u2)
{
	
	int p=l1,q=l2,r=0,k=0,i=l1,temp[100];
	while(p<=u1 && q<=u2)
	{
		if(a[p]<=a[q])
			temp[r++]=a[p++];
		else
			temp[r++]=a[q++];
	}
	while(p<=u1)
		temp[r++]=a[p++];
	while(q<=u2)
		temp[r++]=a[q++];
	while(k<r)	
		a[i++]=temp[k++];	
}
