/**************************************
http://www.spoj.com/problems/BUGLIFE/
 
**************************************/
#include<stdio.h>
struct P
{
	int i;
};
struct P stack[1000010];
void Push(int *top,int i)
{
	*top = *top + 1;
	stack[*top].i = i;
	return ;
}
int Pop(int *top)
{
	struct P temp = stack[*top];
	*top = *top -1;
	return temp.i;
}
int COLOR[2048];
int MAT[2048][2048];
int main()
{
	int TC;
	scanf("%d",&TC);
	int s=1;
	while(TC--)
	{
		int N,E;
		memset(MAT,0,sizeof MAT);
		scanf("%d %d",&N,&E);
		int i=0,j;
		int a,b;
		for(i=0;i<E;i++)
		{
			scanf("%d %d",&a,&b);
			MAT[a][b] = 1;
			MAT[b][a] = 1;
		}
		
		int top = -1;
		int flag=0;
		for(i=1;i<=N;i++)
		{
			COLOR[i] = -1;
		}
		for(i=1;i<=N;i++)
		{
			if(COLOR[i]==-1)
			{
				COLOR[i] = 1;
				Push(&top,i);
				
				while(top!=-1)
				{
					int v;
					int u = Pop(&top); 
					for(v=1;v<=N;v++)
					{
						if(MAT[u][v] &&  COLOR[v] == -1)
						{
							COLOR[v] = 1 - COLOR[u];
							Push(&top,v);
						}
						else if(MAT[u][v] && COLOR[u] == COLOR[v])
							flag=1;
					}
				}	
			}				
		}	
		printf("Scenario #%d:\n",s);
		s++;
		if(flag)
			printf("Suspicious bugs found!\n");
		else
			printf("No suspicious bugs found!\n");
		
	}
	return 0;
}