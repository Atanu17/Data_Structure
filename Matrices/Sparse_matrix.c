#include<stdio.h>
#include<stdlib.h>
int main()
{
	int **a,m,n,i,j,k,ind,**b;
	printf("\nEnter the number of rows and coluumns of the matrix");
	scanf("%d%d",&m,&n);
	a=(int**)malloc(sizeof(int*)*m);
	for(i=0;i<m;i++)
	  a[i]=(int*)malloc(n*sizeof(int));
	printf("\nEnter the elements of the matrix");
	for(i=0;i<m;i++)
	{
	   for(j=0;j<n;j++)
	   {
	   	  scanf("%d",(*(a+i)+j));
	   }	
	}
	printf("\nOriginal Matrix:\n");
	for(i=0;i<m;i++)
	{
	   for(j=0;j<n;j++)
	   {
	   		if(a[i][j]==0)
	   		    k++;
	   	  printf("%d ",*(*(a+i)+j));
	   }
	   printf("\n");	
	} 
	int f=(m*n)-k;
	if(((k/(float)(m*n))*100)>=66)
	{
	   printf("\nSparse Matrix\n");
	   b=(int**)malloc(sizeof(int*)*(f+1));
	   for(i=0;i<(f+1);i++)
	     b[i]=(int*)malloc(sizeof(int)*n);
	   b[0][0]=m;
	   b[0][1]=n;
	   b[0][2]=f;
	   ind=1;
	   for(i=0;i<m;i++)
		{
	   	for(j=0;j<n;j++)
	   	{
	   		if(a[i][j]!=0)
	   		{
	   			b[ind][0]=i;
	   			b[ind][1]=j;
	   			b[ind++][2]=a[i][j];
	   		}
	   	}
	   }
		for(i=0;i<(f+1);i++)
		{
		   for(j=0;j<3;j++)
		   	 printf("%d ",b[i][j]);
		   printf("\n");
	    }
		   
	}
	else
	    printf("\nNot Sparse Matrix");   
	
	return 0;
	 
}
