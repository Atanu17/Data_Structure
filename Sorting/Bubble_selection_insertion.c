#include<stdio.h>
#include<stdlib.h>
void insertion_sort(int *a,int n)
{
	int i,j,key;
	for(i=1;i<n;i++)
	{
		j=i-1;
		key=*(a+i);
	    while(j>=0 && key<*(a+j))
	    {
	    	*(a+j+1)=*(a+j);
	    	j=j-1;
		}
		*(a+j+1)=key;
	}
}
void selection_sort(int *a,int n)
{
	int min,i,j,t;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(*(a+j)<*(a+min))
				min=j;
			
	    }
	    t=a[i];
	    a[i]=a[min];
	    a[min]=t;
	    
	}
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

int main()
{
	int *a;
	int n,i,ch,key,p;
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
		printf("\n\t 1. Bubble Sort \n\t 2.Insertion Sort \n\t 3. Selection Sort \n\t 4.Exit");
		printf("\nEnter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				bubble_sort(a,n);
				printf("\nThe elements after sorting  are :");	
 				for(i=0;i<n;i++)
					printf("%d ",*(a+i));
			    break;
			case 2:
				insertion_sort(a,n);
			    printf("\nThe elements after sorting  are :");	
				for(i=0;i<n;i++)
					printf("%d ",*(a+i));
			    break;
			case 3:
				selection_sort(a,n);
				printf("\nThe elements after sorting are :");	
				for(i=0;i<n;i++)
					printf("%d ",*(a+i));
				
			    break;
			case 4:
			     break;    
			default:
			    printf("\nEnter correct choice");			
		}
	}while(ch!=4);	
	return 0;		
}



