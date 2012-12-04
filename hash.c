#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int no;
	struct node* next;
}node;
void insert(node *[],int,int);
void print(node *[]);
int main()
{
	int i;
	node *a[10];
	for(i=0;i<10;i++)
	{
		a[i]=(node*)malloc(sizeof(node));
		a[i]->next=NULL;
//		a[i]=NULL;
	}
	int n;
	for(i=0;i<10;i++)
	{
		scanf("%d",&n);
	int r=(n%10);
	insert(a,r,n);
	}
	printf("----------------------------\n");
	print(a);
}
void insert(node *a[],int r,int n)
{
	node* newnode;
	newnode=(node*)malloc(sizeof(node));
	newnode->next=a[r]->next;
	newnode->no=n;
	a[r]->next=newnode;
}
void print(node *a[])
{
	int i;
	node* head;
	for(i=0;i<10;i++)
	{head=a[i];
		if(head->next==NULL)
			printf("no number for reaminder %d-",i);
		else{
			head=head->next;
		while(head)
		{
			printf("%d->",head->no);
			head=head->next;
		}
		}
		printf("\n");
	}
}
	
