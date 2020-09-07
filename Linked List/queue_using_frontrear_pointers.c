#include<stdio.h>
#include<stdlib.h>
typedef struct linklist
{
	int data;
	struct linklist *link;
}node;
node *front,*rear,*temp;
void Insert()
{
	temp=(node*)malloc(sizeof(node));
	printf("Enter the number ");
	scanf("%d",&temp->data);
	temp->link=NULL;
	
	if(rear==NULL)
	{
		front=temp;
		rear=temp;
	}
	else
	{
		rear->link=temp;
		rear=temp;
	}
}
void Delete()
{
	if(front==NULL)
	   printf("\nUNDERFLOW");
	else if(front==rear)
	{
		printf("\nDELETED ELEMENT %d",front->data);
		front=NULL;
		rear=NULL;
	}
	else
	{
		printf("\nDELETED ELEMENT %d",front->data);
		front=front->link;
	}
}
void display()
{
	node *p=front;
	while(p!=NULL)
	{
		printf("\n%d",p->data);
		p=p->link;
	}
}
int main()
{
	int ch;
	while(1)
	{
	printf("\n1.INSERT");
	printf("\n2.DELETE");
	printf("\n3.DISPLAY");
	printf("\n4.EXIT");
	printf("\nEnter your choice");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
	    Insert();
		break;
		case 2:
		Delete();
		break;
		case 3:
		display();
		break;
		case 4:
		exit(0);	
		default:
		printf("\n WRONG CHOICE \n");
	  }
    }
  return 0;
}
