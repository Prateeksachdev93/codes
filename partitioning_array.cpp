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


int p[501], sumarray[501];
/*

find the optimum sum for each partition using binary search between avg/max value and total sum of elements
check if this sum is possible for the given number of partitions



*/
bool possible( int total,  int partitions,  long long optimum)
{
    int k = 0;
    
    for(int i = total; i >= 1;)
    {
        long long temp = 0;
        
        for(int j = i-1; j >= 0; j--)
        {
            if(sumarray[i] - sumarray[j] > optimum)
            {
                temp = j + 1;
                break;
            }
        }
        
        i = temp, k++;
    }
    
    return (k <= partitions);
}

long long b_search( int total,  int partitions, long long begin, long long end)
{
    long long temp;
    
    while(begin < end)
    {
        temp = (begin + end) / 2;
        
        if(possible(total, partitions, temp))
            end = temp;
        else
            begin = temp + 1;
    }
    
    return end;
}
void print_result( int total,  int partitions,  long long optimum)
{
    int k = 0;
    long long temp;
    bool partition_index[total];
    
    for(int i = 0; i < total; i++)
        partition_index[i] = false;//none has to be partitioned
    
    for(int i = total; i >= 1;)
    {
        temp = 0;
        
        for(int j = i-1; j >= 0; j--)
        {
            if(sumarray[i] - sumarray[j] > optimum)
            {
                temp = j + 1;
                break;
            }
        }
        
        i = temp, k++;
        partition_index[i] = true;
    }
    
    temp = 1;
    
    while(k < partitions)//if number of partitions remaining
    {
        if(!partition_index[temp])
            partition_index[temp] = true, k++;
        
        temp++;
    }
    
    for(int j = 1; j < total; j++)
    {
    	printf("%d ",p[j]);
        
        
        if(partition_index[j])
            printf("/ ");
    }
    
    pd(p[total]);
}


int main()
{
    int t;
    long long sum, avg, max_value, optimum;
    int total, partitions;
    sd(t);
    
   while(t--)
    {
        
        
        sd(total);
        sd(partitions);
        sumarray[0] = sum = max_value = 0;
        
        for(int i = 1; i <= total; i++)
        {
            sd(p[i]);
            if(max_value<p[i])
            	max_value=p[i];
            sumarray[i] = sumarray[i-1] + p[i];
            sum += p[i];
            
        }
        
        avg = sum / partitions;
        if(avg<max_value)
        	avg=max_value;
        optimum = b_search(total, partitions, avg, sum);
        print_result(total, partitions, optimum);
    }
    
    return 0;
}


