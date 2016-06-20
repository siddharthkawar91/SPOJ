/*************************************
Author :- Kawar Siddharth Rajendra
Problem Statement :-
http://www.spoj.com/problems/PT07Z
*************************************/
#include<stdio.h>
#include<stdbool.h>
bool MAT[10024][10024];
bool Visited[10024] = {false};
int N;
int DIST[10024] = {-1};
int Queue[10024] = {0};
int rpos=0;
int wpos=0;
int max=0;
int Index;
void BFS()
{
	while(rpos!=wpos)
	{
		int u = Queue[rpos];
		int v;
		rpos++;
		for(v=1;v<=N;v++)
		{
			if(MAT[u][v] && !Visited[v])
			{
				
				DIST[v] = 1 + DIST[u];
				if(DIST[v] > max)
				{
					max  = DIST[v];
					Index = v;
				}				
				Visited[v] = 1;
				Queue[wpos] = v;
				wpos++;
			}		
		}
	}
}	
void DFS(int u)
{
	int v;
	for(v=1;v<=N;v++)
	{
		if(MAT[u][v] && !Visited[v])
		{
			DIST[v] = 1 + DIST[u];
			if(DIST[v] > max)
			{
				max  = DIST[v];
				Index = v;
			}
			Visited[v] = true;
			DFS(v);
		}
	}
}
int main()
{
	scanf("%d",&N);
	int i;
	int a,b;
	for(i=0;i<N-1;i++)
	{
		scanf("%d %d",&a,&b);
		MAT[a][b] = true;
		MAT[b][a] = true;
	}
	
	DIST[1] = 0;
	Visited[1] = true;
	
	/*Queue[wpos] = 1;
	wpos++;
	BFS();*/
	
	
	DFS(1);
	
	memset(DIST,-1,sizeof(DIST));
	memset(Visited,0,sizeof(Visited));
	
	
	/*rpos=0;
	wpos=0;
	Queue[wpos] = Index;
	wpos++;*/
	
	Visited[Index] = true;
	DIST[Index] = 0;
	
	/*max=0;
	BFS();
	*/

	DFS(Index);
	
			
	printf("%d\n",max);
	return 0;
}