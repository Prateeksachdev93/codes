#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int m[n][n];
	int w[n][n],mp[n][n];
	int i,j,k;
	int engagedmen[n];
	int engagedwomen[n];
	for(i=0;i<n;i++)
	{
		engagedmen[i]=-1;
		engagedwomen[i]=-1;
		for(j=0;j<n;j++)
			scanf("%d",&m[i][j]);
	}
	for(i=0;i<n;i++)
	{
			int temp=0;
		for(j=0;j<n;j++)
		{
			int temp2;
			scanf("%d",&temp2);
			w[i][temp2]=temp;
			temp+=1;
		}
	}
	int flag=0;
	while(flag==0)
	{
		int woman;
		flag=1;
		for(i=0;i<n;i++)
		{
			if(engagedmen[i]!=-1)
				continue;
			for(j=0;j<n;j++)
			{
				if(m[i][j]!=-1)
				{
					 woman=m[i][j];
					m[i][j]=-1;
				}
				else
					continue;
			if(engagedwomen[woman]==-1)
			{
				engagedwomen[woman]=i;
				engagedmen[i]=woman;
				break;
			}
			else
			{
				if(w[woman][engagedwomen[woman]]>w[woman][i])
				{
					engagedmen[engagedwomen[woman]]=-1;
					engagedmen[i]=woman;
					engagedwomen[woman]=i;
					flag=0;
					break;
				}
			}
			}



		}



	}
	for(i=0;i<n;i++)
	{
		printf("%d %d\n",i,engagedmen[i]);
	}



}

