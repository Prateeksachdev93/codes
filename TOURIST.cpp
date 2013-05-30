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
using namespace std;

int dp[200][100][100], visited[200][100][100];
int t, counter, rows, columns;

char grid[100][101];

int solve(int steps, int r1, int r2) {
	if(steps == rows + columns - 2) {
		
		if(steps-r1==columns-1 && r1==rows-1 && r1==r2) 
			return grid[r1][steps-r1]=='*';
		else return -1;
	}
	if(visited[steps][r1][r2] == counter) 
		return dp[steps][r1][r2];
	visited[steps][r1][r2] = counter;
	 
	dp[steps][r1][r2] = -1;
	int c1 = steps - r1, c2 = steps - r2;
	if(c1 < columns && c2 < columns && grid[r1][c1] != '#' && grid[r2][c2] != '#') 
	{
		dp[steps][r1][r2] = max(dp[steps][r1][r2], solve(steps + 1, r1, r2));

		if(r1 + 1 < rows) 
			dp[steps][r1][r2] = max(dp[steps][r1][r2] , solve(steps + 1, r1 + 1, r2));

		if(r2 + 1 < rows) 
			dp[steps][r1][r2] = max(dp[steps][r1][r2], solve(steps + 1, r1, r2 + 1));

		if(r1 + 1 < rows && r2 + 1 < rows) dp[steps][r1][r2] = max(dp[steps][r1][r2], solve(steps + 1, r1 + 1, r2 + 1));

		if(dp[steps][r1][r2] != -1) {
			if(grid[r1][c1] == '*') dp[steps][r1][r2]++;
			if(r1 != r2 && grid[r2][c2] == '*') dp[steps][r1][r2]++;
		}
	}
	return dp[steps][r1][r2];
}

int main() {
	scanf("%d", &t);
	for(counter = 1; counter <= t; counter++) {
		scanf("%d %d", &columns, &rows);
		for(int i = 0; i < rows; i++) 
			scanf("%s", grid[i]);
		printf("%d\n", solve(0, 0, 0));
	}
	return 0;
}