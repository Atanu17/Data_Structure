#include<stdio.h>
#include<stdlib.h>
#define inf -99999
int main()
{
	int *a,n,i,k,x,num,c=1,b,t;
	printf("\nEnter the no. of elements");
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	a[i]=inf;
	do
	{
		printf("Enter the Number ");
		scanf("%d",&num);
		k=num%n;
		if(a[k]==inf)
		 a[k]=num;
		else // collision
		{
			b=1;
		 	while(1)			
		 	{			
				 t=(k+b*b)%n;
				 if(a[t]==inf)
				 {
				 	a[t]=num;
				 	break;
				 }
				 b++;
		     }
        }
        
        
        c++;
        if(c==n)
		 	printf("\n Array is Full");
		else
		 printf("\n Do you want to continue (1/0)");
        scanf("%d",&x);
    }while(x==1 && c!=n);
    for(i=0;i<n;i++)
    	 printf("%d ",a[i]);
}
