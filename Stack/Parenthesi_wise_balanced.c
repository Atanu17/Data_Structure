#include<stdio.h>
int isEmpty(char *a,int top)
{
	if(top==-1)
		return 1;
	return 0;
}
int eval(char ch)
{
	if(ch=='(' || ch==')')
		return 1;
	if(ch=='{' || ch=='}')
		return 2;
	if(ch=='[' || ch==']')
		return 3;
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
	int i,len,flag,top=-1;
	char exp[100],ch,k;
	printf("\nEnter Expression:");
	while((ch=getchar())!='\n')
	{
		exp[i++]=ch;
	}
	len=i;
	char s[i];
	flag=1;
	for(i=0;i<len;i++)
	{
		char ch=exp[i];
		if(ch=='(' || ch=='{' || ch=='[')
		{
			push(s,len,ch,&top);
		}
		if(ch==')' || ch=='}' || ch==']')
		{
			if(isEmpty(s,top))
			{
				flag=0;
				break;
			}
			else
			{
				k=pop(s,&top);
				if(eval(k)!=eval(ch))
				{
					flag=0;
					break;
				}
			}
		}
	}
	if(isEmpty(s,top)!=1)
	{
		flag=0;
	}
	if(flag==0)
	printf("\nInvalid statement");
	else
	printf("\nValid statement");
	return 0;
}
