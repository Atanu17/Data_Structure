#include<stdlib.h>
struct triplet
{
	int i,j,val;
};
struct triplet *a,*b,*c;
int main()
{
	int n,n1,k;
	printf("\nEnter no of non zero numbers in the matrix 1:");
	scanf("%d",&n);
    a=(struct triplet*)malloc(sizeof(struct triplet)*(n+1));
    printf("\nEnter the no of rows of matrix 1:");
    scanf("%d",&a[0].i);
    printf("\nEnter the no of columns of matrix 1:");
    scanf("%d",&a[0].j);
    a[0].val=n;
    printf("\nEnter no of non zero numbers in the matrix 2:");
	scanf("%d",&n1);
    b=(struct triplet*)malloc(sizeof(struct triplet)*(n1+1));
    printf("\nEnter the no of rows of matrix 2:");
    scanf("%d",&b[0].i);
    printf("\nEnter the no of columns of matrix 2:");
    scanf("%d",&b[0].j);
    b[0].val=n1;
    printf("\nEnter the non zero numbers of matrix 1:");
    for(k=1;k<(n+1);k++)
    {
	    printf("\nINDEX i\tINDEX j\tVALUE\n");
	    scanf("%d%d%d",&a[k].i,&a[k].j,&a[k].val);
    }
    printf("\nEnter the non zero numbers of matrix 2:");
    for(k=1;k<(n1+1);k++)
    {
	    printf("\nINDEX i\tINDEX j\tVALUE\n");
	    scanf("%d%d%d",&b[k].i,&b[k].j,&b[k].val);
    }
    printf("\nNo of non zero numbers in matrix 1:\n");
    printf("\nINDEX i\tINDEX j\tVALUE\n");
    for(k=0;k<(n+1);k++)
    	printf("\n%d\t%d\t%d",a[k].i,a[k].j,a[k].val);
    printf("\nNo of non zero numbers in matrix 2:\n");
    printf("\nINDEX i\tINDEX j\tVALUE\n");
    for(k=0;k<(n1+1);k++)
    	printf("\n%d\t%d\t%d",b[k].i,b[k].j,b[k].val);
}
