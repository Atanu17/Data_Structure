#include<stdio.h>
#include<stdlib.h>
float determinant(int **a,int r,int c)
{
	int i,j,k;
	float ratio,s=1.0;
	for(i=0;i<r-1;i++)
	{
		for(j=i+1;j<r;j++)
		{
			ratio=a[j][i]/a[i][i];
			for(k=0;k<r;k++)
			{
				a[j][k]=a[j][k]-(ratio*a[i][k]);
			}
		}
	}
	for(i=0;i<r;i++)
	s=s*a[i][i];
	return s;
}
int main()
{
	int **a,r,c,i,j,ch,flag=0,**b,**c1,r2=0,c2=0,k,s1,min,max,p,q,m,n;
	float s=0.0;
	printf("\nNo.of rows:");
	scanf("%d",&r);
	printf("\nNo.of columns:");
	scanf("%d",&c);
	while(r<=0)
	{
		printf("Value of no.of rows cannot be zero.Re-Enter the value");
	    scanf("%d",&r);  
	}
	while(r<=0)
	{
		printf("Value of no.of columns cannot be zero.Re-Enter the value");
	    scanf("%d",&c);
	}
	a=(int**)malloc(sizeof(int*)*r);
	for(i=0;i<r;i++)
	a[i]=(int*)malloc(sizeof(int)*c);
	printf("\nEnter the elements:");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		scanf("%d",(*(a+i)+j));
	}
	printf("\nOriginal matrix:\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		printf("%d ",*(*(a+i)+j));
		printf("\n");
	}
	do
	{
		printf("\n1.For Matrix Multiplication");
		printf("\n2.For determinant");
		printf("\n3.For symmetry checking");
		printf("\n4.For Saddle point");
		printf("\n5.For exit");
		printf("\nEnter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the no. of rows and coloumns of the 2nd matrix");
	            scanf("%d%d",&r2,&c2);
			    b=(int**)malloc(sizeof(int*)*r2);
				for(i=0;i<r2;i++)
				b[i]=(int*)malloc(sizeof(int)*c2);
				printf("\nEnter the elements:");
				for(i=0;i<r2;i++)
				{
					for(j=0;j<c2;j++)
					scanf("%d",(*(b+i)+j));
				}
				c1=(int**)malloc(sizeof(int*)*r);
				for(i=0;i<r;i++)
				c1[i]=(int*)malloc(sizeof(int)*c2);
				printf("\nOriginal matrix 1:\n");
				for(i=0;i<r;i++)
				{
					for(j=0;j<c;j++)
					printf("%d ",*(*(a+i)+j));
					printf("\n");
				}
				printf("\nOriginal matrix 2:\n");
				for(i=0;i<r2;i++)
				{
					for(j=0;j<c2;j++)
					printf("%d ",*(*(b+i)+j));
					printf("\n");
				}
				if(r2==c)
				{
					for(i=0;i<r;i++)
					{
						for(j=0;j<c2;j++)
						{
							s1=0;
							for(k=0;k<c;k++)
							s1=s1+a[i][k]*b[k][j];
							c1[i][j]=s1;
						}		
					}
					printf(" The Product of the Matrix\n");
				    for(i=0;i<r;i++)
				    {
				    	for(j=0;j<c2;j++)
				    	{
				    		printf("\t%d",c1[i][j]);
						}
						printf("\n");
					}
				}
				else
				    printf("\nMatrix Multplication is not possible");
				break;
			case 2:
				if(r!=c)
	            {
		            printf("Value of no.of rows and no.of columns cannot be different.");
					break;  
	            }
	            s=determinant(a,r,c);
	            printf("\nDeterminant of the matrix is:%f",s);
				break;
			case 3:
				for(i=0;i<r;i++)
				{
					for(j=0;j<c;j++)
					{
						if(*(*(a+i)+j)!=*(*(a+j)+i))
						{
							flag=1;
							break;
						}
					}
					if(flag==1)
					break;
				}
				if(flag==0)
				printf("\nMatrix is symmetric");
				else
				printf("\nMatrix is not symmetric");
				break;
				case 4:
					for(i=0;i<r;i++)
					{
						min=a[i][0];
						for(j=0;j<c;j++)
						{
							if(a[i][j]<=min)
							{
								min=a[i][j];
								p=i;
								q=j;
							}
						}
						j=q;
						max=a[0][j];
						for(k=0;k<r;k++)
						{
							if(a[k][j]>=max)
							{
								max=a[k][j];
								m=k;
								n=j;
							}
						}
						if(min==max)
						{
							if(p==m && q==n)
							{
								printf("\nThe saddle point of the matrix:%d",max);
							}
						}
					}
					break;
				case 5:
					break;
				default:
					printf("\nWrong choice!Re-Enter your choice");
		}
	}while(ch!=5);
	free(a);
	a=NULL;
	return 0;
}
