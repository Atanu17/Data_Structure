#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
   int data;
   struct node *left;
   struct node *right;
   int flag;
   
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
Node* pop(Node **s,int *top)
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
void enqueue(Node** q,int *front,int *rear,Node** item,int k)
{ 
	int prev_rear = *rear; 
	*rear=(*rear+1)%k;
	if(*front==*rear) 
	{ 
	printf("\nQueue full\n"); 
	*rear = prev_rear; return;
	} 
	else 
	{ 
		q[*rear] = *item;
		return;
	} 
} 
Node* dqueue(Node** q,int *front,int *rear,int k) 
{ 
	if(*front==*rear) 
	{ 
		printf("\nQueue empty\n"); 
	} 
	else 
	{ 
		*front=(*front+1)%k; 
		return q[*front]; 
	} 
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
}
void preOrder(Node **root,int k)
{
	Node * s[k];
	Node *ptr;
	int top=-1;
	ptr=(*root);
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		if(ptr->right!=NULL)
		{
			push(s,ptr->right,k,&top);
		}
		ptr=ptr->left;
	}
	while(top!=-1)
	{
		ptr=pop(s,&top);
		while(ptr!=NULL)
		{
			printf("%d ",ptr->data);
			if(ptr->right!=NULL)
			{
				push(s,ptr->right,k,&top);
			}
			ptr=ptr->left;
		}
	}
}
void postOrder(Node **root,int k)
{
	Node *s[k];
	Node *ptr;
	int top=-1;
	ptr=(*root);
	push(s,ptr,k,&top);
	while(top!=-1)
	{
		while(ptr!=NULL)
		{
			if(ptr->right!=NULL)
			{
				ptr->right->flag=1;
				push(s,(ptr->right),k,&top);
			}
			if(ptr->left!=NULL)
			{
				push(s,ptr->left,k,&top);
			}
			ptr=ptr->left;
		}
		ptr=pop(s,&top);
		while(ptr->flag!=1 && top!=-1)
		{
			printf("%d ",ptr->data);
			ptr=pop(s,&top);
		}
		if(ptr->flag==1)
		{
			ptr->flag=0;
			push(s,ptr,k,&top);
		}
	}
	printf("%d ",ptr->data);
}
levelOrder(Node **root,int k) 
{ 
	Node *ptr = *root;
	Node** q = (Node**)malloc( (k+1)*sizeof(Node) );
	if(ptr==NULL) 
	{ 
		printf("No tree exists\n");
		 return; 
	} 
	else 
	{ 
		int front = 0;
		int rear = 0; 
		enqueue(q,&front,&rear,&ptr,k);
		while(front!=rear) 
		{ 
			ptr = dqueue(q,&front,&rear,k);
			printf("%d ", ptr->data);
			if(ptr->left!=NULL) 
				enqueue(q,&front,&rear,&(ptr->left),k ); 
			if(ptr->right!=NULL) 
				enqueue(q,&front,&rear,&(ptr->right),k ); 
		} 
	}
}

void display(Node *root,int k)
{
	int ch;
	printf("\n\t1. Display PREORDER traversal \n\t2. Display INORDER traversal \n\t3. Display POSTORDER traversal \n\t4. Display LEVELORDER traversal \n\t5. Exit \n Enter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: preOrder(&root,k);
		break;
		case 2: inOrder(&root,k);
		break;
		case 3: postOrder(&root,k);
		break;
		case 4: levelOrder(&root,k);
		break;
		case 5: break;
		default: printf("\nWrong choice!");
		break;
	}
}
int main()
{
   Node *root=NULL;
   int item,ch,k=0;
   do
   {
   		printf("\n\t1. Insertion\n\t2. Display \n\t3. Exit\n Enter your choice:");
   		scanf("%d",&ch);
   		switch(ch)
   		{
   			case 1: printf("\nEnter the data:");
   					scanf("%d",&item);
   					insertion(&root,item,&k);
   					break;
   			case 2: display(root,k);
   			   		break;
   			case 3: break;
   			default: printf("\nWrong choice!");
   			break;
   		}	
   }while(ch!=3);
   return 0;
}
