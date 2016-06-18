/*****************************************************

Link to the problem

http://www.spoj.com/problems/ALLIZWEL
*****************************************************/

#include<stdio.h>
#include<stdbool.h>
#include<string.h>
int dx[] = {-1,1,0,0,-1,1,-1,1};
int dy[] = {0,0,-1,1,-1,1,1,-1};

int len;
char WORD[11];
bool Visited[110][110] = {false};	
int flag=0;
void exist(char MAT[][110],int row, int col,int CurPos)
{
	//printf("%d %d %d\n",row,col,CurPos);
	
	Visited[row][col] = true;
	if(CurPos == len)
	{
		//printf("Length is equal\n");
		flag=1;
		
	}
		int X,Y;
		int i;
		
		for(i=0;i<8;i++)
		{
			X = row + dx[i];
			Y = col + dy[i];
			if(MAT[X][Y]!='1'&& MAT[X][Y] == WORD[CurPos+1] &&!Visited[X][Y])
			{
				//printf("Pushing %d %d\n",X,Y);
				Visited[X][Y] = true;
				exist(MAT,X,Y,CurPos+1);
				Visited[X][Y] = false;
			}	
		}
	Visited[row][col] = false;

}
int main()
{
	int TC;
	scanf("%d",&TC);
	char MAT[110][110];
	char temp[110];
	WORD[0] = 'A';
	WORD[1] = 'L';
	
	WORD[2] = 'L';
	WORD[3] = 'I';
	WORD[4] = 'Z';
	WORD[5] = 'Z';
	WORD[6] = 'W';
	WORD[7] = 'E';
	WORD[8] = 'L';
	WORD[9] = 'L';
	len = 9;
	while(TC--)
	{
		int ROW,COL;
		scanf("%d %d",&ROW,&COL);
		memset(Visited, false, 110*110*sizeof(bool));
		int row,col;
		for(row=0;row<=ROW+1;row++)
		{
			MAT[row][0] = '1';
			MAT[row][COL+1] = '1';
		}
		for(col=0;col<=COL+1;col++)
		{
			MAT[0][col] = '1';
			MAT[ROW+1][col] = '1';
		}
		for(row=1;row<=ROW;row++)
		{
			scanf("%s",temp);
			for(col=1;col<=COL;col++)
				MAT[row][col] = temp[col-1];
		}
		flag=0;
		for(row=1;row<=ROW;row++)
		{
			for(col=1;col<=COL;col++)
			{
				if(MAT[row][col] == 'A')
				{
					exist(MAT,row,col,0);
					if(flag)
					break;
				}		
			}
			if(flag)
				break;
		}	
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
}