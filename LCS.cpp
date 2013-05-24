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

const int MAXLEN = 260000;
const int K = 26;
char st1[MAXLEN], st2[MAXLEN];
struct state {
	int len;
	int link;
	int next[K];
} st[MAXLEN*2-1];

int sz, prev;


void init() {
	st[0].link = -1;
	SET(st[0].next);
	sz++;
}

void construct(char c) {
	int nlast = sz++;
	int p, q, clone;
	st[nlast].len = st[prev].len + 1;
	SET(st[nlast].next);
	for(p=prev; p!=-1 && st[p].next[c]==-1; p=st[p].link) st[p].next[c] = nlast;
	if(p == -1) 
		st[nlast].link = 0;
	else{
		q = st[p].next[c];
		if(st[p].len + 1 == st[q].len)
		 st[nlast].link = q;
		else{
			clone = sz++;
			st[clone].len = st[p].len + 1;
			memcpy(st[clone].next, st[q].next, sizeof st[clone].next);
			st[clone].link = st[q].link;
			for(; p!=-1 && st[p].next[c]==q; p=st[p].link) st[p].next[c] = clone;
			st[q].link = st[nlast].link = clone;
		}
	}
	prev = nlast;
}

int largest_common_substring(char *a, char *b) {
	
	init();
	int p, l, best, bestpos;
	for(int i=0; a[i]; i++)
	 construct (a[i]-'a');
	p = 0;
	l = 0;
	best = 0;
	bestpos = 0;
	for(int i=0; b[i]; i++) {
		if(st[p].next[b[i]-'a'] == -1) {
			for(; p!=-1 && st[p].next[b[i]-'a'] == -1; p=st[p].link);
			if (p == -1) {
				p = l = 0;
				continue;
			}
			l = st[p].len;
		}
		p = st[p].next[b[i]-'a']; l++;
		if(l > best)
		 {
		 	bestpos = i;
		 	best = l;
		 	
		 }
	}
	return best;
}

int main() {
	ss(st1);
	ss(st2);
	int maxlen;
	maxlen=largest_common_substring(st1, st2);
	printf("%d\n", maxlen);
	return 0;
}




