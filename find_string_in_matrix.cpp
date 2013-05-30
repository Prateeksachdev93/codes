#include <stdio.h>
#include <cstring>
// we can go to any adjacent block even diagonal

int M,N;
int r[8]={1,1, 1,-1,-1,-1,0, 0};
int c[8]={1,0,-1, 1, 0,-1,1,-1};
char P[102][102];
int vis[102][102];
int isSafe(int x,int y,char *s)
{
  if(x>=0 && y>=0 && x<M && y<N && P[x][y]==*s && !vis[x][y])
  {
        return 1;
  }
  return 0;
}

int findNeighbour(char *s,int x,int y)
{
  int n;
  if(*s=='\0')
    return 1;

  if(isSafe(x,y,s))
  {
    vis[x][y]=1;

    for(n=0;n<8;n++)
    {
      if(findNeighbour(s+1,x+r[n],y+c[n])) 
        return 1;

    }
    vis[x][y]=0;

    return 0;
  }
  return 0;
}

void find(char *s)
{
  int i,j;
  for(i=0;i<M;i++)
  {
    for(j=0;j<N;j++)
    {
      if(P[i][j]==*s)
      {
        if(findNeighbour(s,i,j))
        {
         printf("YES\n");
         return;
       }
       
      
     }


   }
 }  
 
 printf("NO\n");
}

int main()
{
 int t;
 scanf("%d",&t);
 char str[]="ALLIZZWELL";//string to be searched for
 
 while(t--)
 {
  scanf("%d%d",&M,&N);

  for(int i=0;i<M;i++)
    scanf("%s",P[i]);


  for(int i=0;i<M;i++)
  {
    for(int j=0;j<N;j++)
      vis[i][j]=0;
  }
  
  find(str);
  }
return 0;
}