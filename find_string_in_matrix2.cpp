#include <stdio.h>
 
int M,N;
int r[8]={1,1, 1,-1,-1,-1,0, 0};
int c[8]={1,0,-1, 1, 0,-1,1,-1};
char P[102][102];

int isSafe(int x,int y,char *s)
{
  if(x>=0 && y>=0 && x<M && y<N && P[x][y]==*s)
    return 1;
  return 0;
}
 
int findNeighbour(char *s,int x,int y)
{
        int n;
        if(*s=='\0')
                return 1;
 
  if(isSafe(x,y,s))
   {
        for(n=0;n<8;n++)
        {
                if(findNeighbour(s+1,x+r[n],y+c[n])) return 1;
        }
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
         printf("The word has been found\n");
         return;
        }
      }
    }
  }  
 
   printf("\nThe word has not been found\n");
}
 
int main()
{
       // char P[M][N]={{'A','W','E','.','Q','X'},{'L','L','L','.','E','O'},{'I','Z','Z','W','L','L'}};
	     scanf("%d%d",&M,&N);
       
        for(int i;i<M;i++)
          scanf("%s",P[i]);
       
        char str[]="ALLIZZWELL";
 
        find(str);
        return 0;
}