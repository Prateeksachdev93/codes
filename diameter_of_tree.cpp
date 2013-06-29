//
//  diameter: farthest distance between any two nodes in an undirected tree
//
//  Created by Prateek Sachdev 
//  Copyright (c) 2013 Prateek Sachdev. All rights reserved.
//
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>

using namespace std;

typedef vector<int > vd;

#define sd(n) scanf("%d",&n)
#define sc(n) scanf("%c",&n)
#define sf(n) scanf("%f",&n)
#define ss(n) scanf("%s",n)
#define pd(n) printf("%d\n",n)
#define pb push_back

#define ALL(c) c.begin(), c.end()
#define UB(s, e, x) upper_bound(s, e, x)
#define LB(s, e, x) lower_bound(s, e, x)
#define REV(s, e) reverse(s, e);
#define SZ(c) c.size()
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))

#define SIEVE(a) ({int b=ceil(sqrt(a));vd d(a,0);vd e;int f=2;e.pb(2);e.pb(3);for(int x=1;x<b+1;x++){for(int y=1;y<b+1;y++){int n=(4*x*x)+(y*y);if(n<=a&&(n%12==1||n%12==5)){d[n]^=1;}n=(3*x*x)+(y*y);if(n<=a&&n%12==7){d[n]^=1;}n=(3*x*x)-(y*y);if(x>y&&n<=a&&n%12==11){d[n]^=1;}}}for(int r=5;r<b+1;r++){if(d[r]){for(int i=r*r;i<a;i+=(r*r)){d[i]=0;}}}for(int c=5;c<a;c++){if(d[c]){e.pb(c);}}e;})
template<class T> inline vector<pair<T,int> > FACTORISE(T n){vector<pair<T,int> >R;for (T i=2;n>1;){if (n%i==0){int C=0;for (;n%i==0;C++,n/=i);R.push_back(make_pair(i,C));}i++;if (i>n/i) i=n;}if (n>1) R.push_back(make_pair(n,1));return R;}
template<class T> inline T TOTIENT(T n) {vector<pair<T,int> > R=FACTORISE(n);T r=n;for (int i=0;i<R.size();i++)r=r/R[i].first*(R[i].first-1);return r;}

#define MAXN 10001
vd G[MAXN];
int visited[MAXN];
int maxdist;
int dist[MAXN];
void dfs(int u,int d)
{
	visited[u]=1;
	dist[u]=d;
	if(maxdist<d)
		maxdist=d;
	for(int i=0;i<G[u].size();i++)
	{
		if(!visited[G[u][i]])
		{
			dfs(G[u][i],d+1);
		}
	}
	return ;
}
int main()
{
	int n,m,u,v,i,index;
	sd(n);
	
	maxdist=-1;
	for(i=0;i<n-1;i++)
	{
		sd(u);
		sd(v);
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(1,0);//finding the farthest node from any given node
	for(int i=1;i<=n;i++)
	{
		if(dist[i]==maxdist)
		{
			index=i;
			break;
		}
	}
	CLR(dist);
	CLR(visited);
	maxdist=-1;
	dfs(index,0);//find the farthest node from the previously found out farthest node
	printf("%d\n",maxdist );
}

