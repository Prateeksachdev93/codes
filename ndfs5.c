#include<stdio.h>
#include<stdlib.h>
int g[1000][1000];
int stack[1000];
int n;
int ways[1000][1000];
int x=0;
void dfs(int,int,int);
int main()
{
	int i,j;
	int noofcases;
	scanf("%d",&noofcases);
	while(noofcases--)
	{
	scanf("%d",&n);
	for(i=1;i<n+1;i++)
	{
		for(j=1;j<n+1;j++)
		{
			scanf("%d",&g[i][j]);
		}
	}
	int from,to;
	int queries;
	scanf("%d",&queries);
	while(queries--)
	{
		int total;
		scanf("%d%d%d",&from,&to,&total);
		int top=1;
		stack[0]=from;
		for(i=0;i<1000;i++)
			for(j=0;j<1000;j++)
				ways[i][j]=0;
		dfs(from,to,top);
		int count[x];
		for(i=0;i<x;i++)
			count[i]=0;
		if(x==0)
			printf("-1\n");
		else{
			for(i=0;i<x;i++)
			{int u=0;
				while(ways[i][u]!=0)
				{count[i]++;
					u++;
				}
			}
			int len=2;int t=0;
			while(1)
			{
				for(i=0;i<x;i++)
				{int u=0;
					if(count[i]==len)
					{count[i]=-1;t++;
						while(ways[i][u]!=0)
						{if(u==0)
							printf("%d",ways[i][u]);
							else
								printf(" %d",ways[i][u]);
							u++;
						}
						printf("\n");

					}
					if(t >= total)
						break;
				}
				if(i==x&&t<x&&t<total)	
				{
					len++;
				}
				else break;
			}
		}
	x=0;}
	}
	return 0;
}
void dfs(int from,int to,int top)
{
	int i,j;
	for(i=1;i<n+1;i++)
	{
		if(i==to&& g[from][to]==1)
		{stack[top]=i;
			for(j=0;j<=top;j++)
			{
				ways[x][j]=stack[j];
			}
			x++;
		}
		if(g[from][i]==1)
		{
		stack[top]=i;
		dfs(i,to,top+1);
		}

	}
	return;
}
