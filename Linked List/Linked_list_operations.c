#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
   int data;
   struct node *next;
}Node;    
void display(Node *);
void INSERTFIRST(Node **,int);
void INSERTLAST(Node **,int);
void INSERTMIDDLE(Node **,int,int);
Node * INSERTION(Node *);
void DELETEFIRST(Node **);
void DELETELAST(Node **);
void DELETEMIDDLE(Node **,int);
Node * DELETION(Node *);
void reverse(Node**);
void swap(Node**,int);
Node* intersection_menu(Node*,Node*,Node*);
void intersection(Node**,Node**,Node**);
int main()
{
   Node *start=NULL,*start1=NULL,*start2=NULL,*head=NULL;
   int item,ch,k;
   


do
   {
   		printf("\n\t1. INSERTION\n\t2. DELETION\n\t3.REVERSE LIST\n\t4. INTERSECTION OF TWO LISTS\n\t5. SWAP BETWEEN K AND K+1TH NODE OFLIST\n\t6. Display \n\t7. Exit\n Enter your choice:");
   		scanf("%d",&ch);
   		switch(ch)
   		{
   			case 1: 
   					start=INSERTION(start);
   					break;
   			case 2: start=DELETION(start);
   					break;
   			case 3:
   					reverse(&start);
			   		break;
			case 4:
					head=intersection_menu(start1,start2,head);
					printf("\nList after intersection of two lists:");
					display(head);
					break;
			case 5:
					printf("\nEnter the value of k");
					scanf("%d",&k);
					swap(&start,k);
					break;				   		
   			case 6: display(start);
			   		break;
			case 7: break;
   			default: break;
   		}	
   	}while(ch!=7);	
   return 0;
} 
Node * INSERTION(Node *start)
{
	int ch,item,k;
	do
	{
		printf("\n\t1. INSERT FIRST\n\t2. INSERT LAST\n\t3.INSERT AT GIVEN POSITION \n\t4. RETURN TO MAIN MENU\n Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
	   	{
	   		case 1: printf("\nEnter the data:");
	   				scanf("%d",&item);
	   				INSERTFIRST(&start,item);
	   				break;
	   		case 2: printf("\nEnter the data:");
	   				scanf("%d",&item);
	   				INSERTLAST(&start,item);
				   	break;
			case 3: printf("\nEnter the position to INSERT");
					scanf("%d",&k);
					printf("\nEnter the data:");
	   				scanf("%d",&item);
					INSERTMIDDLE(&start,item,k);
			case 4: break;
	   		default:break;
	   }
   	}while(ch!=4);
   	return start;
}
void INSERTFIRST(Node **start,int item)
{
	Node *temp;
	if((*start)==NULL)
    {
    	(*start)=(Node *) malloc(sizeof(Node));
    	(*start)->data=item;
    	(*start)->next=NULL;
    }
    else
    {
    	temp=(Node *) malloc(sizeof(Node));	
    	temp->data=item;
    	temp->next=(*start);
    	(*start)=temp;
    }
    return ;   		
}
void INSERTLAST(Node **start,int item)
{
	Node *temp,*ptr;
	temp=(Node*)malloc(sizeof(Node));
    temp->data=item;
    temp->next=NULL;
	if((*start)==NULL)
    {
		(*start)=temp;
    }
    else
    {
    	ptr=(*start);
    	while(ptr->next!=NULL)
    		ptr=ptr->next;
    	ptr->next=temp;
    }  	
	return;	
}
void INSERTMIDDLE(Node **start,int item,int k)
{
	int c=1;
	Node *temp,*ptr,*lptr;
	temp=(Node*)malloc(sizeof(Node));
    temp->data=item;
    temp->next=NULL;
    if((*start)==NULL)
    {
    	printf("\nNo previous node present.Element will be inserted at first position");
		(*start)=temp;
	}
	else if(k==1)
	{
		temp->next=(*start);
		(*start)=temp;
	}
	else
	{
		ptr=(*start);
		while(ptr->next!=NULL && c<k)
		{
			lptr=ptr;
    		ptr=ptr->next;
    		c=c+1;
    	}
    	if(ptr->next==NULL && c<k)
    		printf("\nInserting at middle not possible");
    	else
    	{
    		lptr->next=temp;
    		temp->next=ptr;
		}
    }
}
Node * DELETION(Node *start)
{
	int ch,k;
	do
	{
		printf("\n\t1. DELETE FIRST\n\t2. DELETE LAST\n\t3. DELETE FROM GIVEN POSITION \n\t4. RETURN TO MAIN MENU\n Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
	   	{
	   		case 1: DELETEFIRST(&start);
	   				break;
	   		case 2: DELETELAST(&start);
				   	break;
			case 3: printf("\nEnter the position to DELETE");
					scanf("%d",&k);
					DELETEMIDDLE(&start,k);
			case 4: break;
	   		default:break;
	   }
   	}while(ch!=4);
   	return start;
}
void DELETEFIRST(Node **start)
{
	Node *ptr;
	if((*start)==NULL)
	 printf("\n No Element to delete");
	else
	{
		ptr=(*start);
		printf("\n Deleted %d",ptr->data);
		(*start)=(*start)->next;
		free(ptr);
		ptr=NULL;
	}
}
void DELETELAST(Node **start)
{
	Node *ptr;
	if((*start)==NULL)
		printf("\n No Element to delete");
	else if((*start)->next==NULL)
	{
		printf("\n Deleted %d",(*start)->data);
	    (*start)=NULL;
	}
	else
	{
		ptr=(*start);
		while(ptr->next->next!=NULL)
		{
			ptr=ptr->next;
		}
		printf("\n Deleted %d",ptr->next->data);
		ptr->next=NULL;
	}
}
void DELETEMIDDLE(Node **start,int k)
{
	Node *ptr,*lptr;
	int c=1;
	if((*start)==NULL)
		printf("\n List is Empty");
	else if(k==1)
	{
		ptr=(*start);
		printf("\n Deleted %d",ptr->data);
		(*start)=(*start)->next;
		free(ptr);
		ptr=NULL;
	}
	else
	{
		ptr=(*start);
		while(ptr->next!=NULL && c<k)
		{
			lptr=ptr;
    		ptr=ptr->next;
    		c=c+1;
    	}
    	if(ptr->next==NULL && c<k)
    		printf("\nDeleting at middle not possible");
    	else
    	{
    		printf("\n Deleted %d",ptr->data);
    		lptr->next=ptr->next;
    		free(ptr);
			ptr=NULL;
		}
	}
}
void reverse(Node **start)
{
	Node *p,*q;
	p=(*start)->next;
	(*start)->next=NULL;
	while(p!=NULL)
	{
		q=p->next;
		p->next=(*start);
		(*start)=p;
		p=q;
	}	
}
void swap(Node **start,int k)
{
	Node *p,*q;
	int i=1;
	p=(*start);
	while(i<k && p!=NULL)
	{
		q=p;
		p=p->next;
		i=i+1;
	}
	if(q==NULL && p!=NULL)
	{
		p=(*start)->next;
		(*start)->next=p->next;
		p->next=(*start);
		(*start)=p;
	}
	else if(q!=NULL && p==NULL)
	   printf("Kth node does not exist");
	else
	{
		if(p->next==NULL)
		   printf("(k+1)th node does not exist");
		else
		{
			q->next=p->next;
			p->next=p->next->next;
			q->next->next=p;	
		}   
    }   
}
void sortinsert(Node **start,int item)
{
   Node *temp,*ptr=NULL,*q=NULL;
   if((*start)==NULL)
   {
		(*start)=(Node *) malloc(sizeof(Node));
    	(*start)->data=item;
    	(*start)->next=NULL;
   }
   else
   {
        ptr=(*start);
        while(ptr!=NULL && ptr->data<item )
		{   
			q=ptr;
	    	ptr=ptr->next;
		}
		if(q==NULL)
		{
			temp=(Node*)malloc(sizeof(Node));
	   		temp->data=item;
		    temp->next=(*start);
		    (*start)=temp;
		}
		else if(q!=NULL && ptr==NULL)
		{
			temp=(Node*)malloc(sizeof(Node));
	   		temp->data=item;
		    temp->next=NULL;
		    q->next=temp;
		}
		else if(ptr!=NULL && q!=NULL)
		{
			temp=(Node*)malloc(sizeof(Node));
	   		temp->data=item;
		    temp->next=ptr;
		    q->next=temp;
		}
	}	
}
Node* intersection_menu(Node *start1,Node *start2,Node *head)
{
	int ch,item;
	do
	{
		printf("\n\t1.Enter elements in 1st list.\n\t2.Enter elements in 2nd list.\n\t3.Exit.\n\t");
		printf("\nEnter your choice.");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the data");
				scanf("%d",&item);
		    	sortinsert(&start1,item);
		    break;
		    case 2:
		    	printf("\nEnter the data");
				scanf("%d",&item);
				sortinsert(&start2,item);
			break;
			case 3: break;
		}
	}while(ch!=3);
	intersection(&start1,&start2,&head);
	return head;
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
void intersection(Node **start1,Node **start2,Node **head)
{
	Node *p,*q,*ptr,*temp;
	p=(*start1);
	q=(*start2);
	printf("\n1st list:");
	display(p);
	printf("\n2nd list:");
	display(q);
	while(p!=NULL && q!=NULL)
	{
		if(p->data<q->data)
		p=p->next;
		else if(q->data<p->data)
		q=q->next;
		else
		{
			temp=(Node*)malloc(sizeof(Node));
		    temp->data=q->data;
		    temp->next=NULL;
			if((*head)==NULL)
		    {
				(*head)=temp;
		    }
		    else
		    {
		    	ptr=(*head);
		    	while(ptr->next!=NULL)
		    		ptr=ptr->next;
		    	ptr->next=temp;
		    }
		    q=q->next;
		    p=p->next;
		}
	}
}		

