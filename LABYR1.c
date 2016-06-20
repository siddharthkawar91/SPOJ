/*************************************
Author :- Kawar Siddharth Rajendra
Problem Statement :-
http://www.spoj.com/problems/LABYR1
*************************************/
#include<stdio.h>
int labyr[1024][1024]={0};
int maze[1024][1024]={0};

int main()	
{
	int n;		
	scanf("%d\n",&n);
	while(n--)
	{
		int ROW,COL,i,j,m,l,max;
		int QUEUE[1024*1024];
		int flag=0;	
		char ch;	
		scanf("%d %d",&COL,&ROW);
		for(i=0;i<ROW;i++)
		{
			ch = getchar();
			for(j=0;j<COL;j++)
			{
				
				scanf("%c",&ch);
				if(ch == '.')
				{	
					if(!flag)
					{
						flag=1;		
						m=i;l=j;
					}
					labyr[i][j] = 200000000;					
					maze[i][j] = 200000000;
				}
			}
		}
		int rpos=0,wpos=1;
		int row,col,f;
		int x[]={0,0,-1,1};
		int y[]={1,-1,0,0};
		QUEUE[rpos] = 1024*m + l;
		labyr[m][l] = 0;
		while(rpos<wpos)
		{
	
			row = QUEUE[rpos]/1024;
			col = QUEUE[rpos]%1024;
			for(f=0;f<4;f++)
			{
				if(labyr[row-x[f]][col-y[f]]==200000000)	
				{
					labyr[row - x[f]][col - y[f]] = labyr[row][col] + 1;
					QUEUE[wpos] = 1024*(row -x[f]) + col - y[f];
					wpos++;
	 			}
			}
			rpos++;
		}
		max = -1;
		for(i=0;i<ROW;i++)
		{
			for(j=0;j<COL;j++)
			{
				if(labyr[i][j]!=200000000 && max < labyr[i][j])
				{
					max = labyr[i][j];
					m = i;l = j;
				}
				labyr[i][j] = 0;
			}	
		}
	//	printf("%d %d\n",m,l);
		rpos=0;wpos=1;
		maze[m][l] = 0;
		QUEUE[rpos] = 1024*m + l;
		while(rpos<wpos)
		{
	
			row = QUEUE[rpos]/1024;
			col = QUEUE[rpos]%1024;
			for(f=0;f<4;f++)
			{
				if(maze[row-x[f]][col-y[f]]==200000000)	
				{
	//				printf("%d %d\n",row-x[f],col-y[f]);
					maze[row - x[f]][col - y[f]] = maze[row][col] + 1;
	//				printf("%d--\n",maze[row - x[f]][col - y[f]]);
					QUEUE[wpos] = 1024*(row -x[f]) + col - y[f];
					wpos++;
	 			}
			}
			rpos++;
		}
		max = -1;
		for(i=0;i<ROW;i++)
		{
			for(j=0;j<COL;j++)
			{
				if(maze[i][j]!=200000000 && max < maze[i][j])
				{
					max = maze[i][j];
					 
				}
				maze[i][j] = 0;
			}	
		}
		printf("Maximum rope length is %d.\n",max);	
	}
	return 0;

}
