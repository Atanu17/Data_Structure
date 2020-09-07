#include<stdio.h>
#define MAX 20

int row,col,count;//global declaration

void sparse_matrix(int [MAX][MAX]);//function prototype

main()
{
	int a[MAX][MAX],t,total,i,j;
	printf("Enter row of the matrix: ");
	scanf("%d",&row);
	printf("\nEnter column of the matrix: ");
	scanf("%d",&col);
	total=row*col;
	t=total/3;
	printf("\nEnter the elements of the matrix: \n");
	/*to take input elements of the matrix*/
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("\nEnter The Element a%d%d: ",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}
	/*to print the input matrix*/
	printf("\nThe Input Matrix is:\n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf(" %d ",a[i][j]);
		}
		printf("\n");
	}
	/*for counting total number of non-zero elements*/
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(a[i][j]!=0)
			   count++;
	 }
	}
	if(count>t)
	  printf("\nSparse matrix is not possible!!");
	else
	{
		printf("\nSparse matrix is possible\n\n");
		sparse_matrix(a);//function call
	}
}

void sparse_matrix(int x[MAX][MAX])//function body
{
	int i,j;
	printf("\nThe Sparse Matrix is: \n\n");
	/*to display the sparse matrix*/
	printf("%d\t%d\t%d",row,col,count);
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(x[i][j]!=0)
			{
				printf("\n%d\t%d\t%d",i,j,x[i][j]);
			}
		}
	}
}

