#include<stdio.h>
#include<stdlib.h>
#define max 5
int top;//global variable
void push(int stk[])
{
	int num;
	if(top==(max-1))
	   printf("\nStack overflow\n");
	else 
	{
		printf("\nEnter a number \n");
		scanf("%d",&num);
		stk[++top]=num;//place the number at stack top
		printf("\n Number inserted  \n");
    }  
}
void pop(int stk[])
{
	if (top==-1)
	   printf("\nStack underflow \n");
	else
	{
		printf("\n Deleted element %d",stk[top--]);
    }   
}
void peep(int stk[])
{
	if(top==-1)
	   printf("\n There is no element to be printed  \n");
	else
	   printf("\n The topmost element is %d",stk[top]);
}
void display(int stk[])
{
	int i;
	if(top==-1)
	    printf("\nStack underflow \n");
	else
	{
		printf("\n The elements of the stack are as follows \n");
		for(i=top;i>=0;i--)
		   printf("%d ",stk[i]);
	}    
}
int main()
{
	int ch,stk[max];
	top=-1;
	while(1)
	{
	 printf("\n 1.PUSH \n");
	 printf("\n 2.POP \n");
	 printf("\n 3.PEEP \n");
	 printf("\n 4.DISPLAY \n");
	 printf("\n 5.EXIT \n");
	 printf("\n CHOICE: \n");
	 scanf("%d",&ch);
	 switch(ch)
	 {
		case 1:
	    push(stk);
		break;
		case 2:
		pop(stk);
		break;
		case 3:
		peep(stk);
		break;
		case 4:
		display(stk);
		break;
		case 5:
		exit(0);	
		default:
		printf("\n WRONG CHOICE \n");
	 }
  }
  return 0;
}
