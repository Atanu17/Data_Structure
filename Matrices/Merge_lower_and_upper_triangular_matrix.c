#include<stdio.h>
#include<stdlib.h>
int main()
{
	int **a,i,j,n,**b,**c;
	float s=0.0;
	printf("\nEnter the order of the matrices:");
	scanf("%d",&n);
	while(n<=0)
	{
		printf("Value of no.of columns cannot be zero. Re- Enter the value");
	    scanf("%d",&n);
	}
	a=(int**)malloc(sizeof(int*)*n);
	for(i=0;i<n;i++)
	  a[i]=(int*)malloc(sizeof(int)*n);

   	b=(int**)malloc(sizeof(int*)*n);
	for(i=0;i<n;i++)
	b[i]=(int*)malloc(sizeof(int)*n);
	printf("\nEnter the elements of the lower triangular matrix:");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		scanf("%d",(*(a+i)+j));
	}

	printf("\nEnter the elements of the upper triangular  matrix:");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		scanf("%d",(*(b+i)+j));
	}
	printf("\nFirst matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		printf("%d ",*(*(a+i)+j));
		printf("\n");
	}

	printf("\nSecond matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		printf("%d ",*(*(b+i)+j));
		printf("\n");
	}
	c=(int**)malloc(sizeof(int*)*n);
	for(i=0;i<n;i++)
	 c[i]=(int*)malloc(sizeof(int)*(n+1));
	for(i=0;i<n;i++)
	{
		for(j=0;j<n+1;j++)
		{
		
		    if(j<=i)
	           c[i][j]=a[i][j];  			
			else
				c[i][j]=b[i][j-1];
	    }
    }
    printf("\nMerged matrix:\n");
	for(i=0;i<n;i++)
	{
	    for(j=0;j<n+1;j++)
		  printf("%d ",*(*(c+i)+j));
		printf("\n");
	}
	return 0;
}

