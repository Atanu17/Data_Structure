#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int coef,exp;
	struct node *link;
}poly;

poly* insert(poly *start,poly *t)
{
	
	if(start==NULL)
	 start=t;
	else
	{
		poly *p=start;
		while(p->link!=NULL)
		 p=p->link;
		 
		p->link=t;
		
	}
	return start;
	
}
poly* add(poly *start1,poly *start2)
{
	poly *p1=start1;
	poly *p2=start2;
	poly *r=NULL,*t;
	while(p1!=NULL && p2!=NULL)
	{
		if(p1->exp>p2->exp)
		{
			t=(poly*)malloc(sizeof(poly));   
		   t->coef=p1->coef;
		   t->exp=p1->exp;
		   t->link=NULL;
		   r=insert(r,t);
		   p1=p1->link;
		}
		else if(p1->exp<p2->exp)
		{
			t=(poly*)malloc(sizeof(poly));
		   t->coef=p2->coef;
		   t->exp=p2->exp;
		   t->link=NULL;
		   r=insert(r,t);
		   p2=p2->link;
	    }
	    else
	    {
	    	t=(poly*)malloc(sizeof(poly));
		   t->coef=p1->coef+p2->coef;
		   t->exp=p1->exp;
		   t->link=NULL;
		   r=insert(r,t);
		   p1=p1->link;
		   p2=p2->link;
		}
	}
	if(p1==NULL)
	 r=insert(r,p2);
	else
	 r=insert(r,p1);
	 
	return r;
}
void display(poly *start)
{
	poly *p=start;
	while(p->link!=NULL)
	{
		printf(" %d X^%d + ",p->coef,p->exp);
		p=p->link;
	}
	printf(" %d X^%d  ",p->coef,p->exp);
}
int main()
{
	int n1,i,n2;
	poly *p1=NULL,*p2=NULL,*p3=NULL,*t;
	printf("\nEnter the No. of terms of first polynomial ");
	scanf("%d",&n1);
	for(i=1;i<=n1;i++)
	{
		t=(poly*)malloc(sizeof(poly));
		printf("\nEnter coef ");
		scanf("%d",&t->coef);
		printf("\nEnter expo ");
		scanf("%d",&t->exp);
		t->link=NULL;
		p1=insert(p1,t);
	}
		 
    printf("\n");
	display(p1);
	printf("\nEnter the No. of terms of second polynomial ");
	scanf("%d",&n2);
	for(i=1;i<=n2;i++)
	{
		t=(poly*)malloc(sizeof(poly));
		printf("\nEnter coef ");
		scanf("%d",&t->coef);
		printf("\nEnter expo ");
		scanf("%d",&t->exp);
		t->link=NULL;
		p2=insert(p2,t);
	}
		 
	printf("\n");
	display(p2);
	p3=add(p1,p2) ;
	printf("\n");
	display(p3);
	return 0;
}
