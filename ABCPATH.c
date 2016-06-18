/*****************************************************

ABCPATH Solution
Link to the problem

http://www.spoj.com/problems/ABCPATH/
*****************************************************/

#include<stdio.h>
#include<stdlib.h>

struct Pts
{
	int i;
	int j;
};
struct Pts stack[3000];

void Push(int *top,int i,int j)
{
	*top = *top + 1;
	stack[*top].i = i;
	stack[*top].j = j;
	return ;
}
struct Pts Pop(int *top)
{
	struct Pts temp = stack[*top];
	*top = *top - 1;
	return temp;
}
int main()
{
	int counter=0;
	
	while(1)
	{
		int H,W;
		char MAT[60][60];
		int SCAN[100]={0};
		int X[] = {-1,1,0,0,1,-1,-1,1};
		int Y[] = {0,0,-1,1,1,-1,1,-1};
		scanf("%d %d",&H,&W);
		
		if(H==0)
			break;
			
		int row,col;
		int top=-1;
		
		for(row=0;row<=H+1;row++)
			for(col=0;col<=W+1;col++)
				MAT[row][col] = 11;
				
		char str[55];		
		for(row=1;row<=H;row++)
		{
			scanf("%s",str);
			for(col=1;col<=W;col++)
				MAT[row][col] = str[col-1];
		}
		/*Printing the MAtrix*/
		/*for(row=0;row<=H+1;row++)
		{
			for(col=0;col<=W+1;col++)
				printf("%d ",MAT[row][col]);
				
			printf("\n");	
		}*/	
		int i,j;
		
		for(row=1;row<=H;row++)
		{
			for(col=1;col<=W;col++)
			{
				if(MAT[row][col]=='A')
					SCAN[MAT[row][col]]=1;
					
				else
				{
					top=-1;
					if(SCAN[MAT[row][col]]==1)
					{	
						//printf("%C\n",MAT[row][col]);
						continue;
					}
					//printf("%C\n",MAT[row][col]);
					Push(&top,row,col);
					
					struct Pts temp;
					
					while(top!=-1)
					{
						temp = Pop(&top);
						if(MAT[temp.i][temp.j]=='A')
						{
							SCAN[MAT[row][col]] = 1;
							//printf("----%C\n",MAT[row][col]);
							break;
						}	
						for(j=0;j<8;j++)
							if(MAT[temp.i-X[j]][temp.j-Y[j]]==MAT[temp.i][temp.j]-1)
							{
								Push(&top,temp.i-X[j],temp.j-Y[j]);
							}	
					}
					
				}				
			}
		}
		int k;
		int f=0;
		counter++;
		for(k=90;k>=65;k--)
		{
			if(SCAN[k]==1)
			{
				printf("Case %d: %d\n",counter,k-64);
				f=1;
				break;
			}
		}	
		if(f==0)
		printf("Case %d: %d\n",counter,0);
		
	}
	return 0;
}