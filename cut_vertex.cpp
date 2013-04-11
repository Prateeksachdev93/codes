#include <cstdio>
#include <iostream>

#include <vector>
#include <set>
using namespace std;

#define MAXN 3002

vector<int> g[MAXN];
int n;

bool used[MAXN];
int timer,tin[MAXN],fup[MAXN];

void dfs(int v,int p=-1){
	used[v] = true;
	tin[v] = fup[v] = timer++;
	int children = 0;
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if(to==p) continue;
		if (used[to])
			fup[v] = min (fup[v], tin[to]);
		else {
			dfs (to, v);
			fup[v] = min (fup[v], fup[to]);
			if(fup[to]>= tin[v] && p!=-1)
				cout<< v<<endl;
			++children;
		}
	}
	if(p==-1 && children>1)
		//need_protection.insert(v);
		cout<< v<<endl;
		
}

int main() {
	int m;
	int cost;
	int from,to;
	
		scanf("%d",&n);//number of nodes
		scanf("%d",&m);//number of edges
		
		while(m--)
		{
			scanf("%d%d",&from,&to);
			g[from].push_back(to);
			g[to].push_back(from);

		}
	
		timer = 0;
		for (int i=0; i<n; ++i)
			used[i] = false;
		dfs (0);
	

	
	return 0;
}
