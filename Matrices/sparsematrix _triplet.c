#include<stdio.h>
#include<stdlib.h>
struct triplet
{
	int i,j,val;
};

int main()
{
	struct triplet *a,*b,*c;
	int n,n1,k,ind1=1,ind2=1,x,y=0;
	printf("\nEnter no. of non-zero numbers in the matrix 1:");
	scanf("%d",&n);
    a=(struct triplet*)malloc(sizeof(struct triplet)*(n+1));
    printf("\nEnter the no. of rows of matrix 1:");
    scanf("%d",&a[0].i);
    printf("\nEnter the no. of columns of matrix 1:");
    scanf("%d",&a[0].j);
    a[0].val=n;
    printf("\nEnter no. of non-zero numbers in the matrix 2:");
	scanf("%d",&n1);
    b=(struct triplet*)malloc(sizeof(struct triplet)*(n1+1));
    y=n+n1+1;
    c=(struct triplet*)malloc(sizeof(struct triplet)*y);
    printf("\nEnter the no. of rows of matrix 2:");
    scanf("%d",&b[0].i);
    printf("\nEnter the no. of columns of matrix 2:");
    scanf("%d",&b[0].j);
    b[0].val=n1;
    printf("\nEnter the non-zero numbers of matrix 1 with their index:");
    for(k=1;k<(n+1);k++)
    {
	    printf("\nINDEX i\tINDEX j\tVALUE\n");
	    scanf("%d%d%d",&a[k].i,&a[k].j,&a[k].val);
    }
    printf("\nEnter the non-zero numbers of matrix 2 with their index:");
    for(k=1;k<(n1+1);k++)
    {
	    printf("\nINDEX i\tINDEX j\tVALUE\n");
	    scanf("%d%d%d",&b[k].i,&b[k].j,&b[k].val);
    }
    printf("\nSparse representation of matrix 1:\n");
    printf("\nINDEX i\tINDEX j\tVALUE\n");
    for(k=0;k<(n+1);k++)
    	printf("\n%d\t%d\t%d",a[k].i,a[k].j,a[k].val);
    printf("\nSparse representation of matrix 2:\n");
    printf("\nINDEX i\tINDEX j\tVALUE\n");
    for(k=0;k<(n1+1);k++)
    	printf("\n%d\t%d\t%d",b[k].i,b[k].j,b[k].val);
    c[0].i=a[0].i;
    c[0].j=a[0].j;
    int ind3=1,f=0;
    while(ind1<=a[0].val && ind2<=b[0].val)
	{
		if(a[ind1].i<b[ind2].i)
		{
			c[ind3].i=a[ind1].i;
			c[ind3].j=a[ind1].j;
			c[ind3++].val=a[ind1++].val;
			f++;
			
		}
		else if(a[ind1].i==b[ind2].i)
		{
			if(a[ind1].j<b[ind2].j)
			{
				c[ind3].i=a[ind1].i;
			    c[ind3].j=a[ind1].j;
			    c[ind3++].val=a[ind1++].val;
			    f++;
			}
			else if(a[ind1].j>b[ind2].j)
			{
				c[ind3].i=b[ind2].i;
			    c[ind3].j=b[ind2].j;
			    c[ind3++].val=b[ind2++].val;
                 f++;
			}
			else
			{
				c[ind3].i=a[ind1].i;
			    c[ind3].j=a[ind1].j;
			    if(a[ind1].val+b[ind2].val!=0)
			    {
			    	c[ind3++].val=a[ind1++].val+b[ind2++].val;
                	f++;
                }
                else
                {
                	ind1++;
                	ind2++;
				}
			}
		}
		else
		{
				c[ind3].i=b[ind2].i;
			    c[ind3].j=b[ind2].j;
			    c[ind3++].val=b[ind2++].val;
			    f++;
		}
	}	
	
	
	if(ind1>a[0].val)
	{
		for(x=ind2;x<=b[0].val;x++)
		{
				c[ind3].i=b[x].i;
			    c[ind3].j=b[x].j;
			    c[ind3++].val=b[x].val;
			    f++;

		}
	}
	else
	{
		for(x=ind1;x<=a[0].val;x++)
		{
				c[ind3].i=a[x].i;
			    c[ind3].j=a[x].j;
			    c[ind3++].val=a[x].val;
			    f++;
		}
	
	}
	c[0].val=f;
    printf("\nSparse representation of  matrix 3:\n");
    printf("\nINDEX i\tINDEX j\tVALUE\n");
    for(k=0;k<ind3;k++)
    	printf("\n%d\t%d\t%d",c[k].i,c[k].j,c[k].val);
    return 0;	
}
