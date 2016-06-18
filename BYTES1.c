/**********
http://www.spoj.com/problems/BYTESE1
**********/
#include<stdio.h>
#include<limits.h>
int MAT[128][128];
int Visited[128][128];
int Queue[1028*128];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
int main()
{
	int TC;
	scanf("%d",&TC);
	while(TC--)
	{
		int ROW,COL;
		int row,col;
		int DX,DY;
		int Timer;
		scanf("%d %d",&ROW,&COL);
		//memset(Visited,32345678,sizeof(Visited));
		for(row=1;row<=ROW;row++)
			for(col=1;col<=COL;col++)
			{
				scanf("%d",&MAT[row][col]);
				Visited[row][col] = INT_MAX;
			}
		scanf("%d %d %d",&DX,&DY,&Timer);
		
		/*for(row=1;row<=ROW;row++)
		{
			for(col=1;col<=COL;col++)
				printf("%d ",MAT[row][col]);
			
			printf("\n");
		}*/
		int rpos=0,wpos=0;
		Visited[1][1] = MAT[1][1];
		Queue[wpos] = 1024*1 + 1;
		wpos++;
		while(rpos<=wpos)
		{
			int X = Queue[rpos]/1024;
			int Y = Queue[rpos]%1024;
			rpos++;
			
			int k;
			for(k=0;k<4;k++)
			{
				int CX = X + dx[k];
				int CY = Y + dy[k];
				if(CX>=1 && CX<=ROW && CY >= 1 && CY <= COL && Visited[CX][CY] > MAT[CX][CY] + Visited[X][Y])
				{
					Visited[CX][CY] = MAT[CX][CY] + Visited[X][Y];
					//printf("%d %d %d",CX,CY,MAT[CX][CY]);
					Queue[wpos] = 1024*CX + CY;
					wpos++;
				}
			}
		}
		
		if((Timer - Visited[DX][DY])>=0)
		{
			printf("YES\n");
			printf("%d\n",Timer - Visited[DX][DY]);
		}	
		else
			printf("NO\n");
		/*for(row=1;row<=ROW;row++)
		{
			for(col=1;col<=COL;col++)
				printf("%d ",Visited[row][col]);
			
			printf("\n");
		}*/
		
	}
	
}