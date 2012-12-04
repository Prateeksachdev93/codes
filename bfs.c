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
	node B[elements];
	for(i=1;i<=elements;i++)
	{
		B[i].nodenumber=i;
		B[i].known=0;
		B[i].distance=1000;
		B[i].status=-1;
		B[i].parent=0;
		for(j=0;j<elements;j++)
			A[i][j]=0;
	}
	int edges;
	printf("please enter number of edges:");
	scanf("%d",&edges);
	for(i=1;i<=edges;i++)
	{
		int from,to;
		scanf("%d",&from);
		scanf("%d",&to);
		A[from][to]=1;
	}
	printf("select starting node:");
	int startingnode;
	scanf("%d",&startingnode);
	int Q[elements];
	int start=0,end=0;
	Q[start]=startingnode;
	B[startingnode].distance=0;
//	for(i=0;i<elements;i++)
//		printf("%d %d\n",i,B[i].distance);
	while(start<=end)
	{
		int V=Q[start];
		start++;
		for(i=1;i<=elements;i++)
		{
			if(A[V][i]==1 && B[i].status==-1 && i!=V)
			{
				end++;
				Q[end]=i;
				B[i].status=0;
				if(B[i].distance > B[V].distance+1)
				B[i].distance=B[V].distance+1;
				B[i].parent=B[V].nodenumber;
			}
		}
	}
	for(i=1;i<=elements;i++)
		printf("%d at distance %d with parent %d\n",i,B[i].distance,B[i].parent);
}
