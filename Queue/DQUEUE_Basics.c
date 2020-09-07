#include<stdio.h>
#include<stdlib.h>
#define max 5
int front;//global variable
int rear;//global variable
void insert_rear(int q[])
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
void Delete_front(int q[])
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
void insert_front(int q[])
{
	int num;
	if(front==0)
	   printf("\n Inserting from front is not possible \n");
	else
	{
		printf("\nEnter a number \n");
		scanf("%d",&num);
	
		if(front==-1)//if there are no elements in queue
		{
			rear=0;
			front=0;
			q[front]=num;
		}
		else
		q[--front]=num;
	}   
}
void delete_rear(int q[])
{
	if(rear==-1)
	   printf("Queue Underflow");
	else
	{
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
		  rear--;
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
	 printf("\n 1.INSERT FROM REAR \n");
	 printf("\n 2.DELETE FROM FRONT \n");
	 printf("\n 3.INSERT FROM FRONT \n");
	 printf("\n 4.DELETE FROM REAR \n");
	 printf("\n 5.DISPLAY \n");
	 printf("\n 6.EXIT \n");
	 printf("\n CHOICE: \n");
	 scanf("%d",&ch);
	 switch(ch)
	 {
		case 1:
	    insert_rear(q);
		break;
		case 2:
		Delete_front(q);
		break;
		case 3:
	    insert_front(q);
		break;
		case 4:
		delete_rear(q);
		break;
		case 5:
		display(q);
		break;
		case 6:
		exit(0);	
		default:
		printf("\n WRONG CHOICE \n");
	 }
  }
  return 0;
}
