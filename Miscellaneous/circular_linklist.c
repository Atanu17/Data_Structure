#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct linklist
{
	int data;
	struct linklist *link;
}node;
node *start,*temp,*ptr;
void insertFirst()
{
	temp=(node*)malloc(sizeof(node));
	printf("Enter the data ");
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
		 ptr=ptr->link;
		 
		ptr->link=temp;
		temp->link=start;
		start=temp;
		
	}
}
void insertLast()
{
	temp=(node*)malloc(sizeof(node));
	printf("Enter the data ");
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
		 ptr=ptr->link;
		 
		ptr->link=temp;
		temp->link=start;
		
	}
}
void deleteFirst()
{
	if(start==NULL)
	 printf("\n Nothing to Dispplay");
	else if(start->link==start)
	{
		printf("\n Deleted %d",start->data);
		start=NULL;
	}
	else
	{
		printf("\n Deleted %d",start->data);
		
		ptr=start;
		while(ptr->link!=start)
			ptr=ptr->link;
		
		start=start->link;
		ptr->link=start;
	
	}
}
void deleteLast()
{
	if(start==NULL)
	 printf("\n Nothing to Dispplay");
	else if(start->link==start)
	{
		printf("\n Deleted %d",start->data);
		start=NULL;
	}
	else
	{
		
		
		ptr=start;
		while(ptr->link->link!=start)
			ptr=ptr->link;
			
		printf("\n Deleted %d",ptr->link->data);
		
		ptr->link=start;
	
	}
}
void searchInsert()
{
	int num,f=0;
	if(start==NULL)
	 printf("\n Nothing to Dispplay");
	else
	{
		printf("\n Enter the search data ");
		scanf("%d",&num);
		
		
		ptr=start;
		while(ptr->link!=start)
		{
			if(ptr->data==num)
			{
				temp=(node*)malloc(sizeof(node));
				printf("Enter the data ");
				scanf("%d",&temp->data);
				temp->link=NULL;
				
				temp->link=ptr->link;
				ptr->link=temp;
				f=1;
				break;
	
			}
			ptr=ptr->link;
		}
		if(f==0 && ptr->data==num)	
		{
				temp=(node*)malloc(sizeof(node));
				printf("Enter the data ");
				scanf("%d",&temp->data);
				temp->link=NULL;
				
				ptr->link=temp;
				temp->link=start;
		}
		else
		 printf("\n Element not present");

	}
}
void searchDelete()
{
	int num,f=0;
	if(start==NULL)
	 printf("\n Nothing to Dispplay");
	else
	{
		printf("\n Enter the search data ");
		scanf("%d",&num);
		
		if(start->data==num)
		{
			ptr=start;
			while(ptr->link!=start)
			 ptr=ptr->link;
			 
			
			start=start->link;
			ptr->link=start;
			f=1;
		}
		else
		{
		ptr=start;
		node *pptr=start;
		while(ptr->link!=start)
		{
			if(ptr->data==num)
			{
				pptr->link=ptr->link;
				f=1;
				break;
	
			}
			pptr=ptr;
			ptr=ptr->link;
		}
		if(f==0 && ptr->data==num)	
		{
			pptr->link=start;
		}
		else
		 printf("\n Element not present");
      }
	}
}

void display()
{
	if(start==NULL)
	 printf("\n Nothing to Dispplay");
	else
	{
		ptr=start;
		while(ptr->link!=start)
		{
			printf("\n %d",ptr->data);
			ptr=ptr->link;
		}
		printf("\n %d",ptr->data);
	}
}
void main()
{
	int ch;
	start=NULL;
	while(1)
	{
		printf("\n\n 1 for Insert First ");
		printf("\n 2 for Insert :Last ");
		printf("\n 3 for Delete First ");
		printf("\n 4 for Delete Last ");
		printf("\n 5 for Search Insert ");
		printf("\n 6 for Search Delete ");
		printf("\n 7 for Display");
		printf("\n 8 for Exit ");
		printf("\n\nEnter the choice ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
			insertFirst();
			display();
			break;
			
			case 2:
			insertLast();
			display();
			break;
			
			case 3:
			deleteFirst();
			display();
			break;
			
			case 4:
		    deleteLast();
			display();
			break;
			
			case 5:
		    searchInsert();
			display();
			break;
	
			case 6:
		    searchDelete();
			display();
			break	;
					
			case 7:
			display();
			break;
			
			case 8:
			printf("\n Thank You ");
			exit(1);
				
		}
	}// end of while
}// end of main
