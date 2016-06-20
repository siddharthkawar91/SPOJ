/*************************************
Author :- Kawar Siddharth Rajendra
Problem Statement :-
http://www.spoj.com/problems/SHOP
*************************************/
#include<stdio.h>
#include<limits.h>
int Visited[30][30];
char MATRIX[30][30];
int Queue[20000];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int WIDTH,HEIGHT;
int e[2][2];
int main()
{
	
	char Dum[30];
	while(scanf("%d %d",&WIDTH,&HEIGHT))
	{
		if(WIDTH == 0 && HEIGHT ==0)
		 break;
		 
		int rpos=0,wpos=0;
		int DX,DY;
		int i,j;
		for(i=1;i<=HEIGHT;i++)
		{
			for(j=1;j<=WIDTH;j++)
			Visited[i][j] = INT_MAX;
		}
		
		for(i=1;i<=HEIGHT;i++)
		{
			scanf("%s",Dum);
			for(j=1;j<=WIDTH;j++)
			{
				
				if(Dum[j-1] == 'X')
				{
					Visited[i][j] = -1;
					MATRIX[i][j] = -1;
				}	
				else if(Dum[j-1] == 'S')
				{
					Queue[wpos] = 1024*i + j;
					wpos++;
					e[0][0] = i;
					e[0][1] = j;
					MATRIX[i][j] = 0;
					Visited[i][j] = 0;
				}
				else if(Dum[j-1] == 'D')
				{
					DX = i, DY = j;
					
					MATRIX[i][j] = 0;
					Visited[i][j] = INT_MAX;
				}
				else
					MATRIX[i][j] = Dum[j-1] - '0';
			}
		}
		
		DFS(e[0][0],e[0][1]);
		/*while(rpos<=wpos)
		{
			int X = Queue[rpos]/1024;
			int Y = Queue[rpos]%1024;
			
			rpos++;
			if(X == DX && Y == DY)
				continue;
			//printf("%d %d\n",X,Y);
			int k;
			for(k=0;k<4;k++)
			{
				int KX = X + dx[k];
				int KY = Y + dy[k];
				//printf("+%d %d+\n",KX,KY);
				if(KX>=1 && KX<=HEIGHT && KY>=1 && KY <= WIDTH && Visited[KX][KY] != -1 && Visited[KX][KY] > Visited[X][Y] + MATRIX[KX][KY])
				{
					//printf("-%d %d-\n",KX,KY);
					Visited[KX][KY] = Visited[X][Y] + MATRIX[KX][KY];
					Queue[wpos] = 1024*KX + KY; 
					wpos++;
				}
			}
		}*/
		
		printf("%d\n",Visited[DX][DY]);
	}
	return 0;
}
int DFS(int X,int Y)
{
	int k;
	for(k=0;k<4;k++)
	{
		int KX = X + dx[k];
		int KY = Y + dy[k];
		//printf("+%d %d+\n",KX,KY);
		if(KX>=1 && KX<=HEIGHT && KY>=1 && KY <= WIDTH && Visited[KX][KY] != -1 && Visited[KX][KY] > Visited[X][Y] + MATRIX[KX][KY])
		{
			//printf("-%d %d-\n",KX,KY);
			Visited[KX][KY] = Visited[X][Y] + MATRIX[KX][KY];
			DFS(KX,KY);
		}
	}	
}