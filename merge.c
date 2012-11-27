#include<stdio.h>
void merge(int a[],int ll,int ul);
void mergesort(int a[],int low,int high,int mid);
int main()
{
	int n;
	scanf("%d",&n);
	int a[100];
	int i,j;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	merge(a,0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");


}
void merge(int a[],int ll,int ul)
{
	if(ll<ul)
	{
		int mid=(ll+ul)/2;//lower limit and upper limit
		merge(a,ll,mid);
		merge(a,mid+1,ul);
		mergesort(a,ll,ul,mid);
	}
	return ;

}
void mergesort(int a[],int low,int high,int mid)
{
	int c[50];
	int i=low;
	int j=mid+1;
	int k=low;
	while((i<=mid)&&(j<=high))
	{
		if(a[i]<a[j])
		{
			c[k]=a[i];
			k++;
			i++;
		}
		else
		{
			c[k]=a[j];
			k++;
			j++;
		}
	}
	while(i<=mid)
	{
		c[k]=a[i];
		k++;
		i++;
	}
	while(j<=high)
	{
		c[k]=a[j];
		k++;
		j++;
	}
	for(i=low;i<k;i++)
	{
		a[i]=c[i];
	}
} 



