//valid expression checking
#include<stdio.h>
#define MAX 50//constant declaration

char arr[MAX];//global declaration
int top;//pointer

main()
{
	top=-1;//initialize
	int l;
	char stack[50];
	printf("Enter the expression: ");
	gets(arr);
	for(l=0;arr[l]!='\0';l++)
	{
		if(arr[l]=='(' || arr[l]=='{' || arr[l]=='[')
		 stack[++top]=arr[l];//PUSH
		
		else if(arr[l]==')' || arr[l]==']' || arr[l]=='}')
		{
		if(arr[l]==')' && stack[top]!='(')
		 break;
		else if(arr[l]=='}' && stack[top]!='{')
		 break;
		else if(arr[l]==']' && stack[top]!='[')
		 break;
		 top--;//POP
	    }
	}

	if(top==-1)
	 printf("\nValid Expression");
	else
	  printf("\nNot Valid Expression");
}
