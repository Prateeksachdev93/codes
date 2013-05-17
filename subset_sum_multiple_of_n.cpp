//
//  main.cpp
//
//  Created by Prateek Sachdev 
//  Copyright (c) 2013 Prateek Sachdev. All rights reserved.
//
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstring>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <iostream>

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

int mod[100002],sweets[100002],flagmod[100002];
int main()
{
	int c,n;	
	/*
		(index of)subset of elements in an array of size n whose sum is a multiple of c
	    n>=c 
	    ends when c=n=0
	*/
	sd(c);sd(n);
	int sum=0,ll,ul;
	while(1)
	{

		
		if(c==0 && n==0)
			break;

		sum=0;
		CLR(mod);
		CLR(flagmod);
		for(int i=1;i<=n;i++)
			sd(sweets[i]);
		flagmod[0]=1;
		for(int i=1;i<=n;i++)
		{
			sum+=sweets[i];sum%=c;
			if(flagmod[sum])
			{
				ll=mod[sum]+1;ul=i;
				break;
			}
			flagmod[sum]=1;
			mod[sum]=i;
		}
		for(int i=ll;i<=ul;i++)
		{
			printf("%d ",i);
		}
		printf("\n");

		sd(c);sd(n);
	}


	return 0;
}



