#include<stdio.h>
#include<stdlib.h>
int partition(int x[],int f,int l)
{
	int i,j,temp,p;
		p=x[f];
		i=f;
		j=l;
		while(i<=j)
		{
			while(x[i]<=p && i<=j)
			 i++;
			while(x[j]>p) 
			  j--;
			  
			  if(i<j)
			  {
			  	temp=x[i];
			  	x[i]=x[j];
			  	x[j]=temp;
			  }
		}
		temp=x[f];
		x[f]=x[j];
		x[j]=temp;
		return j;
}
void quicksort(int a[],int f,int l)
{
	int p;
	if((l-f+1)<=1)
		return;
	p=partition(a,f,l);
	quicksort(a,f,p-1);
	quicksort(a,p+1,l);	
}
int main()
{
	int *a,n,i;
	printf("\nEnter the number of elements");
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));
	printf("\nEnter the numbers");
	for(i=0;i<n;i++)
		scanf("%d",(a+i));
	quicksort(a,0,n-1);
	printf("\nElements after sorting:");
	for(i=0;i<n;i++)
		printf("%d ",*(a+i));
	return 0;
}
