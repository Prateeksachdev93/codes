#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	struct node* right;
	struct node* left;
	int num;
}node;
node* insert(node*,int);
void preorder(node*);
void inorder(node*);
void levelorder(node*);
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
	levelorder(start);
	printf("\n");
	return 0;
}
node* insert(node* start,int n)
{
	if(start==NULL)
	{
		node* start=(node*)malloc(sizeof(node));
		start->left=NULL;
		start->right=NULL;
		start->num=n;
		return start;
	}
	else if(start->num< n)
	{
		start->right=insert(start->right,n);
	}
	else
	{
		start->left=insert(start->left,n);
	}
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
	printf("%d ",start->num);
	inorder(start->right);
}
void levelorder(node* start)
{
	node* queue[100];
	int ind1=0;
	int ind2=0;
	int i;
	for(i=0;i<100;i++)
	{
		queue[i]=NULL;
	}
	while(start)
	{
		printf("%d ",start->num);
		if(start->left)
			queue[ind1++]=start->left;
		if(start->right)
			queue[ind1++]=start->right;
	start=queue[ind2++];
	}
}



