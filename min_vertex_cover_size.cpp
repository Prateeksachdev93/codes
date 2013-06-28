#include <iostream>
#include <vector>
#include <cassert>
#include <queue>
#include <cstdio>
 
using namespace std;
 
vector<int> adj[100000];
int deg[100000];
int q[100000];
 
int main()
{
	int top=0,v;
  int n; scanf("%d", &n);
  for(int i = 0; i  < n-1; i++) {
    int a, b; scanf("%d%d", &a, &b); a--, b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
    deg[a]++;
    deg[b]++;
  }  
  for(int i = 0; i < n; i++)
    if(deg[i] == 1) 
    	q[++top]=i;

  int result = 0;
  while(top>0){
  
     v=q[top];top--;
    if(deg[v] != 1) continue;
    result++;
 
    int u = -1;
    for(int i = 0; i < adj[v].size(); i++)
      if(deg[adj[v][i]] > 0)
       	 u = adj[v][i];
 
    deg[u] = 0;//removing the parent
    for(int i = 0; i < adj[u].size(); i++)
      if(--deg[adj[u][i]]==1) q[++top]=adj[u][i];//adding newly formed leaves
  
  }
 	printf("%d\n",result );
  
}