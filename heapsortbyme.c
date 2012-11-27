#include<stdio.h>
void restoreHup(int*,int);
void restoreHdown(int*,int,int);
void main()
{
	int a[200],n,i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		restoreHup(a,i);
	}
	int b[200]={0};
	int ind=0;
	//for(i=1;i<=n;i++)
	while(n)
	{
		b[ind++]=a[1];
		a[1]=a[n];
		n--;
		restoreHdown(a,1,n);
	}
	n=j;
	for(i=0;i<ind;i++)
		printf("%d-->",b[i]);
	printf("\n");
}
void restoreHup(int *a,int i)
{
	int v=a[i];

	while((i>1)&&(a[i/2]>v))
	{
		a[i]=a[i/2];
		i=i/2;
	}
	a[i]=v;
}

void restoreHdown(int *a,int i,int n)
{
	int j=i*2;
	while(j<=n)
	{
	if(a[j]<a[j+1])
	{
		if(a[i]>a[j])
		{
			int temp=a[j];
			a[j]=a[i];
			a[i]=temp;
			i=j;
		}
		else break;
	}
	else if(a[j]>a[j+1])
	{
		if(a[i]>a[j+1])
		{
			int temp=a[j+1];
			a[j+1]=a[i];
			a[i]=temp;
			i=j+1;
		}
		else break;
	}
	j=i*2;
	}
}



