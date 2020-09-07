// implementation of queue using ARRAY
#include<stdio.h>
#define MAX 5

int queue[MAX];// global variable
int front,rear;// pointer

void Insert()
{
	int num;
	if(rear==MAX-1)
	 printf("\n\tO V E R F L O W\n");
	else
	{
		printf("\n\tEnter the data ");
		scanf("%d",&num);
		if(rear==-1)
		{
			front=0;
			rear=0;
			queue[rear]=num;
		}
		else
		queue[++rear]=num;// place the number
	}
}

void Delete()
{
	if(front==-1)
	 printf("\n\tU N D E R F L O W\n");
	else
	{
		printf("\n\tDeleted %d",queue[front]);
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
		 front++;
	}
}

void display()
{
	int i;
	if(front==-1)
	 printf("\n\tQueue is Empty\n");
	else
	{
		for(i=front;i<=rear;i++)
		 printf("\n\t%d",queue[i]);
		printf("\n\n");
	}
}

main()
{
	int n;
	front=-1;//initialize
	rear=-1;
	do
	{	
	  printf("\n\tPress 1: For Insert");
	  printf("\n\tPress 2: For Delete");
	  printf("\n\tPress 3: For Display");
	  printf("\n\tPress 4: For Exit");
	  printf("\n\n\tEnter your Choice: ");
	  scanf("%d",&n);
    switch(n)
    {
    	case 1: 
		  Insert();
    	  display();
    	  break;
    	  
    	case 2:
    	    Delete();
    		
    	case 3:
    		display();
    		break;
    		
    	case 4:break;
    	default:
    		printf("\n\tWrong Choice\n");
	}
  }while(n!=4);
}
