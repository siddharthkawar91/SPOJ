/*************************************
Author :- Kawar Siddharth Rajendra
Problem Statement :-
http://www.spoj.com/problems/MIXTURES
*************************************/
#include<cstdio>
#include<stdbool.h>
#include<cstdlib>
#include <cstring>
#define INT_MAX 1061109567
int Queue[5000*5000];

int main()
{

	int ROW,COL;
	char MAT[128][128];
	int dist[128][128];
	char Input[128];
	scanf("%d %d",&COL,&ROW);
	
		int row,col;
		
		//dist[row][col] = INT_MAX;
		memset(dist,0x3f,sizeof(dist));
		//dir[row][col] = -1		
		int rpos=0,wpos=0;
		bool F=false;
		
		int DX[] = {-1,1,0,0};
		int DY[] = {0,0,-1,1};
 		for(row=0;row<=ROW+1;row++)
		{
			MAT[row][0] = '*';
			MAT[row][COL+1] = '*';
		}
		for(col=0;col<=COL+1;col++)
		{
			MAT[0][col] = '*';
			MAT[ROW+1][col] = '*';
		}
		
		for(row=1;row<=ROW;row++)
		{
			scanf("%s",Input);
			
			for(col=1;col<=COL;col++)
			{
				MAT[row][col] = Input[col-1]; 
				if(Input[col-1] == 'C' && !F )
				{
					MAT[row][col] = 'S';
					dist[row][col] = -1;
					Queue[wpos] = 128*row + col;
					wpos++;
					F = true;
				}					
			}
		}	
		
		/*for(row=0;row<=ROW+1;row++)
		{
			for(col=0;col<=COL+1;col++)
				printf("%c",MAT[row][col]);
				
			printf("\n");
		}	*/	
		int X,Y;
		int k;
		
		int D;
		int mirror=0;
		bool M =false;
		while(rpos<wpos)
		{
			row  = Queue[rpos]/128;
			col  = Queue[rpos]%128;
			//printf("--%d %d--\n",row,col);
			if(MAT[row][col] == 'C')
			{
				printf("%d\n",dist[row][col]);
				break;
				
			}	
			for(k=0;k<4;k++)
			{
				X = row + DX[k];
				Y = col + DY[k];
				
				while(MAT[X][Y] != '*') 
				{
					if(dist[X][Y] > 1 + dist[row][col])
					{
					
						dist[X][Y] = 1 + dist[row][col];
						if(MAT[X][Y] == 'C')
						{
							printf("%d\n",dist[X][Y]);
							break;
						}	
						Queue[wpos] = 128*X + Y;
						wpos++;
					}
					X = X + DX[k];
					Y = Y + DY[k];
				}
			}
			rpos++;
		}
		/*printf("----------\n");
		for(row=1;row<=ROW;row++)
		{
			for(col=1;col<=COL;col++)
				if(dist[row][col] != INT_MAX)
					printf("%d ",dist[row][col]);
				else
					printf("L ");
			printf("\n");
		}*/
		/*for(row=1;row<=ROW;row++)
		{ 
			for(col=1;col<=COL;col++)
				if(Mir[row][col] != INT_MAX)
					printf("%d ",Mir[row][col]);
				else
					printf("o ");
			printf("\n");
		}
		printf("----------\n");
		for(row=1;row<=ROW;row++)
		{
			for(col=1;col<=COL;col++)
				if(dir[row][col] != -1)
					printf("%d ",dir[row][col]);
				else
					printf("M ");
			printf("\n");
		}*/
	
		
}