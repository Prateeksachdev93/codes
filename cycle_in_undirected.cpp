#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v[100001];
int counter=0;
int visited[100001];
vector<int > x;
void dfs(int from)
{
	int i,j;
	for(i=0;i<v[from].size();i++)
	{
		if(!visited[v[from][i]])
		{
			//printf("from [i] %d\n",v[from][i]);
			visited[v[from][i]]=1;
			x.push_back(v[from][i]);
		//	counter++;
			dfs(v[from][i]);
			break;
		}

	}
	return;
}
int main()
{
	int n,n1,n2;
	int m;
	int i,j,k;
	int t;
	int mini_neigh;
	
	
		//no of vertices , no of edges, minimum no of edges on each vertex
		// to find a cycle of length mini_len + 1
		scanf("%d%d%d",&n,&m,&mini_neigh);   

		for(i=0;i<m;i++)
		{   
			scanf("%d%d",&n1,&n2);
		v[n1].push_back(n2);
		v[n2].push_back(n1);

		}   
		for(i=0;i<n+1;i++)
			visited[i]=0;

		x.push_back(1);
		visited[1]=1;
		dfs(1);
		
		int len=x.size();

		int flag=0;
		for(i=0;i<len;i++)	
		{
			k=x[i];
			for(j=0;j<v[k].size();j++)
			{
				if(v[k][j]==x[len-1])
				{
						flag=1;
						break;
				}

			}
			if(flag==1)
				break;
		}
		printf("%d\n",len -i);
		for(;i<len;i++)
		{
			printf("%d ",x[i]);
			
		}
		printf("\n");
	
	return 0;
}
