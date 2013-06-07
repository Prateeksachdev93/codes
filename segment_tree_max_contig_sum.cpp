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

#include <cstdio>
using namespace std;

struct Tree 
{ 
	int max_sum, sum, left_val, right_val; 
};
const int MAX = 1<<16;
int a[MAX];
Tree T[MAX*2];//4*2^logn 

inline int max2(int a, int b) {
	return ((a > b)? a : b);
}

inline int max3(int a, int b, int c) {
	return max2(a, max2(b, c));
}

void init(int Node, int i, int j) {
	if(i==j) {
		T[Node].max_sum = T[Node].sum = T[Node].right_val = T[Node].left_val = a[i];
		return;
	}
	int m = (i+j)/2;
	init(2*Node, i, m);
	init(2*Node+1, m+1, j);
	
	T[Node].sum = T[Node*2].sum + T[Node*2+1].sum;
	T[Node].max_sum = max3(T[2*Node].max_sum, T[2*Node].right_val + T[2*Node+1].left_val, T[2*Node+1].max_sum);
	T[Node].left_val = max2(T[2*Node].left_val, T[2*Node].sum + T[2*Node+1].left_val);
	T[Node].right_val = max2(T[2*Node].right_val + T[2*Node+1].sum, T[2*Node+1].right_val);
}

void query(Tree &result, int Node, int L, int R, int i, int j) {
	if(L==i && R==j) {
		result = T[Node];
		return;
	}
	int m = (L + R)/2;
	if(j<=m) query(result, 2*Node, L, m, i, j);
	else if(i>m) query(result, 2*Node+1, m+1, R, i, j);
	else {
		Tree Left, Right;
		query(Left, 2*Node, L, m, i, m);
		query(Right, 2*Node+1, m+1, R, m+1, j);
		result.max_sum = max3(Left.max_sum, Right.max_sum, Left.right_val + Right.left_val);
		result.sum = Left.sum + Right.sum;
		result.left_val = max2(Left.left_val, Left.sum + Right.left_val);
		result.right_val = max2(Left.right_val + Right.sum, Right.right_val);
	}
}

int main() {
	int n, i, j, q;
	Tree result;
	scanf("%d", &n);
	for(i=0; i<n; i++) 
		sd(a[i]);
	init(1, 0, n-1);
	sd(q);
	while(q--) {
		scanf("%d%d", &i, &j);
		query(result, 1, 0, n-1, i-1, j-1);
		printf("%d\n", result.max_sum);
	}
	return 0;
}
