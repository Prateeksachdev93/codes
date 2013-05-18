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
const int MAX = 11, MOD = 1000000000;

int mat[MAX][MAX], resmat[MAX][MAX], a[MAX];
//indexing starts from 1
void multi(int x[MAX][MAX], int y[MAX][MAX], int n) {
	int r[MAX][MAX] = {0}, i, j, k;
	long long int temp;
	for(i = 1; i <= n; i++) {
		for(j = 1; j <= n; j++) {
			for(k = 1; k <= n; k++) {
				temp = x[i][k];temp *= y[k][j];temp += r[i][j];temp %= MOD;
				r[i][j] = temp;
			}
		}
	}
	CPY(x, r);
}

void expo(int p, int n) {
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
	
	int t, i, j, k, n;
	long long int sum, temp;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &k);
		for(i = k; i; i--) scanf("%d", &a[i]);
		for(j = 1; j <= k; j++) scanf("%d", &mat[1][j]);
		scanf("%d", &n);
		if(n <= k) printf("%d\n", a[k-n+1] % MOD);
		else {
			for(i = 2; i <= k; i++) {
				for(j = 1; j <= k; j++) 
					mat[i][j] = 0;
				mat[i][i-1] = 1;
			}
			expo(n-k, k);
			sum = 0;
			
			for(i = 1; i <= k; i++) {
				temp = resmat[1][i];
				temp *= a[i];
				sum += temp;
				sum %= MOD;
			}
			printf("%d\n", (int)sum);
		}
	}
	return 0;
}
