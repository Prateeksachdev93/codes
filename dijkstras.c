
#include<stdio.h>
typedef struct node
{
	int nodenumber;
	int known;
	int distance;
	int status;
	int parent;
}node;
int main()
{
	int elements;
	scanf("%d",&elements);
	int A[elements+1][elements+1];
	int i,j;
	node B[elements+1];
	for(i=1;i<=elements;i++)
	{
		B[i].nodenumber=i;
		B[i].known=0;
		B[i].distance=1000;
		B[i].status=-1;
		B[i].parent=0;
		for(j=1;j<=elements;j++)
			A[i][j]=-1;// stores -1 if not connected
	}
	int edges;
	for(i=1;i<=elements;i++)
	{
		for(j=1;j<=elements;j++)
			scanf("%d",&A[i][j]);
	}
	printf("select starting node:");
	int startingnode;
	int Q[elements];
	int start=0,end=0;
	B[1].distance=0;
	B[1].status=0;
	int V;
	startingnode=1;//starting from 1
	while(1)
	{
		V=startingnode;
		for(i=1;i<=elements;i++)
		{
			if(A[V][i]!=-1 && B[i].status==-1 )
			{
				if(B[i].distance > B[V].distance+A[V][i])
				{
					B[i].distance=B[V].distance+A[V][i];
					B[i].parent=B[V].nodenumber;
				}
			}

		}
		B[V].status=0;
		int min=10000,index,flag=1;
		for(i=1;i<=elements;i++)
		{
			if(B[i].status==-1)
			{
				if(B[i].distance <= min)
				{index=i;
					min=B[i].distance;
				}
				flag=0;
			}
		}
		if(flag==1)
				break;
		startingnode=index;
	}
	for(i=1;i<=elements;i++)
		printf("%d at distance %d with parent %d\n",i,B[i].distance,B[i].parent);
}
