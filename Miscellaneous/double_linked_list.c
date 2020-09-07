#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *llink;
	struct node *rlink;
}*start,*temp,*ptr;

void insert_first()
{
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\n\t Enter the data: ");
	scanf("%d",&temp->data);
	temp->llink=NULL;
	temp->rlink=NULL;
	
	if(start==NULL)
	  start=temp;
	else
	{
		temp->rlink=start;
		start->llink=temp;
		start=temp;
	}
}
void insert_last()
{
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\n\t Enter the data: ");
	scanf("%d",&temp->data);
	temp->llink=NULL;
	temp->rlink=NULL;
	
	if(start==NULL)
	  start=temp;
	else
	{
		ptr=start;
		while(ptr->rlink!=NULL)
		  ptr=ptr->rlink;
		  
		temp->llink=ptr;
		ptr->rlink=temp;
	
	}
}

void delete_first()
{
		if(start==NULL)
		 printf("\n\t Nothing to delete \n");
		else
		{
		  printf("\nDeleted %d",start->data);
		  start=start->rlink;
		  start->llink=NULL;
		}
}
void delete_last()
{
	if(start==NULL)
	 printf("\n\t Can Not Delete\n");
	else if(start->rlink==NULL)
	{
		printf("\nDeleted %d",start->data);
	 	start=NULL;
	 }
	else
	{
	   ptr=start;
	   while(ptr->rlink->rlink!=NULL)	
	    ptr=ptr->rlink;
	    
	 printf("\nDeleted %d",ptr->rlink->data);
	 ptr->rlink=NULL;
	 
	}
}
void display()
{
	ptr=start;
	while(ptr!=NULL)
	{
	  printf("\n\t %d",ptr->data);
	  ptr=ptr->rlink;
    }
}
main()
{
	int n;
	start=NULL;
	do
	{
		printf("\n\t Press 1: For insert_first");
		printf("\n\t Press 2: For insert_last");
		printf("\n\t Press 3: For delete_first");
		printf("\n\t Press 4: For delete_last");
		printf("\n\t Press 5: For display");
		printf("\n\t Press 6: For exit");
		printf("\n\n\t Enter Your Choice: ");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				insert_first();
				display();
				break;
			case 2:
				insert_last();
				display();
				break;
			case 3:
				delete_first();
				display();
				break;
			case 4:
				delete_last();
			case 5:
				display();
				break;
			case 6:
				break;
			default :
				printf("\n\t Wrong Choice\n");
		}
	}while(n!=6);
	
}

