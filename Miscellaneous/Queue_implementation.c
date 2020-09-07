  #include<stdio.h>
  #define MAX 5
  int front,rear; // global vatriable
  void Insert(int Q[])
  {
  	int num;
  	if(rear==MAX-1)
  	 printf("\n\t O V E R F L O W");
  	else
  	{
  		printf("\n\t Enter the Number ");
  		scanf("%d",&num);
  		if(rear==-1)//empty list
  		{
  			rear=0;
  			front=0;
  		     Q[rear]=num;//place the number at Queue
	    }
	    else
	    Q[++rear]=num;//place the number at Queue
     }
 }
  void Delete(int Q[])
  {
  	if(front==-1)//empty list
  	 printf("\n\t U N D E R F L O W");
  	else
  	{
  		printf("\n\t Deleted %d",Q[front]);
  		if(front==rear)// single element
  		{
  			front=-1;
  			rear=-1;
		  }
		  else
		   front++;
	  }
  }
  
  void display(int Q[])
  {
  	int i;
  	if(front==-1)//empty list
  	 printf("\n\t List is Empty");
  	else
  	{
  		for(i=front;i<=rear;i++)
  		printf("\n\t %d",Q[i]);
	  }
  }

  void main()
  {
  	int queue[MAX];
  	int ch;// choice variable
  	front=-1;// initialize
  	rear=-1; // initialize
  	do{
  	printf("\n\t 1 for INSERT");
  	printf("\n\t 2 for DELETE");
  	printf("\n\t 3 for DISPLAY");
  	printf("\n\t 4 for EXIT ");
  	printf("\n\n\tEnter the choice ");
  	scanf("%d",&ch);
  	switch(ch)
  	{
  		case 1:
  			Insert(queue);
  			display(queue);
  			break;
  			
  		case 2:
  			Delete(queue);
  			display(queue);
  			break;
  				
  		case 3:
		  display(queue);
		  break;
		  
		  case 4:break;
		  
		  default:
		  printf("\n\tOops! Wrong choice ");
	  }
    }while(ch!=4)  ;
  }
