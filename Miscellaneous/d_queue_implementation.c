#include<stdio.h>
#define MAX 5
int queue[MAX];
int front,rear;
void Insert_rear()
{
	int num;
	if(rear==MAX-1)
	  printf("\n\tO V E R F L O W\n");
	  else
	  {
	  	printf("\n\tEnter The Data: ");
	  	scanf("%d",&num);
	  	if(rear==-1)
	  	{
	  		front=0;
	  		rear=0;
	  		queue[rear]=num;
		}
		else
		 queue[++rear]=num;
	  }
}
void Delete_rear()
{
	if(rear==-1)
	 printf("\n\tU N D E R F L O W\n");
	else
	{
		printf("\n\t Deleted: %d",queue[rear]);
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
		 rear--;
	}
}

void Insert_front()
{
	int num;
	if(front==0)
	  printf("\n\tO V E R F L O W\n");
	  else
	  {
	  	printf("\n\tEnter The Data: ");
	  	scanf("%d",&num);
	  	if(rear==-1)
	  	{
	  		front=0;
	  		rear=0;
	  		queue[rear]=num;
		}
		else
		 queue[--front]=num;
	  }
}

void Delete_front()
{
	if(front==-1)
	 printf("\n\tU N D E R F L O W\n");
	else
	{
		printf("\n\t Deleted: %d",queue[front]);
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
		if(front<=rear)
		{
		for(i=front;i<=rear;i++)
		 printf("\n\t%d",queue[i]);
	    }
	    else
	    {
	    for(i=front;i<MAX;i++)
		 printf("\n\t%d",queue[i]);
		 
		for(i=0;i<=rear;i++)
		 printf("\n\t%d",queue[i]);
		}
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
	  printf("\n\tPress 1: For Insert_rear");
	  printf("\n\tPress 2: For Delete_rear");
	  printf("\n\tPress 3: For Insert_front");
	  printf("\n\tPress 4: For Delete_front");
	  printf("\n\tPress 5: For Display");
	  printf("\n\tPress 6: For Exit");
	  printf("\n\n\tEnter your Choice: ");
	  scanf("%d",&n);
    switch(n)
    {
    	case 1: 
		  Insert_rear();
    	  display();
    	  break;
    	  
    	case 2:
    	    Delete_rear();
    	    display();
    	    break;
    		
    	case 3:
    		Insert_front();
    		display();
    	    break;
    		
    	case 4:
    		Delete_front();
    	case 5: 
    	     display();
    	     break;
        case 6:break;
    	default:
    		printf("\n\tWrong Choice\n");
	}
  }while(n!=6);
}
