// implementation of stack using ARRAY
#include<stdio.h>
#define MAX 5

int stack[MAX];// global variable
int top;// pointer

void push()
{
	int num;
	if(top==MAX-1)
	 printf("\n\tO V E R F L O W\n");
	else
	{
		printf("\n\tEnter the data ");
		scanf("%d",&num);
		stack[++top]=num;// place the number
	}
}

void pop()
{
	if(top==-1)
	 printf("\n\tU N D E R F L O W\n");
	else
	{
		printf("\n\tDeleted %d",stack[top--]);
	}
}

void display()
{
	int i;
	if(top==-1)
	 printf("\n\tStack is Empty\n");
	else
	{
		for(i=top;i>=0;i--)
		 printf("\n\t%d",stack[i]);
	}
}

main()
{
	int n;
	top=-1;//initialize
	do
	{	
	  printf("\n\tPress 1: For Push");
	  printf("\n\tPress 2: For Pop");
	  printf("\n\tPress 3: For Display");
	  printf("\n\tPress 4: For Exit");
	  printf("\n\n\tEnter your Choice: ");
	  scanf("%d",&n);
    switch(n)
    {
    	case 1: 
		  push();
    	  display();
    	  break;
    	  
    	case 2:
    		pop();
    		
    	case 3:
    		display();
    		break;
    		
    	case 4:break;
    	default:
    		printf("\n\tWrong Choice");
	}
  }while(n!=4);
}
