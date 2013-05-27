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

long long int SegmentTree[4*100005][2]; // 0 holds the sum for that, 1 holds additions for that range

void update(int curr_Node, int i, int j, int x, int y, int v) {
	if(i == x && j == y) {
		SegmentTree[curr_Node][1] += v;
		SegmentTree[curr_Node][0] += (long long int)v * (y-x+1);
		return;
	}
	int middle, ll, ul;
	middle = (i + j) >> 1; ll = curr_Node << 1; ul = ll + 1;
	if(y <= middle) update(ll, i, middle, x, y, v);
	else if(x > middle) update(ul, middle+1, j, x, y, v);
	else {
		update(ll, i, middle, x, middle, v);
		update(ul, middle+1, j, middle+1, y, v);
	}
	SegmentTree[curr_Node][0] = SegmentTree[ll][0] + SegmentTree[ul][0] + SegmentTree[curr_Node][1] * (j-i+1);
}

long long int query(int curr_Node, int i, int j, int x, int y, long long int v) {
	if(i == x && j == y) 
		return SegmentTree[curr_Node][0] + v * (y-x+1);//sum + values to be added for that range
	int middle, ll, ul;
	middle = (i + j) >> 1; 
	ll = curr_Node << 1; 
	ul = ll + 1;
	if(y <= middle) 
		return query(ll, i, middle, x, y, v + SegmentTree[curr_Node][1]);
	else if(x > middle) 
		return query(ul, middle+1, j, x, y, v + SegmentTree[curr_Node][1]);
	else 
	{
		long long int result = 0;
		result += query(ll, i, middle, x, middle, v + SegmentTree[curr_Node][1]);
		result += query(ul, middle+1, j, middle+1, y, v + SegmentTree[curr_Node][1]);
		return result;
	}
}

int main() {
	
	//array indexing from 0 - (n-1)
	int t, n, q, c, x, y;
	int add;
	scanf("%d", &t);
	while(t--) {
		sd(n);
		sd(q);
		CLR(SegmentTree);
		// if c==0 give what needs to be added
		// if c==1 return sum of range
		while(q--) {
			sd(c);sd(x);sd(y);
			if(c==1)
			 printf("%lld\n", query(1, 0, n-1, x-1, y-1, 0));//initial sum=0
			else 
			{
				sd(add);
				update(1, 0, n-1, x-1, y-1,add);
			}
		}
	}
	return 0;
}


