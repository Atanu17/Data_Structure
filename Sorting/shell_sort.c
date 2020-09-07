#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *a,n,i,span=0,j,k,t,flag;
	printf("\nEnter the limit of array");
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));
	printf("\nEnter the elements of the array");
	for(i=0;i<n;i++)
	  scanf("%d",a+i); 
	printf("\n The Array Elements before sorting:");
	for(i=0;i<n;i++)
	printf(" %d",a[i]);
	span=n;
	while(span>1)
	{
		flag=0;
		span=(span+1)/2;
		for(j=span;j<n;j++)
		{
			t=a[j];
			k=j-span;
			while(k>=0 && t<a[k])
			{
				a[k+span]=a[k];
				k=k-span;
			}
			a[k+span]=t;
			
		}
	}
	printf("\n The Array Elements after sorting:");
	for(i=0;i<n;i++)
	printf(" %d",a[i]);
	return 0;
}
