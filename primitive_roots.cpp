//
// main.cpp
//
// Created by Prateek Sachdev
// Copyright (c) 2013 Prateek Sachdev. All rights reserved.
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

vd prime_nos;
int power(long long int num,int pow, int M)
{

    if (pow == 0) return 1;
    if (pow % 2 == 0)
        return power(((num%M)*(num%M))%M, pow / 2,M)%M;
    else
        return ((power(num, pow - 1,M)%M) * (num%M))%M;
}


int factorize(long long int n,int *factors)
{
	int i, limit = (int)sqrt(n), factor_c = 0;
	for(i = 0; prime_nos[i] <= limit; i++)
	{
		if(n % prime_nos[i]==0)
		{
			factors[factor_c++] = prime_nos[i];
			while(n % prime_nos[i]==0) n /= prime_nos[i];
			limit = (int)sqrt(n);
		}
	}
	if(n>1) 
		factors[factor_c++] = n;
	return factor_c;
}
int main()
{
	prime_nos=SIEVE(46356);//prime numbers till sqrt(max);
	int factors[40];//for 2^31 factor count is around 32
	int factor_count;
	long long int p,n;
	long long int r;
	int i;
	while(1)
	{
		

		scanf("%lld%lld",&p,&n);
		if(!p && !n)
			break;
		else
		{
			factor_count=factorize(p-1,factors);//here p:prime so phi(p)=p-1; else factorize(phi(p))
			
			while(n--)
			{
				scanf("%lld",&r);

				for(i=0;i<factor_count;i++)
				{
					
					if(power(r,(p-1)/factors[i],p)==1)
						break;
					
				}
				if(i==factor_count)
					printf("YES\n");
				else
					printf("NO\n");
			}

		}
	}
	return 0;
}

