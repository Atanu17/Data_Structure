#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
   int data;
   struct node *left;
   struct node *right;
   
}Node;
void insertion(Node **root,int item,int *k)
{
	Node *temp;
    if((*root)==NULL)
    {
    
    	(*root)=(Node *) malloc(sizeof(Node));
    	(*root)->data=item;
    	(*root)->left=NULL;
    	(*root)->right=NULL;
    	*k=*k+1;
    }
    else
    {
    	temp=(Node *) malloc(sizeof(Node));
    	temp->data=item;
    	temp->left=temp->right=NULL;
    	Node *ptr=*root;
    	Node *par;
    	while(ptr!=NULL)
    	{
    		if(item<ptr->data)
    		{
    			par=ptr;
    			ptr=ptr->left;
    			
			}
			else if(item>ptr->data)
			{
				par=ptr;
				ptr=ptr->right;
				
			}
			else
			{
				printf("\nData already exists...");
				return;
			}
		}
		if(item<par->data)
		{
			par->left=temp;
			*k=*k+1;
		}
		else
		{
			par->right=temp;
			*k=*k+1;
		}
    }
    return;   		
}
void deletion(Node **root,int item)
{
	Node *ptr=*root;
	Node *par=NULL; 
	Node *par_suc=NULL;
	Node *suc=NULL;
	while(ptr!=NULL && ptr->data!=item)
	{
		if(item<ptr->data)
		{
			par=ptr;
			ptr=ptr->left;
		}
		else if(item>ptr->data)
		{
			par=ptr;
			ptr=ptr->right;
		}
	}
	if(ptr!=NULL)
	{
		if(ptr->left==NULL && ptr->right==NULL)
		{
			if(par!=NULL)
			{
				if(ptr->data<par->data)
					par->left=NULL;
				else if(ptr->data>par->data)
					par->right=NULL;
					free(ptr);
					ptr=NULL;
			}
			else
			{
				free(*root);
				*root=NULL;
			}
			
		}
		else if(ptr->left!=NULL && ptr->right==NULL)
		{
			if(par!=NULL)
			{
				if(ptr->data<par->data)
					par->left=ptr->left;
				else if(ptr->data>par->data)
					par->right=ptr->left;
			}
			else
			{
				*root=ptr->left;
			}
			free(ptr);
			ptr=NULL;
		}
		else if(ptr->left==NULL && ptr->right!=NULL)
		{
			if(par!=NULL)
			{
				if(ptr->data<par->data)
					par->left=ptr->right;
				else if(ptr->data>par->data)
					par->right=ptr->right;
			}
			else
			{
				*root=ptr->right;
			}
			free(ptr);
			ptr=NULL;
		}
		else if(ptr->left!=NULL && ptr->right!=NULL)
		{
			par_suc=ptr;
			suc=ptr->right;
			while(suc->left!=NULL)
			{
				par_suc=suc;
				suc=suc->left;
			}
			if(suc->data<par_suc->data)
			{
				par_suc->left=NULL;
			}
			else
			{
				par_suc->right=NULL;
			}
			if(suc->right!=NULL && par_suc!=ptr)
			{
				par_suc->left=suc->right;
				suc->left=ptr->left;
				suc->right=ptr->right;
			}
			else if(suc->right!=NULL && par_suc==ptr)
			{
				suc->left=ptr->left;
			}
			else
			{
				suc->left=ptr->left;
				suc->right=ptr->right;
			}
			
			if(par==NULL)
			{
				*root=suc;
			}
			else
			{
				if(suc->data<par->data)
				{
					par->left=suc;
				}
				else if(suc->data>par->data)
				{
					par->right=suc;
				}
			}
			free(ptr);
			ptr=NULL;
		}
	}
	else
	{
		printf("\nData not found");
	}
}
void push(Node **s,Node *item,int max,int *top)
{
	if(*top==(max-1))
		printf("\nOVERFLOW");
	else
	{
		*top=*top+1;
		s[*top]=item;
	}
}
Node * pop(Node **s,int *top)
{
	Node *item;
	if(*top==-1)
	{
		printf("\nUNDERFLOW");
		return;
	}
	else
	{
		item=s[*top];
		*top=*top-1;
	}
	return item;
}
void inOrder(Node **root,int k)
{
	Node * s[k];
	Node *ptr;
	int top=-1;
	ptr=(*root);
	while(ptr!=NULL)
	{
		push(s,ptr,k,&top);
		ptr=ptr->left;
	}
	while(top!=-1)
	{
		ptr=pop(s,&top);
		printf("%d ",ptr->data);
		if(ptr->right!=NULL)
		{
			ptr=ptr->right;
			while(ptr!=NULL)
			{
				push(s,ptr,k,&top);
				ptr=ptr->left;
			}
		}
	}
	if(top==-1)
		printf("\nNo Data to display");
}

int main()
{
   Node *root=NULL;
   int item,ch,k=0;
   do
   {
   		printf("\n\t1. Insertion\n\t2.Deletion\n\t3.Display \n\t4.Exit\n Enter your choice:");
   		scanf("%d",&ch);
   		switch(ch)
   		{
   			case 1: printf("\nEnter the data to insert:");
   					scanf("%d",&item);
   					insertion(&root,item,&k);
   					break;
   			case 2: printf("\nEnter the data to delete:");
   					scanf("%d",&item);
   					deletion(&root,item);
   			   		break;
   			case 3: inOrder(&root,k);
   			   		break;
   			case 4: break;
   			default: printf("\nWrong choice!");
   			break;
   		}	
   }while(ch!=4);
   return 0;
}
