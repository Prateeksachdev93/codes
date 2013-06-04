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
typedef long long int LL;

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

string s;
int P[16][50001];
struct entry
{
	int i,nr[2];
}L[50001];
bool compare(entry a,entry b)
{
	if(a.nr[0]==b.nr[0])
		return a.nr[1] < b.nr[1];
	else
		return a.nr[0] < b.nr[0];
}
int stp = 1;
void compute_suffix_array(){
	int i,l;
	l = s.length();
	for(i=0;i<l;i++)
		P[0][i] = s[i];
	int cnt = 1;
	while(cnt < l){
		for(i=0;i<l;i++)
		{
			L[i].i = i;
			L[i].nr[0] = P[stp-1][i];
			L[i].nr[1] = i + cnt < l ? P[stp - 1][i + cnt] : -1;
		}
		sort(L,L+l,compare);
		int rank = 0;
		for(i = 0;i < l;i++){
			if(i-1>=0){
				if(L[i].nr[0] != L[i-1].nr[0] || L[i].nr[1] != L[i-1].nr[1])
					rank++;
			}
			P[stp][L[i].i] = rank;
		}
		cnt = cnt<<1;
		stp++;
	}
}
int lcp(int x, int y)
{
	if(x == y)
		return s.length() - x;
	int ans  = 0;
	int i;
	for(i = stp - 1; i>=0 && x < s.length() && y < s.length();i--){
		if(P[i][x] == P[i][y]){
			ans += 1<<i;
			x += 1<<i;
			y += 1<<i;
		}
	}
	return ans;

}
int main()
{
	int t,l,i,j;
	LL lcpsum;
	cin>>t;
	while(t > 0){
		cin>>s;
		stp = 1;
		compute_suffix_array();
		l = s.length();
		lcpsum = 0;
		for(i=0;i<l-1;i++)
		{
			lcpsum = lcpsum + lcp(L[i].i,L[i+1].i);
		}
		LL l1 = s.length();
		LL ans = (l1 * (l1 + 1)) / 2 - lcpsum; //total Nc2 - sum of Longest common prefix
		cout<<ans<<endl;
		t--;
	}
}
