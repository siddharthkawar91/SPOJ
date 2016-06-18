/***********************************

http://www.spoj.com/problems/CCHESS

***********************************/
#include<stdio.h>
#include<limits.h>

int dx[] = {2,2,-2,-2,-1,1,-1,1};
int dy[] = {-1,1,-1,1,2,2,-2,-2};
int Queue[10000];
int main()
{
	int SX,SY,X,Y;
	int T=0;
	long long int Visited[8][8];
	while(scanf("%d %d %d %d",&SX,&SY,&X,&Y)>0)
	{
		
			int row,col;
			/*for(row=0;row<8;row++)
				for(col=0;col<8;col++)
					Visited[row][col] = INT_MAX;*/
			
			memset(Visited,32345678,sizeof(Visited));			
			
			int wpos=0;
			int rpos=0;
			int k;
			int DX;
			int DY;
			
			Queue[wpos] = SX*1024 + SY;
			wpos++;
			Visited[SX][SY] = 0;
			int m=0;
			while(rpos<=wpos)
			{
				
				SX = Queue[rpos]/1024;
				SY = Queue[rpos]%1024;
				rpos++;
				for(k=0;k<8;k++)
				{
					DX = SX + dx[k];
					DY = SY + dy[k];
					
					if(DX >=0 && DX <= 7 && DY >=0 && DY <= 7 && Visited[DX][DY] > Visited[SX][SY] + SX*DX + SY*DY)
					{
						Visited[DX][DY] = Visited[SX][SY] + SX*DX + SY*DY;
						Queue[wpos] = 1024*DX + DY;
						wpos++;
					}
				}
				
			}
			printf("%d\n",Visited[X][Y]);
	}
	
}