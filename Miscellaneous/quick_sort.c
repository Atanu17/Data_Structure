#include<stdio.h>
void quick_sort(int [],int,int);//function prototype
int n;//global declaration
main() 
{
	int i,a[20];
	printf("\nTotal number of elements: ");
	scanf("%d",&n);
	printf("\nEnter %d elements: ",n);
	for(i=0;i<n;i++)
	  scanf("%d",&a[i]);
	  quick_sort(a,0,n-1);//function call
	printf("\nAfter arranging the numbers: \n");
	for(i=0;i<n;i++)
	  printf(" %d",a[i]);
}
void quick_sort(int x[],int f,int l)
{
	int i,j,temp,p;
	if(f<l)
	{
		p=x[f];
		i=f;
		j=l;
		while(i<=j)
		{
			while(p>=x[i] && i<=j)
			 i++;
			 
			while(p<x[j]) 
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
		
		quick_sort(x,f,j-1);
		quick_sort(x,j+1,l);		
	}

}
