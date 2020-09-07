// accept infix expression & convert postfix form
#include<stdio.h>
int priority(char c)
{
	if(c=='^')
	 return 4;
	else if(c=='*' || c=='/' || c=='%')
	 return 3;
	else if(c=='+' || c=='-')
	 return 2;
	else// when '(' in stack
	 return 1; 
}
void main()
{
	char infix[100],stack[50],post[100];
	int i,top=-1,ind=0;
	printf("Enter the expression ");
	scanf("%s",infix);
	printf("\n The expression is %s",infix);
	for(i=0;infix[i]!='\0';i++)
	{
		if(infix[i]=='(')
		 stack[++top]=infix[i];
		 
		else if(infix[i]>='a' && infix[i]<='z')// operand
		 post[ind++]=infix[i];
		 
		 else if(infix[i]==')')
		 {
		 	while(stack[top]!='(')
		 	 post[ind++]=stack[top--];
		 	 
		 	top--; // remove '(' from stack
		 }
		 else // operator
		 {
		 	if(priority(infix[i])>priority(stack[top]))
		 	  stack[++top]=infix[i];
		 	else // same or lower
		 	{
		 		while(priority(infix[i])<=priority(stack[top]))
		 		 post[ind++]=stack[top--];
		 		 
		 		stack[++top]=infix[i];
			 }
		 }
		 stack[++top]='\0';
		 post[ind]='\0';
		 printf("\n %c\t%s\t%s",infix[i],stack,post);
		 top--;
		 
	}
	getch();
	
}
