#include<stdio.h>
#include<stdlib.h>
void swap(float **p,float **q)
{
	float *t;
	t=*p;
	*p=*q;
	*q=t;
}


float determinant(float **a,int r,int c)
{
	int i,j,k;
	float ratio,s=1.0;
	for(i=0;i<r-1;i++)
	{
		for(j=i+1;j<r;j++)
		{
			if(a[i][i]==0)
			{
				swap(&a[i],&a[i+1]);
			}
			ratio=a[j][i]/a[i][i];
			for(k=0;k<r;k++)
			{
				a[j][k]=a[j][k]-(ratio*a[i][k]);
			}
		}
	}
	for(i=0;i<r;i++)
	s=s*a[i][i];
	if(s==-0)
	  return 0;
	else 
	return s;  
}
int main()
{
	int r,c,i,j,ch,flag=0,r2=0,c2=0,k,min,max,p,q,m,n,f=0;
	float s=0.0,**a,**a1,**b,**c1,s1;
	printf("\nNo.of rows:");
	scanf("%d",&r);
	printf("\nNo.of columns:");
	scanf("%d",&c);
	while(r<=0)
	{
		printf("Value of no.of rows cannot be zero.Re-Enter the value");
	    scanf("%d",&r);  
	}
	while(c<=0)
	{
		printf("Value of no.of columns cannot be zero.Re-Enter the value");
	    scanf("%d",&c);
	}
	a=(float**)malloc(sizeof(float*)*r);
	for(i=0;i<r;i++)
	a[i]=(float*)malloc(sizeof(float)*c);
	printf("\nEnter the elements:");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		scanf("%f",(*(a+i)+j));
	}
	printf("\nOriginal matrix:\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		printf("%0.2f ",*(*(a+i)+j));
		printf("\n");
	}
	a1=(float**)malloc(sizeof(float*)*r);
	for(i=0;i<r;i++)
	a1[i]=(float*)malloc(sizeof(float)*c);
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			a1[i][j]=a[i][j];
	}
	do
	{
		printf("\n1.For Matrix Multiplication");
		printf("\n2.For determinant");
		printf("\n3.For Saddle point");
		printf("\n4.For symmetry checking");
		printf("\n5.For exit");
		printf("\nEnter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the no. of rows and coloumns of the 2nd matrix");
	            scanf("%d%d",&r2,&c2);
			    b=(float**)malloc(sizeof(float*)*r2);
				for(i=0;i<r2;i++)
				b[i]=(float*)malloc(sizeof(float)*c2);
				printf("\nEnter the elements:");
				for(i=0;i<r2;i++)
				{
					for(j=0;j<c2;j++)
					scanf("%f",(*(b+i)+j));
				}
				c1=(float**)malloc(sizeof(float*)*r);
				for(i=0;i<r;i++)
				c1[i]=(float*)malloc(sizeof(float)*c2);
				printf("\nOriginal matrix 1:\n");
				for(i=0;i<r;i++)
				{
					for(j=0;j<c;j++)
					printf("%0.2f ",*(*(a1+i)+j));
					printf("\n");
				}
				printf("\nOriginal matrix 2:\n");
				for(i=0;i<r2;i++)
				{
					for(j=0;j<c2;j++)
					printf("%0.2f ",*(*(b+i)+j));
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
							s1=s1+a1[i][k]*b[k][j];
							c1[i][j]=s1;
						}		
					}
					printf(" The Product of the Matrix\n");
				    for(i=0;i<r;i++)
				    {
				    	for(j=0;j<c2;j++)
				    	{
				    		printf("\t%0.2f",c1[i][j]);
						}
						printf("\n");
					}
				}
				else
				    printf("\n Matrix Multplication is not possible since number of coloumns of first matrix is not equal to the number of rows of the second matrix");
				break;
			case 2:
				if(r!=c)
	            {
		            printf("Value of no.of rows and no.of columns cannot be different.");
					break;  
	            }
	            s=determinant(a,r,c);
	            printf("\nDeterminant of the matrix is:%0.2f",s);
				break;
			case 4:
				for(i=0;i<r;i++)
				{
					for(j=0;j<c;j++)
					{
						if(*(*(a1+i)+j)!=*(*(a1+j)+i))
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
				case 3:
					for(i=0;i<r;i++)
					{
						min=a1[i][0];
						p=0;
						for(j=0;j<c;j++)
						{
							if(a1[i][j]<=min)
							{
								min=a1[i][j];
								p=j;
							}
						}
						
						max=a1[0][p];
						for(k=0;k<r;k++)
						{
							if(a1[k][p]>=max)
							{
								max=a1[k][p];
								m=k;
								n=p;
							}
						}
						if(min==max)
						{
							f=1;
							break;
						}
					}
					if(f==1)
						printf("\nThe saddle point of the matrix is:%d at index [%d,%d]",max,m+1,n+1);	
					else
							printf("\nThere is no saddle point ");
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

