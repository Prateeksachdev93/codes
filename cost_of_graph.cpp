//
//  SPOJ : KOICOST using disjoint data structures
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

#define MAX 100009
#define MOD 1000000000


vector< pair<int,pair<int,int> > > G;
int parent[MAX];
long long int cnt[MAX], sum[MAX];

int find(int u) {
	if(u != parent[u]) parent[u] = find(parent[u]);
	return parent[u];
}

int main() {
	int Nodes, Edges, u, v, w, i;
	long long int res, cu, cv;
	scanf("%d %d", &Nodes, &Edges);
	for(i = 0; i < Edges; i++) {
		scanf("%d %d %d", &u, &v, &w);
		G.push_back(make_pair(w, make_pair(u, v)));
	}
	sort(G.begin(), G.begin()+Edges);
	for(i = 0; i < Edges; i++) sum[i] = (long long )(G[i].first + (i > 0 ? sum[i-1] : 0));
	for(i = 1; i <= Nodes; i++) {
		parent[i] = i;
		cnt[i] = 1;
	}
	for(res = 0, i = G.size() - 1; i >= 0; i--) {
		u = find(G[i].second.first);
		v = find(G[i].second.second);
		if(u != v) {
			cu = cnt[u], cv = cnt[v];
			res = (res+ ((cu * cv) * sum[i])%MOD)%MOD;
			
			parent[u] = parent[v];
			cnt[find(G[i].second.first)] = cu + cv;
			cnt[find(G[i].second.second)] = cu + cv;
		}
	}
	printf("%lld\n", res);
	return 0;
}

