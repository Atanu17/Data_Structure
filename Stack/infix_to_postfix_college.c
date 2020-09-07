#include<stdio.h>
#include<ctype.h>
int preced(char c)
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
int isEmpty(char *a,int top)
{
	if(top==-1)
		return 1;
	return 0;
}
void push(char *s,int max,char item,int *top)
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

char pop(char *s,int *top)
{
   if(*top==-1)
   {
   	    printf("\nUNDERFLOW\n");
   	    return;
   }	
   else
   {
   	    char item=s[*top];
   	    *top=*top-1;
   	    return item;
   }
}
int main()
{
	int i=0,len,j=0,flag,top=-1;
	char iexp[100],pexp[100],ch,k,s[100],p;
	printf("\nEnter Expression:");
	while((ch=getchar())!='\n')
	{
		iexp[i++]=ch;
	}
	len=i;
	for(i=0;i<len;i++)
	{
		ch=iexp[i];
		if(isalpha(ch))
		{
			pexp[j++]=ch;
		}
		else if(ch=='(')
		{
			push(s,len,ch,&top);
		}
		else if(ch==')')
		{
			p=pop(s,&top);
			while(p!='(')
			{
				pexp[j++]=p;
				p=pop(s,&top);
			}
		}
		else
		{
			while(preced(ch)<=preced(s[top]))
			{
				pexp[j++]=pop(s,&top);
			}
			push(s,len,ch,&top);
		}
	}
	while(!isEmpty(s,top))
	{
		pexp[j++]=pop(s,&top);
	}
	printf("\n POSTFIX EXPRESSION:");
	for(i=0;i<j;i++)
	   printf("%c",pexp[i]);
	
}
