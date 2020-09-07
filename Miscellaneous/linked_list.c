#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
}*start,*temp,*ptr,*pptr;// global variable


void insert_first()
{
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\n\t Enter The Data: ");
	scanf("%d",&temp->data);
	temp->link=NULL;
	
	if(start==NULL)// when list is empty
	  start=temp;
	else
	{
		temp->link=start;
		start=temp;
	}
}


void insert_last()
{
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\n\t Enter The Data: ");
	scanf("%d",&temp->data);
	temp->link=NULL;
	
	if(start==NULL)// when list is empty
	  start=temp;
	else
	{
		ptr=start;
		while(ptr->link!=NULL)
		  ptr=ptr->link;
		  
		ptr->link=temp; // place the number at last
	}
}


void delete_first()
{
	if(start==NULL)
	  printf("\n\t Can Not Delete");
	else
	{
		printf("\n\t deleted %d",start->data);
		start=start->link;
	}
}


void delete_last()
{
	if(start==NULL)
	 printf("\n\t Can Not Delete");
	else if(start->link==NULL)
	{
		printf("\nDeleted %d",start->data);
	 	start=NULL;
	 }
	else
	{
	   ptr=start;
	   while(ptr->link->link!=NULL)	
	    ptr=ptr->link;
	    
	 printf("\nDeleted %d",ptr->link->data);
	 ptr->link=NULL;
	 
	}
}

void search()
{
	int t,f=0;
	if(start==NULL)
	 printf("\n\tList is Empty");
	else
	{
		printf("\n\t Enter the data You want to search: ");
		scanf("%d",&t);
		ptr=start;
		while(ptr->link!=NULL)
		{
			if(ptr->data==t)
			{
			   printf("\n\t Search is succsessful\n");
			   f=1;
			   break;
		    }
			ptr=ptr->link;
		}
		if(f==0)
		 printf("\n\t Search is unsuccsessful\n");
    }
}

void search_insert()
{
	int t;
	if(start==NULL)
	 printf("\n\tList is Empty");
	else
	{
		printf("\n\t Enter the data You want to search and Delete: ");
		scanf("%d",&t);
		ptr=start;
		while(ptr!=NULL)
		{
			if(ptr->data==t)
			{
			   printf("\n\t Search is succsessful\n");
			   break;
		    }
			ptr=ptr->link;
		}
		if(ptr==NULL)
		 printf("\n\t Search is unsuccsessful\n");
		else
		 {
		 	temp=(struct node*)malloc(sizeof(struct node));
			printf("\n\t Enter The Data You Want to Insert: ");
			scanf("%d",&temp->data);
			temp->link=NULL;
			
			temp->link=ptr->link;
			ptr->link=temp;
		 }
    }
}

void search_delete()
{
	int t;
	
	if(start==NULL)
	 printf("\n\tList is Empty");
	else
	{
		printf("\n\t Enter the data You want to search: ");
		scanf("%d",&t);
		ptr=start;
		
		while(ptr!=NULL)
		{
			if(ptr->data==t)
			{
			   printf("\n\t Search is succsessful\n");
			   break;
		    }
		    pptr=ptr;
			ptr=ptr->link;
		}
		if(ptr==NULL)
		 printf("\n\t Search is unsuccsessful\n");
		else
		{
			pptr->link=ptr->link;
		}
   }
}

void display()
{
	ptr=start;
	while(ptr!=NULL)
	{
	  printf("\n\t %d",ptr->data);
	  ptr=ptr->link;
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
		printf("\n\t Press 6: For search");
		printf("\n\t Press 7: For search_insert");
		printf("\n\t Press 8: For search_delete");
		printf("\n\t Press 9: For exit");
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
				search();
				break;
			case 7:
				search_insert();
				display();
				break;
			case 8:
				search_delete();
				display();
			case 9:
				break;
			default :
				printf("\n\t Wrong Choice\n");
		}
	}while(n!=9);
	
}
