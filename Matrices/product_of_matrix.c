/* order of 1st matrix r1 c1
                         /  
   order of 2nd matrix r2 c2
   
   if r2=c1 then multiplication is possible
   
   size of new matrix is r1 c2 */
#include<stdio.h>
#include<stdlib.h>   
int main()
{
	int **a,**b,**c,r1=0,r2=0,c1=0,c2=0,i,j,k,s=0,num=0;
	printf("\nEnter the no. of rows and coloumns of the 1st matrix");
	scanf("%d%d",&r1,&c1);
	printf("\nEnter the no. of rows and coloumns of the 2nd matrix");
	scanf("%d%d",&r2,&c2);
  //  printf("\nEnter the elements of the 1st matrix");
    //int a[r1][c1],b[r2][c2],c[r1][c2];
    a=(int**)malloc(sizeof(int*)*r1);
	for(i=0;i<r1;i++)
	a[i]=(int*)malloc(sizeof(int)*c1);
    b=(int**)malloc(sizeof(int*)*r2);
	for(i=0;i<r2;i++)
	b[i]=(int*)malloc(sizeof(int)*c2);
    c=(int**)malloc(sizeof(int*)*r1);
	for(i=0;i<r1;i++)
	c[i]=(int*)malloc(sizeof(int)*c2);
	printf("\nEnter the elements of the 1st matrix");
    for(i=0;i<r1;i++)
    {
    	for(j=0;j<c1;j++)
    	{
    		scanf("%d",*(a+i)+j);
		}
	}
	printf("\nEnter the elements of the 2nd matrix");
    for(i=0;i<r2;i++)
    {
    	for(j=0;j<c2;j++)
    	{
    		scanf("%d",*(b+i)+j);
		}
	}
	
	
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c2;j++)
		{
			s=0;
			for(k=0;k<c1;k++)
			{
				int p=*(*(a+i)+k);
				int q=*(*(a+i)+k);
				s=s+p*q;
		    }
			c[i][j]=s;
		}
		
	}
	printf(" The 3rd Matrix\n");
    for(i=0;i<r1;i++)
    {
    	for(j=0;j<c2;j++)
    	{
    		printf("\t%d",c[i][j]);
		}
		printf("\n");
	}
  return 0;	
}
