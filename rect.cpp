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
using namespace std;

const int MAX = 300020;
pair<int, int> px[MAX], py[MAX];

#define getcx getchar_unlocked
#define putcx putchar_unlocked

inline void readInt( int &n ) {
	n=0;
	int ch=getcx();
	while( ch < '0' || ch > '9' ){ch=getcx();}
	while(  ch >= '0' && ch <= '9' )
		n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
}


inline int get( const pair<int ,int> &p, char c) 
{
	return (c=='x')? p.first : p.second;
}


inline bool sortByX(const pair<int,int> &a, const pair<int ,int> &b) 
{
	return (a.first == b.first)? a.second < b.second : a.first < b.first;
}

inline bool sortByY(const pair<int,int> &a, const pair<int,int> &b) 
{
	return (a.second == b.second)? a.first < b.first : a.second < b.second;
}

int LowerBound(char c, pair<int,int> *p, int a, int b, int v) 
{
	int range = b - a, mid, i;
	while(range > 0) 
	{
		mid = range >> 1;
		i = a + mid;
		if(get(p[i], c) < v) a = ++i, range -= mid+1;
		else range = mid;
	}
	return a;
}

int upperBound(char c, pair<int,int> *p, int a, int b, int v) {
	int range = b - a, mid, i;
	while(range > 0) {
		mid = range >> 1;
		i = a + mid;
		if(get(p[i], c) <= v) a = ++i, range -= mid+1;
		else range = mid;
	}
	return a;
}


int main() {
	int n, i, q, x1, y1, x2, y2;
	int intersections, lb, ub, rl, rr,tempx,tempy;
	
	readInt(n);
	for(i = 0; i < n; i++) {
		readInt(tempx);
		readInt(tempy);
		px[i]=py[i]=make_pair(tempx,tempy);
		
	}
	sort(px, px + n, sortByX);//sort by x
	sort(py, py + n, sortByY);//sort by y
	readInt(q);
	while(q--) {
		readInt(x1);
		readInt(y1);
		readInt(x2);
		readInt(y2);

		intersections = 0;
		lb = LowerBound('y', py, 0, n, y1);
		ub = upperBound('y', py, lb, n, y1);
		rl = LowerBound('x', py, lb, ub, x1);
		rr = upperBound('x', py, rl, ub, x2) - 1;

		if(rr - rl + 1 > 0) intersections += rr - rl + 1;

		lb = LowerBound('y', py, 0, n, y2);
		ub = upperBound('y', py, lb, n, y2);
		rl = LowerBound('x', py, lb, ub, x1);
		rr = upperBound('x', py, rl, ub, x2) - 1;

		if(rr - rl + 1 > 0) intersections += rr - rl + 1;

		lb = LowerBound('x', px, 0, n, x1);
		ub = upperBound('x', px, lb, n, x1);
		rl = LowerBound('y', px, lb, ub, y1+1);
		rr = upperBound('y', px, rl, ub, y2-1) - 1;

		if(rr - rl + 1 > 0) intersections += rr - rl + 1;

		lb = LowerBound('x', px, 0, n, x2);
		ub = upperBound('x', px, lb, n, x2);
		rl = LowerBound('y', px, lb, ub, y1+1);
		rr = upperBound('y', px, rl, ub, y2-1) - 1;

		if(rr - rl + 1 > 0) intersections += rr - rl + 1;
		printf("%d\n", intersections);
	}
	return 0;
}
