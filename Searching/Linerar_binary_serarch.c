#include<stdio.h>
#include<stdlib.h>
int ls(int *a,int n,int key)
{
   a[n]=key;
   int i=0;
   while(key!=a[i])
    i=i+1;
   if(i<n)
     return i;
   else
   	  return -1;
}
void bubble_sort(int *a,int n)
{
	int flag,i,j;
	for(i=0;i<n-1;i++)
	{
		flag=0;
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				flag=1;
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
		if(flag==0)
		  break;
	}
}
int bs(int *a,int n,int key)
{
	int lb=0,ub=n-1,mid=(lb+ub)/2;
	while(lb<=ub && a[mid]!=key)
	{
		if(key>a[mid])
		   lb=mid+1;
		else
		   ub=mid-1;
		mid=(lb+ub)/2;      
	}
	if(a[mid]==key)
	  return mid;
	else
	   return -1;  
}
int main()
{
	int *a;
	int n,i,ch,key,f;
	printf("\nEnter the size :");
	scanf("%d",&n);
	while(n<=0)
	{
		printf("\nThe size cannot be 0 or negative.Re-enter the value of n. ");
		scanf("%d",&n);
	}
	a=(int*)malloc(n*sizeof(int));
	printf("\nEnter the elements");
	for(i=0;i<n;i++)
		scanf("%d",(a+i));
	printf("\nThe elements are :");	
	for(i=0;i<n;i++)
		printf("%d ",*(a+i));	
	do
	{
		printf("\n\t 1. Linear Search \n\t 2.Binary search \n\t 3. Exit");
		printf("\nEnter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the element to be searched");
                scanf("%d",&key);
                f=ls(a,n,key);
                if(f>=0)
                  printf("\n Element %d found at index %d",key,f+1);
                else
                  printf("\nelement not found");
			    break;
			case 2:
				bubble_sort(a,n);
				printf("\nThe array in sorted sequence is as follows :");
				for(i=0;i<n;i++)
				   printf("%d ",*(a+i));
				printf("\nEnter the element to be searched");
                scanf("%d",&key);  
				f=bs(a,n,key); 
				if(f>=0)
                  printf("\n Element %d found at index %d",key,f+1);
                else
                  printf("\nelement not found");
			    break;
			case 3:
			    break;
			default:
			    printf("\nEnter correct choice");			
		}
	}while(ch!=3);	
	return 0;		
}
