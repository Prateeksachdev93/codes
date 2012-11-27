#include<stdio.h>
int a[2][2]={{0,1},{1,1}};
void matmul();
void mul();
void power(int m);
int main()
{
	int m;
	scanf("%d",&m);
	power(m-1);
	printf("%d\n",a[1][1]);

}
void power(int m)
{	
	if(m==0 || m==1) 
		return ;
	power(m/2);
	matmul();
	if(m%2!=0)
		mul();
}
void matmul()
{
	int x=a[0][0]*a[0][0] + a[0][1]*a[1][0];
	int y=a[0][0]*a[0][1] + a[0][1]*a[1][1];
	int z=a[1][0]*a[0][0] + a[1][1]*a[1][0];
	int w=a[1][0]*a[0][1] + a[1][1]*a[1][1];
	a[0][0]=x;
	a[0][1]=y;
	a[1][0]=z;
	a[1][1]=w;
}
void mul()
{
	int x=a[0][0]*0 + a[0][1]*1;
	int y=a[0][0]*1 + a[0][1]*1;
	int z=a[1][0]*0 + a[1][1]*1;
	int w=a[1][0]*1 + a[1][1]*1;
	a[0][0]=x;
	a[0][1]=y;
	a[1][0]=z;
	a[1][1]=w;
}
