#include<stdio.h>
#include<stdlib.h>
typedef struct linkedlist
{
	int data;
	struct linkedlist *left;
	struct linkedlist *right;
}tree;

tree* insert(tree *root, int item)
{
	if(root==NULL)
	{
		tree *temp;
		temp=(tree*)malloc(sizeof(tree));
		temp->data=item;
		temp->right=NULL;
		temp->left=NULL;
		root=temp;
		return root;
	}
	if(item<=root->data)
	 root->left=insert(root->left,item);
	else if(item>root->data)
	 root->right=insert(root->right,item);
		return root;
}

void preorder(tree *root)
{
	if(root!=NULL)
	{
		printf("\n %d",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(tree *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("\n %d",root->data);
		inorder(root->right);
	}
}
void postorder(tree *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("\n %d",root->data);
	}
}



int main()
{
	int ch,item;
	tree *ROOT;
	ROOT=NULL;
	do{
	printf("\n 1.INSERT \n 2.PREORDER TRAVERSAL \n 3.INORDER TRAVERSAL \n 4.POSTORDER TRAVERSAL \n \n5. EXIT");
	scanf("%d",&ch);

    	switch(ch)
    	{
    		case 1:
    		printf("ENTER ELEMENT TO INSERT");
    		scanf("%d",&item);
    		ROOT=insert(ROOT,item);
    		break;
    		case 2:
    		preorder(ROOT);
    		break;
    		case 3:
    		inorder(ROOT);
    		break;
    		case 4:
    		postorder(ROOT);
    		break;
    		case 5:
    		break;
    		default:
    		printf("Wrong choice");
    	}
    	
    }while(ch!=5);
    	return 0;	
}
	

