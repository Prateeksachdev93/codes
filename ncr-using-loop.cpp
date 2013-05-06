#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <list>
#include <queue>
#define LL long long
#define M 1000000007
using namespace std;
LL n,nCr[1001][1001];
/************ code for nCr % m *****************/
/************
	using nCr = (n-1) C (r-1)  + (n-1) C r
**************/
int main(){
	cin >> n ;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=i;j++){
			if(j==0 || j==i) nCr[i][j]=1;
			else nCr[i][j]=(nCr[i-1][j-1]+nCr[i-1][j])%M;
		}
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			printf("%d C %d = %lld\n",i,j,nCr[i][j]);
		}
	}
}