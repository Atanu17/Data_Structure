#include<stdio.h>
#include<stdlib.h>
#define max 100
int isEmpty(int s[],int top )
{
	if(top==-1)
		return 1;
	return 0;	
}
void push(int s[],int item,int *top)
{
	if(*top==max-1)
	{
		printf("\nOVERFLOW\n");
		return;
	}
	else
	{
		*top=*top+1;
		s[*top]=item;
		return;
	}
}

int pop(int s[],int *top)
{
   if(*top==-1)
   {
   	    printf("\nUNDERFLOW\n");
   	    return -99999;
   }	
   else
   {
   	    int item=s[*top];
   	    *top=*top-1;
   	    return item;
   }
}
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
void quicksort(int a[],int n)
{
	int s[max],top=-1,u,l,p;
	if(n<=1)
	 return;
	push(s,0,&top);
	push(s,n,&top);
	while(!isEmpty(s,top))
	{
		u=pop(s,&top);
		l=pop(s,&top);
		p=partition(a,l,u);
		if((p-l)>1)
		{
			push(s,l,&top);
			push(s,p-1,&top);
		}
		if((u-p)>1)
		{
			push(s,p+1,&top);
			push(s,u,&top);
		}
	}
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
	quicksort(a,n-1);
	printf("\nElements after sorting:");
	for(i=0;i<n;i++)
		printf("%d ",*(a+i));
	return 0;
}
