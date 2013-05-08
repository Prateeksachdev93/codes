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
typedef long long ll ;
#define sd(n) scanf("%d",&n)
#define sc(n) scanf("%c",&n)
#define sf(n) scanf("%f",&n)
#define ss(n) scanf("%s",n)
#define pd(n) printf("%d\n",n)
#define pb push_back

#define SIEVE(a) ({int b=ceil(sqrt(a));vd d(a,0);vd e;int f=2;e.pb(2);e.pb(3);for(int x=1;x<b+1;x++){for(int y=1;y<b+1;y++){int n=(4*x*x)+(y*y);if(n<=a&&(n%12==1||n%12==5)){d[n]^=1;}n=(3*x*x)+(y*y);if(n<=a&&n%12==7){d[n]^=1;}n=(3*x*x)-(y*y);if(x>y&&n<=a&&n%12==11){d[n]^=1;}}}for(int r=5;r<b+1;r++){if(d[r]){for(int i=r*r;i<a;i+=(r*r)){d[i]=0;}}}for(int c=5;c<a;c++){if(d[c]){e.pb(c);}}e;})
template<class T> inline vector<pair<T,int> > FACTORISE(T n){vector<pair<T,int> >R;for (T i=2;n>1;){if (n%i==0){int C=0;for (;n%i==0;C++,n/=i);R.push_back(make_pair(i,C));}i++;if (i>n/i) i=n;}if (n>1) R.push_back(make_pair(n,1));return R;}
template<class T> inline T TOTIENT(T n) {vector<pair<T,int> > R=FACTORISE(n);T r=n;for (int i=0;i<R.size();i++)r=r/R[i].first*(R[i].first-1);return r;}

#define MOD 1000000007
int fact[1000003], invfact[1000003];
int powmod(int base, int expo){
	if(expo==0)
		return 1;
	else if(expo&1)
		return (long long)base*powmod(base, expo-1)%MOD;
	else{
		int root=powmod(base, expo>>1);
		return (long long)root*root%MOD;
	}
}
int inverse(int x){
	return powmod(x, MOD-2);
}
void init(){
	fact[0]=1;
	for(int i=1; i<=1000003; i++)
		fact[i]=(long long)i*fact[i-1]%MOD;
	invfact[1000002]=inverse(fact[1000002]);
	for(int i=1000002; i>0; i--)
		invfact[i-1]=(long long)i*invfact[i]%MOD;
}
long long C(int n, int r){
	if(r>n || r<0)
		return 0;
	return (long long)((long long)fact[n]*invfact[r]%MOD)*invfact[n-r]%MOD;
}
bool isexcell(long long int num,int a,int b)
{
	int x=num%10;
	//cout <<x<<endl;
	while(num>0)
	{
		if(x!=a && x!=b)
		{
			
			return false;
		}
		num/=10;
		x=num%10;

	}
	return true;
}
int main()
{
	init();
	int n;
	int a,b;
	sd(a);
	sd(b);
	sd(n);
	long long int sum=0;
	int ans=0;
	//cout << isexcell(111,1,3)<< endl;
	for(int i=0;i<=n;i++)
	{
		sum=a*i +b*(n-i);
		if(isexcell(sum,a,b))
		{
			ans=(ans+C(n,i))%MOD;
		}		
	}
	cout << ans<< endl;
	

	return 0;
}


