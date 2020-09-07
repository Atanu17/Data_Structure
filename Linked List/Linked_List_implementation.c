//Linked List Implementation
//implement queue using linklist
#include<stdio.h>
#include<stdlib.h>
typedef struct linklist
{
	int data;
	struct linklist *link;// self reference
}node;

node *start, *ptr, *temp,*pptr;
void insert_first()// insert_first
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
void insert_last()// insert_last
{
	temp=(node*)malloc(sizeof(node));
	printf("Enter the data ");
	scanf("%d",&temp->data);// as it is structure pointer so it use -> instread of .
	temp->link=NULL;
	
	if(start==NULL)
	 start=temp;
	else
	{
		ptr=start;
		while(ptr->link!=NULL)
		{
			ptr=ptr->link;
		}
		ptr->link=temp;
	}
	
}
void Delete_first()
{
	if(start==NULL)
	 printf("\n U N D E R F L O W");
	else
	{
		printf("\n Deleted %d",start->data);
		start=start->link;
	}
}
void Delete_last()
{
	if(start==NULL)
	   printf("\n NO ELEMENT PRESENT");
	else if(start->link==NULL)
	    start=NULL;
	else
	{
		ptr=start;
		while(ptr->link->link!=NULL)
		{
			ptr=ptr->link;
		}
		ptr->link=NULL;
	}	   
}
void search()
{
	int num;
	
	if(start==NULL)
	   printf("\n No element present");
	else
	{
		printf("\n Enter a number");
		scanf("%d",&num);
		
	    ptr=start;
	    while(ptr!=NULL)
	    {
			if(ptr->data==num)
			 {
				printf("\nNumber present");
				break;
			}
		
			ptr=ptr->link;
		}
		if(ptr==NULL)
		  printf("\n Number not present");
		    	
	}   
}
void search_insert()
{
	int num;
	if(start==NULL)
	printf("\n No Element Present");
	else
	{
		printf("\n Enter a number ");
		scanf("%d",&num);
		ptr=start;
		while(ptr!=NULL)
		{
			if (ptr->data==num)
			{
				temp=(node*)malloc(sizeof(node));
				printf("\nEnter the data ");
				scanf("%d",&temp->data);
				temp->link=NULL;
				int ch2;
				printf("\n Press 1 for Before Insert ");
				printf("\n Press 2 for After Insert ");
				printf("Enter your choice");
				scanf("%d",&ch2);
				if(ch2==1)
				{
					if(start->data==num)// or -call insert_first()
					{
						temp->link=start;
						start=temp;
					}
					else
					{
						temp->link=pptr->link;
						pptr->link=temp;
					}  
				}
				else if(ch2==2)
				{
					temp->link=ptr->link;
					ptr->link=temp;
				}
				else
				{
					printf("\n Wrong choice ")	;
				}
				
				break;
	    	}
	    	pptr=ptr;
	    	ptr=ptr->link;
	    }
	    if(ptr==NULL)
	       printf("\nElement not present");
	}
}
void search_Delete()
{
	int num;
	if(start==NULL)
	 printf("\n List is Empty");
	else
	{
		printf("Enter the search number ");
		scanf("%d",&num);
		if(start->data==num)// number present at first node
		 start=start->link;// or call Delete_First();
		else
		{
			ptr=start;
			while(ptr!=NULL)
			{
				if(ptr->link->data==num)
				 {
				 	ptr->link=ptr->link->link;
				 	break;
				 }
				 ptr=ptr->link;
			}
			if(ptr==NULL)
			 printf("\nItem Not Present ");
				 
		 }// end of inner else
		
	}// end of outer else
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
	 printf("\n 1.INSERT LAST \n");
	 printf("\n 2.INSERT FIRST \n");
	 printf("\n 3.DELETE LAST \n");
	 printf("\n 4.DELETE FIRST\n");
	 printf("\n 5.SEARCH ELEMENT \n");
	 printf("\n 6.SEARCH INSERT \n");
	 printf("\n 7.SEARCH DELETE \n");
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
	    Delete_last();
		break;
		case 4:
		Delete_first();
		break;
		case 5:
		search();
		break;	
		case 6:
		search_insert();
		break;	
		case 7:
		search_Delete();
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
