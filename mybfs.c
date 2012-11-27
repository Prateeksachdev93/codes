#include<stdio.h>
int queue[50];
int ind(int[],int,int);
int main()
{
	printf("enter the no.of vertices ");
	int n;
	int i,j;
	scanf("%d",&n);
	int dist[n];
	for(i=0;i<n;i++)
		dist[i]=0;
	int g[n],status[n];//given array of vertices,and status array
	printf("enter the vertices\n");
	for(i=0;i<n;i++)
	{scanf("%d",&g[i]);
			status[i]=0;
	}
	int obj[n][n];//adj matrix
	printf("enter the matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&obj[i][j]);
		}
	}
	int ind1=-1,ind2=-1;
	int root;
	printf("give the value of root node\n");
	scanf("%d",&root);
    ind1++;
	ind2++;
	int index;
	queue[ind1]=root;// queue of neighbours
	while(ind1<=ind2)
	{
		int val=queue[ind1];
		//printf("%d",val);
		index=ind(g,val,n);//returns the index of the  no in the array g[n]
		status[index]=1;
		for(j=0;j<n;j++)
			{
				if(obj[index][j]==1 && status[j]==0)
				{
					ind2++;
					queue[ind2]=g[j];
					dist[j]=dist[index]+1;
					status[j]=1;
				}
			}
			ind1++;
	}
	for(i=0;i<ind1;i++)
		printf("%d at dist %d\n",queue[i],dist[i]);
	printf("\n");
}
int ind(int a[],int val,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==val)
			return i;
	}
}


		

	

