#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	struct node* right;
	struct node* left;
	int height;
	int num;
}node;
node* insert(node*,int);
void preorder(node*);
void inorder(node*);
int he(node* start);
int max(int ,int );
node* single_left(node* start);
node* single_right(node* start);
node* double_right(node* start);
node* double_left(node* start);
int main()
{
	int n;
	int m;
	scanf("%d",&m);
	node *start;
	start=NULL;
	while(m--)
	{
		scanf("%d",&n);
		start=insert(start,n);
	}
	preorder(start);
	printf("\n");
	inorder(start);
	printf("\n");
	return 0;
}
int max(int x,int y)
{
	if(x>y)return x;
	else
		return y;
}
int he(node* start)
{
	if(start==NULL){
		return -1;
	}
	return (max(he(start->left),he(start->right))+1);
}
node* single_left(node* start)
{
	node* k;
	k=start->left;
	start->left=k->right;
	k->right=start;
	k->height=he(k);
	start->height=he(start);
	return k;
}
node* single_right(node* start)
{
	node* k;
	k=start->right;
	start->right=k->left;
	k->left=start;
	k->height=he(k);
	start->height=he(start);
	return k;
}
node* double_left(node* start)
{
	start->left=single_right(start->left);
	return single_left(start);
}		
node* double_right(node* start)
{
	start->right=single_left(start->left);
	return single_right(start);
}
node* insert(node* start,int n)
{
	if(start==NULL)
	{
		start=(node*)malloc(sizeof(node));
		start->left=NULL;
		start->right=NULL;
		start->num=n;
	}
	else if(start->num > n)
	{
		start->left=insert(start->left,n);
		if((he(start->left)) - (he(start->right))==2)
		{
			if(start->left->num>n)
				start=single_left(start);
			else
				start=double_left(start);
		}
	}
	else if(start->num < n)
	{
		start->right=insert(start->right,n);
		if((he(start->right)) - (he(start->left))==2)
		{
			if(start->right->num < n)
				start=single_right(start);
			else
				start=double_right(start);
		}
	
	}
	start->height=he(start);
	return start;
}
void preorder(node* start)
{
	if(start==NULL)
		return;	
	printf("%d ",start->num);
	preorder(start->left);
	preorder(start->right);
}
void inorder(node* start)
{
	if(start==NULL)
		return;	
	inorder(start->left);
	printf("%d height %d\n",start->num,start->height);
	inorder(start->right);
}
