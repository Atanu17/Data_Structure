#include<stdio.h>
#include<ctype.h>
#include<math.h>
int isEmpty(char *a,int top)
{
	if(top==-1)
		return 1;
	return 0;
}

void push(int *s,int item,int max,int *top)
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

int pop(int *s,int *top)
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
	int i,len,flag,top=-1,val=0,j=0,A,B,d=0,s[100];
	char exp[100],ch,k,temp[3];
	printf("\nEnter Expression:");
	while((ch=getchar())!='\n')
	{
		exp[i++]=ch;
	}
	len=i;
	for(i=0;i<len;i++)
	{
		if(isdigit(exp[i]))
		{
			temp[j++]=exp[i];
		}
		else if(exp[i]==' ')
		{
				val=atoi(temp);
				push(s,val,len,&top);
	       	 	for(j=0;j<3;j++)
	        		temp[j]=' ';
	        	j=0;
		}
		else if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/'|| exp[i]=='^')
			{
				B=pop(s,&top);
				A=pop(s,&top);
				if(exp[i]=='+')
				 push(s,A+B,len,&top);
				else if(exp[i]=='-')
				 push(s,A-B,len,&top);
				else if(exp[i]=='*')
				 push(s,A*B,len,&top);
				else if(exp[i]=='/')
				 push(s,A/B,len,&top);
				else
				{
					d=(int)pow(A,B);
					push(s,d,len,&top);
				} 
			}
	}
	printf("\n Result %d",s[top]);
		return 0;
}
