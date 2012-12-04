#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int top=-1;
int isoperator(char ch);
typedef struct node
{
	char ch;
	struct node* left;
	struct node* right;
	struct node* p;
}node;
void inorder(node* start);
void preorder(node* start);
int main()
{
	node *ar[100];
	char s[10];
	scanf("%s",s);
	int i;
	for(i=0;i<100;i++)
	{
		ar[i]=(node*)malloc(sizeof(node));
	}

	for(i=0;i<strlen(s);i++)
	{
			node *newnode=(node*)malloc(sizeof(node));
			newnode->ch=s[i];
		if(isoperator(s[i])==1)
		{
			if(top>=0)
			{newnode->right=ar[top]->p;
			top--;}
			if(top>=0)
			{newnode->left=ar[top]->p;
			ar[top]->p=newnode;}
		}
		else
		{
			top++;
			newnode->left=NULL;
			newnode->right=NULL;
			ar[top]->p=newnode;
		}
	}
	node *start=ar[0]->p;
	printf("infix expression :- ");
	inorder(start);
	printf("\n");
	printf("preexpression :- ");
	preorder(start);
	printf("\n");
	return 0;
}
int isoperator(char ch)
{
	if(ch=='+' || ch=='-' || ch=='*' ||ch=='/')
		return 1;
	else
		return 0;
}
void inorder(node* start)
{
	if(start==NULL)
		return;	
	inorder(start->left);
	printf("%c ",start->ch);
	inorder(start->right);
}
void preorder(node* start)
{
	if(start==NULL)
		return;	
	printf("%c ",start->ch);
	preorder(start->left);
	preorder(start->right);
}



