#include<stdlib.h>
#include<stdio.h>

void PUSH(int *,int,int,int *);
int POP(int *,int *);

void INSERT(int *,int *,int *,int,int);
int DELETE(int *,int *,int *,int);

int main()
{
	int ch,ch1,ch2,*s,max,top=-1,front=0,rear=0,item,c=0;
	do
	{
	printf("\n1.STACK\n2.Circular QUEUE\n3.EXIT\n");
  	printf("\nEnter Your Choice : ");
  	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		printf("\nEnter the maximum Size of the STACK: ");
			scanf("%d",&max);
			s=(int*)malloc(max*sizeof(int));
			do
			{
				printf("\n1.PUSH\n2.POP\n3.Main Menu\n");
				printf("\nEnter your choice: ");
				scanf("%d",&ch1);
				switch(ch1)
				{
				 case 1:
				 	printf("\nEnter the value to be pushed: ");
				 	scanf("%d",&item);
				 	PUSH(s,max,item,&top);
				  	break;
				 case 2:
				 	c=POP(s,&top);
				 	if(c!=-99999)
				 		printf("\nThe popped item is: %d",c);
				 	else
						printf("%d",c);	     
				 	break;
				 case 3:
				    break;
				 default:
				    printf("\nWrong Choice\n");
					break;	
				}
			}
			while(ch1!=3);
			break;
		case 2:
			printf("\nEnter The maximum size of the QUEUE ");
			scanf("%d",&max);
			s=(int*)malloc((max+1)*sizeof(int));
			do
			{
				printf("\n1.INSERT\n2.DELETE\n3.Main Menu\n");
				printf("\nEnter your choice: ");
				scanf("%d",&ch2);
				switch(ch2)
				{
					case 1:
						printf("\nEnter the value to inserted: ");
						scanf("%d",&item);
						INSERT(s,&front,&rear,max+1,item);
						break;
					case 2:
						c=DELETE(s,&front,&rear,max+1);
						if(c!=-99999)
							printf("\nThe deleted item is: %d",c);
					   	else
					   		printf("%d",c);
						break;
				    case 3:
						break;
					default:
						printf("\nWrong Choice\n");	
						break;
				}
			}
			while(ch2!=3);                                  
		    break;
		case 3:
		    break;
		default:
		    printf("\nWrong Choice\n");	
		    break;
	}
   }
	while(ch!=3);
	
	return 0;
}

void PUSH(int *s,int max,int item,int *top)
{
	if(*top==max-1)
	{
		printf("\nOVERFLOW\n");
		return;
	}
	else
	{
		*top=*top+1;
		s[*top]=item;
		return;
	}
}

int POP(int *s,int *top)
{
   if(*top==-1)
   {
   	    printf("\nUNDERFLOW\n");
   	    return -99999;
   }	
   else
   {
   	    int item=s[*top];
   	    *top=*top-1;
   	    return item;
   }
}


void INSERT(int *q,int *front,int *rear,int max,int item)
{
	int prev_rear=*rear;
	*rear=(*rear+1)%max;
	if(*front==*rear)
	{
		printf("\nQueue Full\n");
		*rear=prev_rear;
		return;
	}
	else
	{
		
		q[*rear]=item;
		return;
	}
}

int DELETE(int *q,int *front,int *rear,int max)
{
	if(*front==*rear)
	{
		printf("\nQueue Empty");
		return -99999;
	}
	else
	{
		*front=(*front+1)%max;
		return q[*front];
	}
}

