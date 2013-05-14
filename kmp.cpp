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

void preKMP(string pattern, int f[])
{
        int m = pattern.length(),k;
        f[0] = -1;
        for (int i = 1; i<m; i++)
        {
                k = f[i-1];
                while (k>=0)
                {
                        if (pattern[k]==pattern[i-1])
                                break;
                        else
                                k = f[k];
                }
                f[i] = k + 1;
        }
}
  
bool KMP(string pattern, string target)
{
        int m = pattern.length();
        int n = target.length();
        int f[m];
         
        preKMP(pattern, f);
         
        int i = 0;
        int k = 0;
         
        while (i<n)
        {
                if (k==-1)
                {
                        i++;
                        k = 0;
                }
                else if (target[i]==pattern[k])
                {
                        i++;
                        k++;
                        if (k==m)
                                return 1;
                }
                else
                        k=f[k];
        }
        return 0;
}
int main()
{
	//pattern is  the string to be searched for
	string pat,targ;
	cin>>pat>>targ;
	cout <<KMP(pat,targ)<<endl;
	

	return 0;
}



