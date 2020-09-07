#include<stdio.h>
#include<stdlib.h>
typedef struct linklist
{
	int data;
	struct linklist *link;	
}node;
node* insert(node *s, int num)
{
	node *temp,*ptr;
	temp=(node*)malloc(sizeof(node));
	temp->data=num;
	temp->link=NULL;
	
	if(s==NULL)
	 s=temp;
	else
	{
		ptr=s;
		while(ptr->link!=NULL)
		 ptr=ptr->link;
		 
		ptr->link=temp;
	}
	return s;
}
void display(node *s)
{
	node *ptr;
	ptr=s;
	while(ptr!=NULL)
	{
		printf("\t %d",ptr->data);
		ptr=ptr->link;
    }
    printf("\n");

}
int main()
{
	node *a[10];
	int i,num,k,x;
	for(i=0;i<10;i++)
	a[i]=NULL;
	
	do
	{
		printf("Enter the Number ");
		scanf("%d",&num);
		k=num%10;
		a[k]=insert(a[k],num);
		
		printf("\n Do you want to continue (1/0)");
        scanf("%d",&x);
    }while(x==1);
    for(i=0;i<10;i++)
    {
		if(a[i]==NULL)
		 printf("\n Empty\n");
		else
		display(a[i]);
	}
}
