#include<stdio.h>
int power(int n,int m);
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int x=power(n,m);
	printf("%d\n",x);

}
int power(int n,int m)
{
	if(m==0)
	{
		return 1;
	}
	if(m%2==0)
	{
		return power(n,m/2)*power(n,m/2);
	}
	else
	{
		return n*power(n,m/2)*power(n,m/2);
	}
}
