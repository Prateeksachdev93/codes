#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define edge pair< int, int >
#define MAX 1001

// ( w (u, v) ) format
vector< pair< int, edge > > GRAPH, MST;
int parent[MAX], total, N, E;

int findset(int x, int *parent)
{
    if(x != parent[x])
        parent[x] = findset(parent[x], parent);
    return parent[x];
}

void kruskal()
{
    int i, pu, pv;
    sort(GRAPH.begin(), GRAPH.end()); // increasing weight
    for(i=total=0; i<GRAPH.size(); i++)
    {
        pu = findset(GRAPH[i].second.first, parent);
        pv = findset(GRAPH[i].second.second, parent);
        if(pu != pv)
        {
            MST.push_back(GRAPH[i]); // add to tree
            total += GRAPH[i].first; // add edge cost
            parent[pu] = parent[pv]; // link
        }
    }
}

void reset()
{
    // reset appropriate variables here
    // like MST.clear(), GRAPH.clear(); etc etc.
    for(int i=1; i<=N; i++) parent[i] = i;
}

void print()
{
    int i, sz;
    // this is just style...
    sz = MST.size();
    for(i=0; i<sz; i++)
    {
        printf("%c-%c", 'A' -1 +MST[i].second.first,'A'-1 +MST[i].second.second);
        
        printf(" %d\n", MST[i].first);
    }
    //printf("Minimum cost: %d\n", total);
}

int main()
{
    int i, u, v, w;
    int t;
    int cc=0;
    scanf("%d",&t);
    while(t--)
    {
    	cc++;
    scanf("%d", &N);
    reset();
    for(int i=1;i<=N;i++)
    {
    	for(int j=1;j<=N;j++){
    		scanf("%d,", &w);
    		if(w)
    		{
    			
    			GRAPH.push_back(pair< int, edge >(w, edge(i, j)));
    		}
    	}
    }
    kruskal(); // runs kruskal and construct MST vector
    printf("Case %d:\n",cc );
    print(); // prints MST edges and weights
    GRAPH.clear();
    MST.clear();
	}

    return 0;
}