#include<stdio.h>
void quick(int[],int,int);
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	quick(a,0,n-1);
	for(i=0;i<n;i++)
		printf("%d",a[i]);
	printf("\n");

}
void quick(int a[],int start,int end)
{
	if(start<end)
	{
		int pivot=a[start];
		int l=start;
		int m=start+1;
		while(m<=end)
		{
			if(a[m]<pivot)
			{
				int temp=a[m];
				a[m]=a[l+1];
				a[l+1]=temp;
				l++;
			}
			m++;
		}
			int temp=a[start];
			a[start]=a[l];
			a[l]=temp;

		quick(a,0,l);
		quick(a,l+1,end);
	}
	else
		return;
}


