//implement stack using linklist
#include<stdio.h>
#include<stdlib.h>
typedef struct linklist
{
	int data;
	struct linklist *link;// self reference
}node;

node *start, *ptr, *temp;

void push()// insert_first
{
	temp=(node*)malloc(sizeof(node));
	printf("Enter the data ");
	scanf("%d",&temp->data);// as it is structure pointer so it use -> instread of .
	temp->link=NULL;
	
	if(start==NULL)
	 start=temp;
	else
	{
		temp->link=start;
		start=temp;
	}
	
}
void pop()
{
	if(start==NULL)
	 printf("\n U N D E R F L O W");
	else
	{
		printf("\n Deleted %d",start->data);
		start=start->link;
	}
}

void display()
{
	if(start==NULL)
	 printf("\n List is empty");
	else
	{
		ptr=start;
		while(ptr!=NULL)
		{
			printf("\n %d",ptr->data);
			ptr=ptr->link; // move to the next node
		}
	}
}

int main()
{
	int ch;
	start=NULL;// initialize
	while(1)
	{
	 printf("\n 1.PUSH \n");
	 printf("\n 2.POP \n");
	 printf("\n 3.DISPLAY \n");
	 printf("\n 4.EXIT \n");
	 printf("\n CHOICE: \n");
	 scanf("%d",&ch);
	 switch(ch)
	 {
		case 1:
	    push();
		break;
		case 2:
		pop();
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

	

