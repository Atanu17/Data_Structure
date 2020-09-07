  #include<stdio.h>
  #define MAX 5
  int top; // global vatriable
  void push(int stk[])
  {
  	int num;
  	if(top==MAX-1)
  	 printf("\n\t O V E R F L O W");
  	else
  	{
  		printf("\n\t Enter the Number ");
  		scanf("%d",&num);
  		stk[++top]=num;//place the number at stack top
	  }
  }
  void pop(int stk[])
  {
  	if(top==-1)//empty list
  	 printf("\n\t U N D E R F L O W");
  	else
  	{
  		printf("\n\t Deleted %d",stk[top--]);
	  }
  }
  void peep(int stk[])
  {
   if(top==-1)//empty list
  	 printf("\n\t U N D E R F L O W");
  	else
  	{
  		printf("\n\t Element %d",stk[top]);
	  }
  }	
  
  void display(int stk[])
  {
  	int i;
  	if(top==-1)//empty list
  	 printf("\n\t List is Empty");
  	else
  	{
  		for(i=top;i>=0;i--)
  		printf("\n\t %d",stk[i]);
	  }
  }

  void main()
  {
  	int stack[MAX];
  	int ch;// choice variable
  	top=-1;// initialize
  	do{
  	printf("\n\t 1 for PUSH");
  	printf("\n\t 2 for POP");
  	printf("\n\t 3 for PEEP ");
  	printf("\n\t 4 for DISPLAY");
  	printf("\n\t 5 for EXIT ");
  	printf("\n\n\tEnter the choice ");
  	scanf("%d",&ch);
  	switch(ch)
  	{
  		case 1:
  			push(stack);
  			display(stack);
  			break;
  			
  		case 2:
  			pop(stack);
  			display(stack);
  			break;
  			
  		case 3:
  			peep(stack);
  			break;
  			
  		case 4:
		  display(stack);
		  break;
		  
		  case 5:break;
		  
		  default:
		  printf("\n\tOops! Wrong choice ");
	  }
    }while(ch!=5)  ;
  }
