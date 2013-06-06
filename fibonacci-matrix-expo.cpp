#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <utility>
using namespace std;

#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))


const double EPS = 1e-9;
const double BIG = 1e15;
const int NIL = 0;
const int INF = 0x3f3f3f3f;
const int MAX = 4, MOD = 1000000007;

long long int mat[MAX][MAX], resmat[MAX][MAX], a[MAX];
//indexing starts from 1
void multi(long long int x[MAX][MAX], long long int y[MAX][MAX], long long int n) {
	long long int r[MAX][MAX] = {0}, i, j, k;
	long long int temp;
	for(i = 1; i <= n; i++) {
		for(j = 1; j <= n; j++) {
			for(k = 1; k <= n; k++) {
				temp = (x[i][k]%(MOD-1)* y[k][j]%(MOD-1))%(MOD-1)+r[i][j];
				r[i][j] = temp;
			}
		}
	}
	CPY(x, r);
}

void expo(long long int p, long long int n) {
	if(!p) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++)
				resmat[i][j] = 0;
			resmat[i][i] = 1;
		}
	}
	else if(p & 1) {
		expo(p-1, n);
		multi(resmat, mat, n);
	}
	else {
		expo(p >> 1, n);
		multi(resmat, resmat, n);
	}
}


int main() {

	long long int t, i, j, k, n,n1;
	long long int sum, temp;
	int res1;
	scanf("%lld", &t);
	mat[1][1]=1;mat[1][2]=1;mat[2][1]=1;mat[2][2]=0;
	while(t--) {
			scanf("%lld",&n);
			
			expo(n,2);//sum till n1-1
			res1=resmat[1][1];

			printf("%d\n", res1);
			

		}
		return 0;
	}