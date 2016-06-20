/*************************************
Author :- Kawar Siddharth Rajendra
Problem Statement :-
http://www.spoj.com/problems/MAKEMAZE
*************************************/
#include<stdio.h>
#include<stdbool.h>
char MAT[25][25];
int Queue[10000];
bool Visited[25][25];
bool checked[25][25];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int e[2][2];
int ROW;int COL;

int main()
{
	int TC;
	scanf("%d",&TC);
	char Str[25];
	while(TC--)
	{
		
		scanf("%d %d",&ROW,&COL);
		
		int row,col;
		for(row=1;row<=ROW;row++)
		{	
			scanf("%s",Str);
			for(col=1;col<=COL;col++)	
			{
				MAT[row][col] = Str[col-1];
				Visited[row][col] = false;
				checked[row][col] = false;
			}
		}
		
		
		/*printf("-------------------------------------------\n");
		
		for(row=1;row<=ROW;row++)
		{	
			for(col=1;col<=COL;col++)	
				printf("%c",MAT[row][col]);
				
			printf("\n");
		}*/
		int count=0;
		
		int rpos=0,wpos=0;
		int invalid=0;
		int points = 0;
		for(row=1;row<=ROW;row++)
		{
			for(col=1;col<=COL;col++)
			{
				if((row==1||col==1||row==ROW||col==COL)&&(MAT[row][col] == '.'))
				{
					if(points>=2) 
						invalid = 1;
					else
					{
						e[points][0] = row;
						e[points][1] = col;
					}
					points++;
				}
			}
		}
		/*for(row=1;row<=ROW;row++)
		{
			if(MAT[row][1] == '.' && !checked[row][1])
			{
				Queue[wpos] = 1024*row + 1;
				wpos++;
				count++;
				checked[row][1] = true;
			}	
			if(MAT[row][COL] == '.' && !checked[row][COL])
			{
				Queue[wpos] = 1024*row + COL;
				wpos++;
				count++;
				checked[row][COL] = true;
			}	
		}
		for(col=2;col<=COL-1;col++)
		{
			if(MAT[1][col] == '.' && !checked[1][col])
			{
				Queue[wpos] = 1024*1 + col;
				wpos++;
				count++;
				checked[1][col] = true;
			}
				
			if(MAT[ROW][col] == '.' && !checked[ROW][col])
			{
				Queue[wpos] = 1024*ROW + col;
				wpos++;
				count++;
				checked[ROW][col] = true;
			}
		}*/
		
		//printf("value of points %d\n",points);
		if(points!=2)
		{
			printf("invalid\n");
			continue;
		}
		
		
		
		Visited[e[0][0]][e[0][1]] = true;
		//printf("Source is %d %d\n",e[0][0],e[0][1]);
		//printf("Destination is %d %d\n",e[1][0],e[1][1]);
		
		DFS(e[0][0],e[0][1]);
		/*while(rpos<=wpos)
		{
			int X = Queue[rpos]/1024;
			int Y = Queue[rpos]%1024;
			rpos++;
			
			int k;
			for(k=0;k<4;k++)	
			{
				int KX = X + dx[k];
				int KY = Y + dy[k];
				//printf("%d %d\n",KX,KY);
				if((KX >= 1 && KX <= ROW && KY >= 1 && KY <= COL) && MAT[KX][KY] == '.' && !Visited[KX][KY])
				{
					Visited[KX][KY] = true;
					Queue[wpos] = 1024*KX + KY;
					wpos++;
				}
			}
		}*/
		
		if(Visited[e[1][0]][e[1][1]])
			printf("valid\n");
		else
			printf("invalid\n");
		
		
		/*for(row=1;row<=ROW;row++)
		{
			for(col=1;col<=COL;col++)
				if(Visited[row][col])
					printf("1");
				else
					printf("0");
				
			printf("\n");
		}*/
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
		//printf("%d %d\n",KX,KY);
		if((KX >= 1 && KX <= ROW && KY >= 1 && KY <= COL) && MAT[KX][KY] == '.' && !Visited[KX][KY])
		{
			Visited[KX][KY] = true;
			DFS(KX,KY);
		}
	}
}