//code to find maximum length pallindromic substring in O(n) and finding all 
//substrings of this maximum length
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

void manacher(string &);

int m[7000];
int main()
{
	int t;
	sd(t);
	char ch;
	sc(ch);
	int max=-1;
	int count=0;
	while(t--)
	{
		string s;
		cin >> s;
		manacher(s);
		for(int i=0;i<=2*s.length()+1;i++)
		{
			if(m[i]>=max)
				max=m[i];
		}
		for(int i=0;i<=2*s.length()+1;i++)
		{
			if(m[i]==max)
				count++;
		} 
		printf("%d %d\n",max,count);
		max=-1;
		count=0;
		memset(m,0,sizeof(m));
		

	}
	return 0;
}

void manacher(string &s)
{
int len = s.length();
if(len == 0) return;

m[0] = 0;
m[1] = 1;
int cur, r;
r = 2;
cur = 1;

for(int p2=2; p2<2*len+1; p2++)
{
int p1 = cur- (p2-cur);
//if p1 is negative, we need to
//move "cur" forward
while(p1 < 0)
{
cur++;
r = m[cur] + cur;
p1 = cur- (p2-cur);

}

if(m[p1] < r - p2)
m[p2] = m[p1];
else
{
cur = p2;
int k = r-p2;
if(k<0) k = 0;
while(1)
{
if((p2+k+1)&1)
{
if(p2+k+1 < 2*len+1 && p2-k-1 >=0 && s[(p2+k)/2] == s[(p2-k-2)/2])
k++;
else break;
}
else
{
if(p2+k+1 < 2*len+1 && p2-k-1 >=0)
k++;
else break;
}

}

r = p2+k;
m[p2] = k;
}


}


}