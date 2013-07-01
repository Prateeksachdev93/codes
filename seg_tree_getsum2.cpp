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


#define MAXN 131074
#define MAXT 262148

struct T { int max1, max2; } Tree[MAXT];
int Array[MAXN];

void init(int Node, int i, int j)
{
	if(i==j)
	{
		Tree[Node].max1 = Array[i];
		Tree[Node].max2 = 0;
		return;
	}
	int m = (i+j)/2, t[4];
	init(2*Node, i, m);
	init(2*Node+1, m+1, j);
	t[0] = Tree[2*Node].max1, t[1] = Tree[2*Node].max2;
	t[2] = Tree[2*Node+1].max1, t[3] = Tree[2*Node+1].max2;
	sort(t, t+4);
	Tree[Node].max1 = t[3], Tree[Node].max2 = t[2];
}

void update(int Node, int i, int j, int val, int idx)
{
	if(i==j)
	{
		Array[i] = val;
		Tree[Node].max1 = val;
		Tree[Node].max2 = 0;
		return;
	}
	int m = (i+j)/2, t[4];
	if(idx <= m) update(2*Node, i, m, val, idx);
	else update(2*Node+1, m+1, j, val, idx);
	t[0] = Tree[2*Node].max1, t[1] = Tree[2*Node].max2;
	t[2] = Tree[2*Node+1].max1, t[3] = Tree[2*Node+1].max2;
	sort(t, t+4);
	Tree[Node].max1 = t[3], Tree[Node].max2 = t[2];
}

void query(int Node, int i, int j, int ll, int ul, int &maxi, int &second_maxi)
{
	if((ll==i && ul==j) || i==j)
	{
		maxi = Tree[Node].max1, second_maxi = Tree[Node].max2;
		return;
	}
	int m = (i+j)/2, t[4];
	if(ul <= m)
		query(2*Node, i, m, ll, ul, maxi, second_maxi);
	else if(ll > m)
		query(2*Node+1, m+1, j, ll, ul, maxi, second_maxi);
	else
	{
		query(2*Node, i, m, ll, m, maxi, second_maxi);
		t[0] = maxi, t[1] = second_maxi;
		query(2*Node+1, m+1, j, m+1, ul, maxi, second_maxi);
		t[2] = maxi, t[3] = second_maxi;
		sort(t, t+4);
		maxi = t[3];
		second_maxi = t[2];
	}
}
int main()
{
	int N,Q,ind1,ind2,maxi,second_maxi;
	char s[3];
	sd(N);
	for(int i=0;i<N;i++)
		sd(Array[i]);
	init(1,0,N-1);
	sd(Q);
	for(int i=0;i<Q;i++)
	{
		ss(s);
		sd(ind1);sd(ind2);
		if(s[0]=='U')
		{
			update(1,0,N-1,ind2,ind1-1);
		}
		else
		{
			query(1,0,N-1,ind1-1,ind2-1,maxi,second_maxi);
			printf("%d\n",maxi+second_maxi );
		}
	}
	

	return 0;
}



