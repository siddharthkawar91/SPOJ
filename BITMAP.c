
/*****************************************************

Link to the problem

http://www.spoj.com/problems/BITMAP
*****************************************************/
#include<stdio.h>
int QUEUE[1024*1024];
int main()
{
	int TC;
	scanf("%d",&TC);
	while(TC--)
	{
		
		int row,col;
		int ROW,COL;	
		
		
		scanf("%d %d",&ROW,&COL);
		int MAT[200][200]={0};
		for(col=0;col<=COL+1;col++)
		{
			MAT[0][col] = -2;
			MAT[ROW+1][col]=-2;
		}	
		for(row=0;row<=ROW+1;row++)
		{
			MAT[row][0] = -2;
			MAT[row][COL+1]=-2;
		}
		
		
		char str[200];
		int rpos=0;
		int wpos=0;
		int X[] = {-1,1,0,0};
		int Y[] = {0,0,-1,1};		
		for(row=1;row<=ROW;row++)
		{
			scanf("%s",str);
			for(col=1;col<=COL;col++)
			{	
				MAT[row][col] = str[col-1] - '0';
				if(MAT[row][col]==1)
				{
					MAT[row][col] = -1;
					QUEUE[wpos]= 1024*row + col;
					wpos++;
				}	
				else
					MAT[row][col]=200000000;
			}	
		}	

		int f;
		while(rpos<wpos)
		{
			row = QUEUE[rpos]/1024;
			col = QUEUE[rpos]%1024;
			if(MAT[row][col] == -1)
				MAT[row][col] = 1;
			for(f=0;f<4;f++)
			{
				if(MAT[row-X[f]][col-Y[f]]>=0 && MAT[row-X[f]][col-Y[f]] > MAT[row][col]+1)	
				{
					MAT[row - X[f]][col - Y[f]] = MAT[row][col] + 1;
					QUEUE[wpos] = 1024*(row -X[f]) + col - Y[f];
					wpos++;
	 			}
			}
			rpos++;	
		}				
		for(row=1;row<=ROW;row++)
		{
			for(col=1;col<=COL;col++)
				printf("%d ",MAT[row][col]-1);
			
			printf("\n");
		}		
	}
	return 0;
}