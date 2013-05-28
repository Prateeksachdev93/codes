#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <memory>
#include <iomanip>
#include <functional>
#include <new>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cctype>
#include <ctime>

#define REP(i, n) for((i) = 0; i < n; i++)
#define FOR(i, a, n) for((i) = a; i < n; i++)
#define FORR(i, a, n) for((i) = a; i <= n; i++)
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

using namespace std;

typedef long long ll;
typedef long double ld;

#define MAXN 1000005

ll INF = (ll) (1LL << 60LL);
pair<ll, ll> t[MAXN*4+10];

int n, v[MAXN+10];

void build(int x, int tl, int tr){
	if (tl == tr)
	{
		t[x].first = v[tl];
		t[x].second = v[tl];
	}
	else {
		int tm = (tl + tr) >> 1;
		build ( 2*x,tl,tm);
		build ( 2*x+1,tm+1,tr);
		t[x].first = min (t[2*x].first,t[2*x+1].first);
		t[x].second = max (t[2*x].second,t[2*x+1].second);
	}
}


ll rmaxq (int x, int tl, int tr, int l, int r){
	ll p1,p2;
	if (tl>r||tr<l) {
		return -1;
	}
	if (tl >= l && tr <= r) {
		return t[x].second;
	}
	int tm = (tl + tr) >> 1;

	p1 = rmaxq(2*x,tl,tm,l,r);
	p2 = rmaxq(2*x+1,tm+1,tr,l,r);
	if(p1==-1)
		return p2;
	if(p2==-1)
		return p1;
	return max(p1,p2);
}
ll rmq (int x, int tl, int tr, int l, int r){
	ll p1,p2;
	if (tl>r||tr<l) {
		return -1;
	}
	if (tl >= l && tr <= r) {
		return t[x].first ;
	}
	int tm = (tl + tr) >> 1;

	p1 = rmq(2*x,tl,tm,l,r);
	p2 = rmq(2*x+1,tm+1,tr,l,r);
	if(p1==-1)
		return p2;
	if(p2==-1)
		return p1;
	return min(p1,p2);

}
/*
Array indexing from (1-n)
for max rmaxq(1, 1, n, ll, ul);
*/

int main(void) {

	int n;
	int i;
	
	int k;
	int q1,q2;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&v[i]);

	}
	build( 1, 1, n);

	ll maxi,mini;
	maxi=rmaxq(1, 1, n, 1, n);
	mini=rmq(1, 1, n, 1, n);
	cout << "max " << maxi << "min "<<mini; 

	printf("\n");
	




	return 0;
}