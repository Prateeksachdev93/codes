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


int tail, root, wordlen, printed;
char buffer[32];
struct Node {
	int next[27];
};

Node trie[200010];

int find(char *s) {
	int i, k, curr = root;
	for(i = 0; s[i]; i++) {
		k = s[i] - 'a';
		if(trie[curr].next[k] == -1) 
			return -1;//in case prefix is not found
		curr = trie[curr].next[k];
	}
	return curr;
}

void insert(char *s) {
	int i, k, curr = root;
	for(i = 0; s[i]; i++) {
		k = s[i] - 'a';
		if(trie[curr].next[k] == -1) {
			trie[curr].next[k] = tail;
			memset(trie[tail].next, -1, sizeof(int)*27);
			tail++;
		}
		curr = trie[curr].next[k];
	}
	trie[curr].next[26] = 0;
}



void print_matched(int curr, int len) 
{
	if(trie[curr].next[26] == 0 && len > wordlen)//proper prefix so length cannot be equal to wordlen
	 {
		buffer[len] = 0;
		puts(buffer);
		printed++;
	}
	for(int i = 0; i < 26; i++) {
		if(trie[curr].next[i] != -1) {
			buffer[len] = i + 'a';
			print_matched(trie[curr].next[i], len + 1);
		}
	}
}

int main() {
	int n, i,test_cases;
	int ret;
	char dict_word[32];
	char search_word[32];
	root = 0, tail = 1;
	int counter=0;
	memset(trie[root].next, -1, sizeof(int)*27);
	//freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%s", dict_word);
		insert(dict_word);
	}
	scanf("%d", &test_cases);
	while(test_cases--)
	{
		scanf("%s", search_word);
		printf("Case #%d:\n", counter+1);
		ret = find(search_word);
		if(ret == -1) 
			printf("No match.\n");
		else 
		{
			strcpy(buffer, search_word); printed = 0;
			print_matched(ret, wordlen = strlen(search_word));
			if(!printed) 
				printf("No match.\n");
		}
		counter++;
	}
	return 0;
}