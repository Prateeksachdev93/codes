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

#define SIEVE(a) ({int b=ceil(sqrt(a));vd d(a,0);vd e;int f=2;e.pb(2);e.pb(3);for(int x=1;x<b+1;x++){for(int y=1;y<b+1;y++){int n=(4*x*x)+(y*y);if(n<=a&&(n%12==1||n%12==5)){d[n]^=1;}n=(3*x*x)+(y*y);if(n<=a&&n%12==7){d[n]^=1;}n=(3*x*x)-(y*y);if(x>y&&n<=a&&n%12==11){d[n]^=1;}}}for(int r=5;r<b+1;r++){if(d[r]){for(int i=r*r;i<a;i+=(r*r)){d[i]=0;}}}for(int c=5;c<a;c++){if(d[c]){e.pb(c);}}e;})
template<class T> inline vector<pair<T,int> > FACTORISE(T n){vector<pair<T,int> >R;for (T i=2;n>1;){if (n%i==0){int C=0;for (;n%i==0;C++,n/=i);R.push_back(make_pair(i,C));}i++;if (i>n/i) i=n;}if (n>1) R.push_back(make_pair(n,1));return R;}
template<class T> inline T TOTIENT(T n) {vector<pair<T,int> > R=FACTORISE(n);T r=n;for (int i=0;i<R.size();i++)r=r/R[i].first*(R[i].first-1);return r;}

// vd v=SIEVE(2100);
// int n=TOTIENT(num);
int minLexCyc(string x) {
    int i = 0, j = 1, k = 1, p = 1, a, b, l = x.length();
    while(j+k <= (l<<1)) {
        if ((a=x[(i+k-1)%l])>(b=x[(j+k-1)%l])) {
            i=j++;
            k=p=1;
        } else if (a<b) {
            j+=k; 
            k=1; 
            p=j-i;
        } else if (a==b && k!=p) {
            k++;
        } else {
            j+=p; 
            k=1;
        }
    }
    return i;
}
int main()
{
	int t;
	string s;
	int pos;
	sd(t);
	while(t--)
	{
		cin>>s;
		pos=minLexCyc(s);
		cout << pos+1<<endl;
	}

	return 0;
}



