//
//  main.cpp
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

#define MAX 1002
vd G[MAX];
int L[MAX],P[MAX],T[MAX];

void dfs(int node, int T[MAX], int N, int P[MAX], int L[MAX], int nr)  
{
      int k;
   
  //if node is situated in the first 
  //section then P[node] = 1
  //if node is situated at the beginning
  //of some section then P[node] = T[node]
  //if none of those two cases occurs, then 
  //P[node] = P[T[node]]
      if (L[node] < nr)
          P[node] = 1;
      else
          if(!(L[node] % nr))
              P[node] = T[node];
          else
              P[node] = P[T[node]];
   
     for(int k=0;k<G[node].size();k++)
         dfs(G[node][k], T, N, P, L, nr);
}
int LCA(int T[MAX], int P[MAX], int L[MAX], int x, int y)
{
  //as long as the node in the next section of 
  //x and y is not one common ancestor
  //we get the node situated on the smaller 
  //lever closer
	while (P[x] != P[y])
		if (L[x] > L[y])
			x = P[x];
		else
			y = P[y];

  //now they are in the same section, so we trivially compute the LCA
		while (x != y)
			if (L[x] > L[y])
				x = T[x];
			else
				y = T[y];
			return x;
}

int main()
{
	int n,m,x,q,q1,q2,cc=1;
	int levels;
	int t;
	sd(t);
	while(t--)
	{
			sd(n);
			L[1]=0;
			levels=0;
		
			for(int i=1;i<=n;i++)
			{
				P[i]=i;
			}
			for(int i=1;i<=n;i++)
			{
				sd(m);
				for(int j=0;j<m;j++)
				{
					sd(x);
					G[i].pb(x);
					L[x]=L[i]+1;
					if(L[x]>levels)
						levels=L[x];
					T[x]=i;
				}
		
			}	
			if(n>1)
				dfs(1,T,n,P,L,sqrt(levels));
			
			sd(q);
			printf("Case %d:\n",cc);
			for(int i=0;i<q;i++)
			{
				sd(q1);sd(q2);
				printf("%d\n",LCA(T,P,L,q1,q2));
			}
			for(int i=1;i<=n;i++)
			{
				G[i].clear();
			}
			cc++;
	}
	return 0;
}



