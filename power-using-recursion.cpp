#include <cstdio>
#include <iostream>

using namespace std; 

#define M 10000000007
long long int power(long long int n,long long int m);
int main()
{
	long long int n,m;
	cin >> n>> m;
	long long int x=power(n,m);
	cout << x <<endl;

}


long long int power(long long int num, long long int pow)
{
	//cout << num<<endl;
    if (pow == 0) return 1;
    if (pow % 2 == 0)
        return power(((num%M)*(num%M))%M, pow / 2)%M;
    else
        return ((power(num, pow - 1)%M) * (num%M))%M;
}