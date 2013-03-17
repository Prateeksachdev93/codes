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

#define sd(n) scanf("%d",&n)
#define sc(n) scanf("%c",&n)
#define sf(n) scanf("%f",&n)
#define ss(n) scanf("%s",n)

//to remove kth and then 2*k th and so on people
int josephus_modified(int n ,int k,int m)
{

	if(n==1)
		return 0;
	else
		return (josephus_modified(n-1,k,m+1) + m*k) %n;
}

int main()
{

	int n;
	int k;
	sd(n);
	sd(k);
	int index=josephus_modified(n,k,1);
	printf("%d\n",index+1);
	return 0;
}

