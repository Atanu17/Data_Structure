#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
   int data;
   struct node *next;
   struct node *prev;
}Node;
void sortinsert(Node **start,int item)
{
   Node *temp,*ptr=NULL,*q=NULL;
   if((*start)==NULL)
   {
	(*start)=(Node *) malloc(sizeof(Node));
    	(*start)->data=item;
    	(*start)->next=NULL;
    	(*start)->prev=NULL;
   }
   else
   {
        ptr=(*start);
        while(ptr!=NULL && ptr->data<item)
		{   
			q=ptr;
	    		ptr=ptr->next;
		}
		if(q==NULL)
		{
			temp=(Node*)malloc(sizeof(Node));
	   		temp->data=item;
		     temp->next=(*start);
		    (*start)->prev=temp;
		    (*start)=temp;
		}
		else if(q!=NULL && ptr==NULL)
		{
		    temp=(Node*)malloc(sizeof(Node));
	   	    temp->data=item;
		    temp->next=NULL;
		    q->next=temp;
		    temp->prev=q;
		}
		else if(ptr!=NULL && q!=NULL)
		{
		    temp=(Node*)malloc(sizeof(Node));
	   	    temp->data=item;
		    temp->next=ptr;
		    temp->prev=q;
		    ptr->prev=temp;
		    q->next=temp;
		}
	}	
}
void display(Node *start)
{
   Node *ptr=start;
   if(ptr==NULL)
   {
   	 printf("\nLIST is Empty");
   	 return;
   }
   else
   {
   	 while(ptr!=NULL)
   	 {
   		printf("%d ",ptr->data);
   		ptr=ptr->next;
   	 }
   	 return;
   }
}
int main()
{
    Node *start=NULL;
    int item,ch;
    do
    {
   	printf("\n\t1. INSERTION\n\t2. Display \n\t3. Exit\n Enter your choice:");
   	scanf("%d",&ch);
   	switch(ch)
   	{
   		case 1:
		printf("\nEnter the data");
		scanf("%d",&item);
    		sortinsert(&start,item);
   		break;
   		case 2:display(start);
		break;
		case 3:break;
   		default:
			printf("\nWrong choice!");
break;
   		}	
   	}while(ch!=3);	
   return 0;
}

