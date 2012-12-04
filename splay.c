#include<stdio.h>
#include<stdlib.h>
int ind=0;
int depth=0;
typedef struct node
{
	int no;
	struct node* left;
	struct node* right;
}node;
node* start2;
node *parent(node *,int key);
node* createnewnode(int);
node* consttree(int in[],int pre[],int index1,int index2,int m);
int search(int in[],int n,int m);
void postorder(node*);
void preorder(node*);
void inorder(node*);
void rotate(node* ,int);
node *single_left(node*);
node *single_right(node*);
int main()
{
	int n,m;
	scanf("%d",&m);//no of elements
	int i;
	int pr[m],in[m];//arrays for inorder and preorder
	for(i=0;i<m;i++)
	{
		scanf("%d",&pr[i]);
	}
	for(i=0;i<m;i++)
	{
		scanf("%d",&in[i]);
	}
	int index=0;
	int index2=m-1;
	node* start=consttree(in,pr,index,index2,m);
	int number;
//	postorder(start);
//	printf("\n");
	start2=start;
	scanf("%d",&number);
	rotate(start,number);
	inorder(start2);
	printf("\n");
	preorder(start2);
	printf("\n");
	postorder(start2);
	printf("\n");
	return 0;
}
node* createnewnode(int num)
{
	node* newnode=(node*)malloc(sizeof(node));
	newnode->left=NULL;
	newnode->right=NULL;
	newnode->no=num;
	return newnode;
}
int search(int in[],int n,int m)
{
	int i;
	for(i=0;i<m;i++)
	{
		if(in[i]==n){
			return i;
		}
	}
}
node* consttree(int in[],int pre[],int index1,int index2,int m)
{
	if(index1>index2)
		return NULL;
	node* newnode=createnewnode(pre[ind++]);//ind is the current pointer,m is the size of array
	if(index1==index2)
		return newnode;
	int inorderindex=search(in,newnode->no,m);
	newnode->left=consttree(in,pre,index1,inorderindex-1,m);
	newnode->right=consttree(in,pre,inorderindex+1,index2,m);
	return newnode;
}	
void postorder(node* start)
{
	static int count=0;
	if(start==NULL)
		return;
	postorder(start->left);
	postorder(start->right);
	if(count==0)
		{
			printf("%d",start->no);
			count++;
		}else
			printf(" %d",start->no);
}
void preorder(node* start)
{
	static int count=0;
	if(start==NULL)
		return;
	if(count==0)
		{
			printf("%d",start->no);
			count++;
		}else
			printf(" %d",start->no);
	preorder(start->left);
	preorder(start->right);
}
void inorder(node* start)
{
	static int count=0;
	if(start==NULL)
		return;

	inorder(start->left);
	if(count==0)
		{
			printf("%d",start->no);
			count++;
		}else
			printf(" %d",start->no);
	inorder(start->right);
}
node* parent(node *start,int key)
{
	if(start->no < key)
	{
		if(start->right->no==key)
		{
			return start;
		}
		else
		{
			start=start->right;
			node* start2=parent(start,key);
			return start2;
		}
	}else
	{if(start->left->no==key)
		{
			return start;
		}
		else
		{
			start=start->left;
			node* start2=parent(start,key);
			return start2;
		}
	}
}
void rotate(node* start,int key)
{
	node *p,*g;
	if(start->no==key)
		return ;
	else 
	{
		p=parent(start,key);
		if(p->no!=start->no)
		{
			g=parent(start,p->no);
			if(p->no < g->no)
			{
				if(key < p->no)
					g->left=single_left(p);
				else
				{
					g->left=single_right(p);
				}
			}
			if(p->no > g->no)
			{
				if(key < p->no)
					g->right=single_left(p);
				else
				{
					g->right=single_right(p);
				}
			}
		}
		else
		{
			if(key<p->no)
			{
				start2=single_left(p);
			}
			else
			{
				start2=single_right(p);
			}
		}
		start=start2;
		rotate(start,key);

	}
	return;
}
node* single_left(node* start)
{
	node* k;
	k=start->left;
	start->left=k->right;
	k->right=start;
	return k;
}
node* single_right(node* start)
{
	node* k;
	k=start->right;
	start->right=k->left;
	k->left=start;
	return k;
}
