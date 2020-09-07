#include<stdio.h>
#include<stdlib.h>
typedef struct linklist
{
  int data;
  struct linklist *link;	
}node;
node *start,*ptr,*temp;
void insert_first()
{
	temp=(node*)malloc(sizeof(node));
	printf("\n Enter the data ");
	scanf("%d",&temp->data);
	temp->link=NULL;
	
	if(start==NULL)
	{
		start=temp;
		temp->link=start;
	}
	else
	{
		ptr=start;
		while(ptr->link!=start)
		{
			ptr=ptr->link;
		}
		
		ptr->link=temp;
		temp->link=start;
		start=temp;
	}	
}
void insert_last()
{
	temp=(node*)malloc(sizeof(node));
	printf("\n Enter the data ");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(start==NULL)
	{
		start=temp;
		temp->link=start;
	}
	else
	{
	ptr=start;
	while(ptr->link!=start)
	{
		ptr=ptr->link;
	}
	temp->link=start;
	ptr->link=temp;
    }
}

void delete_first()
{
	if(start==NULL)
		printf("\n NO ELEMENT PRESENT");
	else if(start->link==start)
	{
    	printf("\n Deleted ELEMENT--->%d",start->link);
		start=NULL;
    } 
	ptr=start;
	while(ptr->link!=start)
		ptr=ptr->link;
		
	start=start->link;
	ptr->link=start;

}
void delete_last()
{
	if(start==NULL)
		printf("\n LIST IS EMPTY");
	else if(start->link==start)
	{
		printf("\n DELETED ELEMENT---->%d",start->data);
		start=NULL;
	}
	else
	{
		ptr=start;
		while(ptr->link->link!=start)
			ptr=ptr->link;
			
		ptr->link=NULL;
		ptr->link=start;
	}
}
void display()
{ 
	if(start==NULL)
	 printf("\n List is empty");
	else
	{
		ptr=start;
		while(ptr->link!=start)
		{
			printf("\n %d",ptr->data);
			ptr=ptr->link; // move to the next node
		}
		printf("\n %d",ptr->data);
	}
}


int main()
{
	int ch;
	start=NULL;// initialize
	while(1)
	{
	 printf("\n 1.INSERT LAST \n");
	 printf("\n 2.INSERT FIRST \n");
	 printf("\n 3.DELETE LAST \n");
	 printf("\n 4.DELETE FIRST\n");
	 printf("\n 8.DISPLAY \n");
	 printf("\n 9.EXIT \n");
	 printf("\n CHOICE: \n");
	 scanf("%d",&ch);
	 switch(ch)
	 {
		case 1:
	    insert_last();
		break;
		case 2:
	    insert_first();
		break;
		case 3:
	    delete_last();
		break;
		case 4:
		delete_first();
		break;
		case 8:
		display();
		break;
		case 9:
		exit(0);	
		default:
		printf("\n WRONG CHOICE \n");
	 }
  }
  return 0;
}
