#include<stdio.h>
#include<string.h>
#define MAX 50//constant declaration

char stack[MAX];//global declaration
int top;//pointer
int priority(char c)
{
	if(c=='^')
	  return 5;
	else if(c=='*' || c=='/')
	 return 4;
	else if(c=='+' || c=='-')
	 return 3;
	else
	 return 2;
}
main()
{
	top=-1;//initialization of pointer
	int l,k=0;
	char arr[MAX],post[MAX];
	printf("Enter the expression: ");
	gets(arr);
	strcat(arr,")");
	stack[++top]='(';
	printf("\n\n\tSYMBOL\t\tSTACK\t\tEXPRESSION\n\n");
	for(l=0;arr[l]!='\0';l++)
	{
	 if(arr[l]>='A' && arr[l]<='Z')	
	  post[k++]=arr[l];
	 else if(arr[l]=='(')
	  stack[++top]=arr[l];
	else if(arr[l]==')')
	{
		while(stack[top]!='(')
		 post[k++]=stack[top--];
		 
		top--; // romove ( bracket from stack
	}
	else
	{
		if(priority(arr[l])>priority(stack[top]))
		 stack[++top]=arr[l];
		else
		{
		
		while(priority(arr[l])<=priority(stack[top]))
		 post[k++]=stack[top--];
		stack[++top]=arr[l];
	    }
    }
    post[k]='\0';
	stack[++top]='\0';
    printf("\n\t%c\t\t%s\t\t%s",arr[l],stack,post);
    top--;
	}
}
