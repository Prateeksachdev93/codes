//
//  spoj: BABTWR
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

const int MAX=110;
int cc;
int ans;
struct box
{
	int h,w,d;
};
box BOX[MAX];
int msh[MAX];//max stack height if i-th is on the top

int solve()
{
	ans=-1;
	for(int i=0;i<cc;i++)
	{
		msh[i]=BOX[i].h;
	}
	for(int i=1;i<cc;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(BOX[i].w<BOX[j].w && BOX[i].d<BOX[j].d && msh[i]<msh[j]+BOX[i].h)
				msh[i]=msh[j]+BOX[i].h;
		}
	}
	for(int i=0;i<cc;i++)
	{
		if(ans<msh[i])
			ans=msh[i];
	}
	return ans;
}
int compare (const void *a, const void *b)//to sort all the boxes in decreasing order of their base area
{
    return  ((*(box *)b).d * (*(box *)b).w ) -( (*(box *)a).d * (*(box *)a).w ) ;
}
int main()
{
	int n,hh,ww,dd;
	
	while(sd(n) && n)
	{
			cc=0;
			
			for(int i=0;i<n;i++)
			{
				sd(hh);sd(ww);sd(dd);
				BOX[cc].h=hh;BOX[cc].w=min(ww,dd);BOX[cc].d=max(ww,dd);//always assuming that base < depth
				cc++;
				BOX[cc].h=ww;
				BOX[cc].w=min(hh,dd);
				BOX[cc].d=max(hh,dd);
				cc++;
				BOX[cc].h=dd;
				BOX[cc].w=min(hh,ww);
				BOX[cc].d=max(hh,ww);
				cc++;
			}
			qsort(BOX,cc,sizeof(BOX[0]),compare);
			pd(solve());
	}

	return 0;
}



