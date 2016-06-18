/***********************************

http://www.spoj.com/problems/BYTESM2

***********************************/
#include<stdio.h>
int MAX(int x,int y,int c)
{
	int max;
	if(x>y)
		max=x;
	else
		max=y;
		
	if(max>c)
		return max;
		
	return c;
}
int main()
{
	int TC;
	scanf("%d",&TC);
	while(TC--)
	{
		int ROW,COL;
		scanf("%d %d",&ROW,&COL);
		int MAT[200][200] = {0};
		int row,col;
		for(row=0;row<=ROW+1;row++)
		{	
				MAT[row][0] = 0;
				MAT[row][COL+1] = 0;
		}
		for(col=0;col<=COL+1;col++)
		{
			MAT[0][col] = 0;
			MAT[ROW+1][col] = 0;
		}
		
		for(row=1;row<=ROW;row++)
			for(col=1;col<=COL;col++)
				scanf("%d",&MAT[row][col]);
		
		for(row=1;row<=ROW;row++)
			for(col=1;col<=COL;col++)
				MAT[row][col] = MAT[row][col] + MAX(MAT[row-1][col-1],MAT[row-1][col],MAT[row-1][col+1]);
				
		int max=-1;
		for(row=1;row<=ROW;row++)
		{
			for(col=1;col<=COL;col++)
				if(max < MAT[row][col])
					max = MAT[row][col];
		}
		printf("%d\n",max);
	}
	return 0;
}