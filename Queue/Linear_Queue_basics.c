#include<stdio.h>
#include<stdlib.h>
#define max 5
int front;//global variable
int rear;//global variable
void insert(int q[])
{
	int num;
	if(rear==(max-1))
	   printf("\n Queue overflow\n");
	else
	{
		printf("\nEnter a number \n");
		scanf("%d",&num);
		if(rear==-1)//if there are no elements in queue
		{
			rear=0;
			front=0;
			q[rear]=num;
		}
		else
		q[++rear]=num;
		printf("\n Number inserted  \n");
    }  
}
void Delete(int q[])
{
	if (front==-1)
	   printf("\nQueue underflow \n");
	else
	{
		printf("\n Deleted element %d",q[front]);
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
		  front++;
    }   
} 
void display(int q[])
{
	int i;
	if(front==-1)
	    printf("\nQueue underflow \n");
	else
	{
		printf("\n The elements of the queue are as follows \n");
		for(i=front;i<=rear;i++)
		   printf("%d ",q[i]);
	}    
}
int main()
{
	int ch,q[max];
	front=-1;
	rear=-1;
	while(1)
	{
	 printf("\n 1.INSERT \n");
	 printf("\n 2.DELETE \n");
	 printf("\n 3.DISPLAY \n");
	 printf("\n 4.EXIT \n");
	 printf("\n CHOICE: \n");
	 scanf("%d",&ch);
	 switch(ch)
	 {
		case 1:
	    insert(q);
		break;
		case 2:
		Delete(q);
		break;
		case 3:
		display(q);
		break;
		case 4:
		exit(0);	
		default:
		printf("\n WRONG CHOICE \n");
	 }
  }
  return 0;
}
