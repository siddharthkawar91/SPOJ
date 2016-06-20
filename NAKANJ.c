/*************************************
Author :- Kawar Siddharth Rajendra
Problem Statement :-
http://www.spoj.com/problems/NAKANJ
*************************************/
#include<stdio.h>
#include<limits.h>
int Visited[8][8];

int SX,SY;
int X,Y;
int dx[] = {-2,2,1,-1,2,-2,1,-1};
int dy[] = {-1,-1,-2,-2,1,1,2,2};

int main()
{
	int TC;
	scanf("%d",&TC);
	int Queue[10000];
	while(TC--)
	{
		
		char str1[3],str2[3];
		scanf("%s %s",str1,str2);
		memset(Visited,0x0,sizeof(Visited));
		
		int i,j;
		for(i=1;i<=8;i++)
		{
			for(j=1;j<=8;j++)
				Visited[i][j] = INT_MAX;
		}
		
		SX = str1[0] - 96;
		SY = str1[1] - '0';
		
		X = str2[0] - 96;
		Y = str2[1] - '0';
		//printf("%d%d %d%d\n",SX,SY,X,Y);
		
		int rpos;
		int wpos;
		rpos=0;
		wpos=0;
		
		Queue[wpos] = SX*1024 + SY;
		//printf("Writing %d %d\n",Queue[wpos],wpos);
		Visited[SX][SY] = 1;
		wpos++;
		int k;
		//printf("%d%d %d%d\n",SX,SY,X,Y);
		
		while(rpos<=wpos)
		{
			
			//printf("Value at %d %d\n",Queue[rpos],rpos);
			SX = Queue[rpos]/1024;
			SY = Queue[rpos]%1024;
			
			//printf("%d %d\n",SX,SY);
			
			if(SX == X && SY == Y)
				break;
				
			rpos++;
			for(k=0;k<8;k++)
			{
				int DX = SX + dx[k];
				int DY = SY + dy[k];
				
				if(DX>=1 && DX<= 8 && DY>=1 && DY <= 8 && Visited[DX][DY] > Visited[SX][SY] + 1 )
				{
					//printf("%d %d\n",DX,DY);
					Visited[DX][DY] =  Visited[SX][SY] + 1;
					Queue[wpos]= DX*1024 + DY;
					wpos++;
				}
			}
		}
		
		printf("%d\n",Visited[X][Y]-1);
	}
	return 0;
}