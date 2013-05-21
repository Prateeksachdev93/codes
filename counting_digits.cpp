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

int bucket[9];
int count1[10];
int count2[10];
void digicount(int num, int power, int cnt[], int firstloop)
{
	int n, i;
	n = num / bucket[power];
	//cout <<"n = " <<n<<endl;
	for(i=0;i<n;i++)
		cnt[i] += bucket[power];
	cnt[i] += num % bucket[power] + 1;
	if(firstloop) 
		cnt[0] -= bucket[power];
	if(power==0) 
		return;
	for(i=0;i<10;i++)
		cnt[i] += n*power*bucket[power-1];
	if(firstloop) 
		cnt[0] -= (bucket[power]-1)/9;
	digicount(num % bucket[power], power-1, cnt, 0);
}

int main()
{
	int p1, p2, i;
	int n1, n2, temp;
	bucket[0]=1;
	for(int i=1;i<=8;i++)
	{
		bucket[i]=bucket[i-1]*10;
	}
	while(scanf("%d%d",&n1,&n2))
	{

		if(n1==0 && n2==0)
			break;
		CLR(count1);CLR(count2);
		if(n1>n2)
		{
			temp = n1;
			n1 = n2;
			n2 = temp;
		}
		
		n1-=1;
		if(n1>0)
		{
			p1 = (int)floor(log10(n1));

			digicount(n1, p1, count1, 1);
		}
		p2 = (int)floor(log10(n2));
		
		digicount(n2, p2, count2, 1);
		
		printf("%d",count2[0]-count1[0]);

		for(i=1; i<10; i++)
			 printf(" %d",count2[i]-count1[i]);
		printf("\n");
	}
	return 0;
}
