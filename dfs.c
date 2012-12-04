#include<stdio.h>
#include<stdlib.h>
int g[1000][1000];
int n;
typedef struct node
{
	int nodenumber;
	int status;
	int parent;
}node;
node B[100];
void dfs(int);
int main()
{
	int i,j;
	scanf("%d",&n);
	for(i=1;i<n+1;i++)
	{
		B[i].nodenumber=i;
		B[i].status=-1;
		B[i].parent=0;
		for(j=1;j<n+1;j++)
		{
			scanf("%d",&g[i][j]);
		}
	}
	int from;
	scanf("%d",&from);
	dfs(from);
	for(i=1;i<=n;i++)
	{
		printf("node %d with parent %d\n",B[i].nodenumber,B[i].parent);
	}
	return 0;
}
void dfs(int from)
{
	int i,j;
	for(i=1;i<n+1;i++)
	{
		if(g[from][i]==1 && B[i].status)
		{
		B[i].parent=from;
		B[i].status=0;
		dfs(i);
		}
	}
	return;
}
