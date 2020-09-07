//Heapsort
#include <stdio.h>
#include <stdlib.h>

void display( int* , int );
void heapify(int*,int);
void heapSort(int*,int);
void adjust(int*,int,int);

int main()
{
	printf("\nEnter the size of array\n");
	int n,i;
	scanf("%d", &n);
	int *a = (int*)malloc(sizeof(int)*n);
	printf("\nEnter the elements of the array\n");
	for(i=0;i<n;i++)
		scanf("%d",(a+i));
	printf("\nBefore heap sort: \n");
	display(a,n);
	
	heapSort(a,n);
	
	printf("\nAfter heap sort: \n");
	display(a,n);
	
	return 0;
}

void display(int *a, int n)
{
	int i;
	for (i = 0 ; i < n ; i++ )
	printf("[%d] ", *(a+i) );
	printf("\n");
}
                                            
void heapify(int* a, int n)
{
	int i;
	for( i=((n-1)/2); i>=0 ; i--)
	{
		adjust(a,i,n);
	}
}

void heapSort(int *a, int n)
{
	int temp,i;
	heapify(a,n);
	printf("\nAfter heapify");
	display(a,n);
	for(i = n-1 ; i>=1 ; i-- )
	{
		temp = a[i];
		a[i] = a[0];
		a[0] = temp;
		adjust(a,0,i);
	}
}

void adjust(int* a, int i , int n)
{
	int j = 2*i+1;
	int item  = a[i];
	while(j<n)
	{
		if(j<n-1 && a[j]<a[j+1])
			j = j+1;
		if(item>a[j])
			break;
		a[(j-1)/2] = a[j];
		j = 2*j+1;
	}
	
	a[(j-1)/2] = item ;
}
