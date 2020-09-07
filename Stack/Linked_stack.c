#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
   int data;
   struct node *next;
}Node;    

void display(Node *);
void push(Node **,int);
void pop(Node **);

int main()
{
   Node *top=NULL;
   int item,ch;
   do
   {
   		printf("\n\t1. PUSH\n\t2. POP\n\t3. Exit\n Enter your choice:");
   		scanf("%d",&ch);
   		switch(ch)
   		{
   			case 1: printf("\nEnter the data:");
   					scanf("%d",&item);
   					push(&top,item);
   					break;
   			case 2: pop(&top);
   					break;
			case 3: break;
   			default:
			   	printf("\nWrong choice!");
			 break;
   		}	
   	}while(ch!=3);	
   return 0;
} 
void push(Node **top,int item)
{
	Node *temp;
    if((*top)==NULL)
    {
    	(*top)=(Node *) malloc(sizeof(Node));
    	if((*top)==NULL)
    	{
    		printf("\nOverflow");
    		return;
    	}	
    	(*top)->data=item;
    	(*top)->next=NULL;
    }
    else
    {
    	temp=(Node *) malloc(sizeof(Node));
    	if(temp==NULL)
    	{
    		printf("\nOverflow");
    		return;
    	}	
    	temp->data=item;
    	temp->next= (*top);
    	(*top)=temp;
    }
    return;   		
}
void pop(Node **top)
{
	if((*top)==NULL)
		printf("\nStack is empty");
	else
	{
		Node *temp;
		temp=(*top);
		printf("\n Popped element:%d",(*top)->data);
		(*top)=(*top)->next;
		free(temp);
	}
}			

