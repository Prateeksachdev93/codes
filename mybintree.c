#include<stdio.h>
#include<stdlib.h>
int depth=0;
typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;
node * deletekey(node *start,int key);
node *locatemax(node *start);
node *locatemin(node *start);
node * insert(node *start,int val);
node * find(node *start,int key);
void preorder(node *start);
void postorder(node *start);
void inorder(node *start);
int main ()
{
	node *start=(node *)malloc(sizeof(node));
	start->left=NULL;
	start->right=NULL;
	int val,key;
	scanf("%d",&val);
	start->data=val;
	scanf("%d",&val);
	while(1)
	{
		if(val==-1)
			break;
		else
		{
			insert(start,val);
			scanf("%d",&val);
		}
	}
	printf("preorder traversal --->\n");
	preorder(start);
	printf("\n");
	printf("postorder traversal --->\n");
	postorder(start);
	printf("\n");
	printf("inorder traversal --->\n");
	inorder(start);
	printf("\n");
	printf("enter a key to be found\n");
	scanf("%d",&key);
	find(start,key);
	locatemin(start);
	locatemax(start);
	deletekey(start,key);
	printf("preorder traversal --->\n");
	preorder(start);
	printf("\n");

	return 0;
}
node * insert(node *start,int val)
{
	if(start==NULL)
	{
		node *start=(node*)malloc(sizeof(node));
		start->right=NULL;
		start->left=NULL;
		start->data=val;
		return ;
	}
	else
	{
		if(val > start->data)
			start->right=insert(start->right,val);
		else
			start->left=insert(start->left,val);
	}
	return start;
}
void postorder(node *start)
{
	if(start==NULL||start->data<0)
		return;
	postorder(start->left);
	postorder(start->right);
	printf("%d ",start->data);
}
void preorder(node *start)
{
	if(start==NULL||start->data<0)
		return;
	printf("%d ",start->data);
	preorder(start->left);
	preorder(start->right);
}
void inorder(node *start)
{
	if(start==NULL||start->data<0)
		return ;
	inorder(start->left);
	printf("%d ",start->data);
	inorder(start->right);
}
node * find(node *start,int key)
{
	if(start==NULL)
	{
		printf("key not found\n");
		return;
	}
	else if(start->data==key)
	{
		printf("%d has been located at depth %d\n",key,depth);
		return start;
	}
	else if(start->data > key)
	{
		depth++;
		find(start->left,key);
	}
	else if(start->data <key)
	{
		depth++;
		find(start->right,key);
	}
}
node *locatemin(node *start)
{
	if(start->left==NULL)
	{
		printf("the lowest value that has been found is %d\n",start->data);
		 return start;
	}
	else 
		locatemin(start->left);
}
node *locatemax(node *start)
{
	if(start->right==NULL)
	{
		printf("the highest value that has been located is %d\n",start->data);
		return start;
	}
	else
		locatemax(start->right);
}
node * deletekey(node *start,int key)
{
	node *temp;
	if(start==NULL)
	{
		printf("element not found\n");
		exit;
	}
	else if(key>start->data)
		start->right=deletekey(start->right,key);
	else if(key<start->data)
		start->left=deletekey(start->left,key);
	else
		if(start->left && start->right)
		{
			temp=locatemin(start->right);
			start->data=temp->data;
			temp->data=-1;

	//		start->data=temp->data;
	//		start->right=deletekey(start->right,key);
		}
		else
		{
			temp=start;
			if(start->left==NULL)
				start=start->right;
			else if(start->right==NULL)
				start=start->left;
		}
	return start;
}




