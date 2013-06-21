//
// spoj ANTTT
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

const int MAXLINES = 1010;

struct Point 
{ 
	int x, y; 
};
struct LineSegment
{ 
	Point a, b; 
};

LineSegment line_seg[MAXLINES];
int root[MAXLINES];

int find_root(int u) {
	if(u!=root[u]) 
		root[u] = find_root(root[u]);
	return root[u];
}

inline bool inrange(int a,int b,int c)
{
	if(a<=b && b<=c)
		return true;
	return false;
}
inline void link(int u, int v) {
	root[u] = root[v];
}

inline int direction(Point &pi, Point &pj, Point &pk) { //to check clockwise or anticlockwise
	return (pk.x-pi.x)*(pj.y-pi.y)-(pj.x-pi.x)*(pk.y-pi.y);
}

inline bool onsegment(Point &pi, Point &pj, Point &pk) {
	return (inrange(min(pi.x,pj.x),pk.x,max(pi.x,pj.x)) && inrange(min(pi.y,pj.y),pk.y,max(pi.y,pj.y)));
}

inline bool intersect(Point &p1, Point &p2, Point &p3, Point &p4) {
	int d1, d2, d3, d4;
	d1 = direction(p3, p4, p1);
	d2 = direction(p3, p4, p2);
	d3 = direction(p1, p2, p3);
	d4 = direction(p1, p2, p4);
	if(((d1>0 && d2<0)||(d1<0 && d2>0)) && ((d3>0 && d4<0)||(d3<0 && d4>0))) return true;//condition for intersection
	if(!d1 && onsegment(p3, p4, p1)) return true;//if points are collinear....then they can intersect if point lies on this line
	if(!d2 && onsegment(p3, p4, p2)) return true;
	if(!d3 && onsegment(p1, p2, p3)) return true;
	if(!d4 && onsegment(p1, p2, p4)) return true;
	return false;
}

int main() {
	
	int t, m, n, i, j, u, v;
	sd(t);
	while(t--) {
		sd(n);sd(m);
		for(i = 1; i <= n; i++) {
			root[i] = i;
			scanf("%d%d%d%d", &line_seg[i].a.x, &line_seg[i].a.y, &line_seg[i].b.x, &line_seg[i].b.y);
		}
		for(i = 1; i <= n; i++) {
			for(j = 1; j <= n; j++) {
				u = find_root(i);
				v = find_root(j);
				if(u != v && intersect(line_seg[i].a, line_seg[i].b, line_seg[j].a, line_seg[j].b)) link(u, v);
			}
		}
		while(m--) {
			scanf("%d%d", &i, &j);
			u = find_root(i);
			v = find_root(j);
			if(u==v) printf("YES\n");
			else printf("NO\n");
		}
	}
	
	return 0;
}



