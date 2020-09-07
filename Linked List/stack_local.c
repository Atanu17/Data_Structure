#include<stdio.h>
#include<stdlib.h>
typedef struct linklist
{
	int data;
	struct linklist *link;
}node;

node * push(node *s)
{
	node *t;
	t=(node*)malloc(sizeof(node));
	printf("Enter the Data ");
	scanf("%d",&t->data);
	t->link=NULL;
	
	if(s==NULL)
	 s=t;
	else
	{
		t->link=s;
		s=t;
	}
	return s;
}
node * pop(node *s)
{
	if(s==NULL)
	 printf("\n UNDERFLOW");
	else
	{
		printf("\n Deleted %d",s->data);
		s=s->link;
	}
}
void display(node *s)
{
	if(s==NULL)
	 printf("\n List is empty");
	else
	{
		node *p=s;
		while(p!=NULL)
		{
			printf("\n %d",p->data);
			p=p->link;
		}
	}
}
void main()
{
	node *start=NULL;
	int ch;
	while(1)
	{
	printf("\n1.PUSH");
	printf("\n2.POP");
	printf("\n3.DISPLAY");
	printf("\n4.EXIT");
	printf("\nEnter your choice");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			start=push(start);
	    break;
	    case 2:
	    	start=pop(start);
	    break;
	    case 3:
	    	display(start);
	    break;
	    case 4:
	    	exit(0);
	    break;
	    default:
	    	printf("Wrong Choice!");
	}
}
}
	
	/*char ch='Y';
	do
	{
		start=push(start);
		printf("\n Are you continue (y/N) ");
		fflush(stdin);
		scanf("%c",&ch);
		
	}while(ch=='y' || ch=='Y');
	display(start);*/
	
