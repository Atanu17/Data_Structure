#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int stack[20];
	int top=-1,A,B;
	char s[200];
	gets(s);
	char s1[20];
	int i,pos=0,r,d=0;
	for(i=0;i<strlen(s);i++)//10 20 + 
	{
		
		if(s[i]!=' ')
		{
			if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
			{
				B=stack[top--];
				A=stack[top--];
				if(s[i]=='+')
				 d=A+B;
				else if(s[i]=='-')
				 d=A-B;
				else if(s[i]=='*')
				 d=A*B;
				else
				 d=A/B;
			}
			else
			{
			
				r=(int)s[i]-48;
				d=d*10+r;
				
			}
		}
		else
		{
			
			stack[++top]=d;
			printf("\n %d",stack[top]);
			d=0;
		}
    
	}
	printf("\n Result %d",stack[top]);
}
