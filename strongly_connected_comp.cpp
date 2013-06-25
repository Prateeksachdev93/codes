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

#define MAXN 100002

using namespace std;

vd G[ MAXN + 1 ], G_Transpose[ MAXN + 1 ];
int outdegree[MAXN];
vd S;
bool visited[ MAXN + 1 ];
int component[ MAXN + 1 ];
int answer[ MAXN + 1 ];
int n, m;
vd result;
int component_number=0;

void dfs1( int vertex ) {
    visited[ vertex ] = true;
    for (int i = 0; i < G[ vertex ].size(); ++i ) 
    {
        if ( !visited[ G[ vertex ][ i ] ] ) 
        {
            dfs1( G[ vertex ][ i ] );
        }
    }
    S.push_back( vertex );
}

void dfs2( int vertex, int c ) {
    visited[ vertex ] = false;
    component[ vertex ] = c;
    
    for (int i = 0; i < G_Transpose[ vertex ].size(); ++i ) 
    {
        if ( visited[ G_Transpose[ vertex ][ i ] ] ) 
        {
            dfs2( G_Transpose[ vertex ][ i ], c );
        }
    }
}
int findcomponent()
{
	int index=-1;
	for(int i=0;i<component_number;i++)
	{
		if(outdegree[i]==0)
		{
			if(index!=-1)
				return -1;
			else
				index=i;
		}
	}
	return index;
}
int main() 
{
    /***************************** STRONGLY CONNECTED COMPONENTS**************************/
    int i, j, u, v;
    int sz=0;
    
    int comp;
    
        scanf( "%d", &n );
    
        scanf( "%d", &m );
        //clear
        for ( i = 0; i <= n; ++i ) {
            G[ i ].clear();
            G_Transpose[ i ].clear();
            visited[ i ] = false;
        }
        S.clear();
        
        for ( i = 0; i < m; ++i ) {
            scanf( "%d%d", &u, &v );
            G[ u ].push_back( v );
            G_Transpose[ v ].push_back( u );
        }
        for ( i = 1; i <= n; ++i ) {
            if ( !visited[ i ] ) {
                dfs1( i );
            }
        }
        component_number = 0;
        for ( i = S.size() - 1; i >= 0; --i ) {
            if ( visited[ S[ i ] ] ) {
                dfs2( S[ i ], component_number);
                answer[component_number] = true;
                component_number++;
            }

        }
        //cout << component_number<<endl;
        for ( i = 1; i <= n; ++i ) {
            for ( j = 0; j < G[i].size(); ++j ) {
                if ( component[i] != component[G[i][j]] ) {
                    outdegree[component[i]]++;
                    break;
                }
            }
        }
        /***************************** STRONGLY CONNECTED COMPONENTS**************************/
        
        comp=findcomponent();
        for(int i=1;i<=n;i++)
        {
        	if(component[i]==comp)
        	{
        		result.push_back(i);
        		sz++;
        	}
        }
        printf("%d\n%d", sz,result[0]);
        for(int i=1;i<result.size();i++)
        	printf(" %d",result[i] );

        
        printf("\n");
    
    
    return 0;
}
