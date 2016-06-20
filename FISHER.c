/*************************************
Author :- Kawar Siddharth Rajendra
Problem Statement :-
http://www.spoj.com/problems/FISHER
*************************************/
#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
int DP[55][1050];
bool Visited[55][1050]={false};
struct V
{
	int i;
	int j;
};
struct V Stack[100];
void Push(int *top, int i, int j)
{
	*top = *top + 1;
	Stack[*top].i = i;
	Stack[*top].j = j;
}
struct V Pop(int *top)
{
	struct V temp = Stack[*top];
	*top = *top - 1;
	return temp;
}
int main()
{
	int D[51][51];
	int T[51][51];
	while(1)
	{
		int N,M;
		scanf("%d %d",&N,&M);
		if(N==0&&M==0)
			break;
		
		int i,j;
		for(i=1;i<=N;i++)
			for(j=1;j<=N;j++)
				scanf("%d",&T[i][j]);
			
		for(i=1;i<=N;i++)
			for(j=1;j<=N;j++)
				scanf("%d",&D[i][j]);
				
			
		for(i=0;i<=M;i++)
			DP[1][i] = 0;
			
		for(i=2;i<=N;i++)
			for(j=0;j<=M;j++)
				DP[i][j] = INT_MAX;

		int k;
		for(k=2;k<=N;k++)
		{
			int top=-1;
			DP[k][T[1][k]] = D[1][k];
			//printf("Pushing %d...\n",k);
			Push(&top,k,T[1][k]);
			int t,d;
			while(top!=-1)
			{
				struct V curr;
				curr = Pop(&top);
				if(curr.i == N)
					continue;
				t = curr.j;
				for(j=1;j<=N;j++)
				{
					if(D[curr.i][j]&&(t+T[curr.i][j] <= M)&&(DP[j][t+T[curr.i][j]]>DP[curr.i][t]+D[curr.i][j]))
					{
						DP[j][t+T[curr.i][j]] = DP[curr.i][t] + D[curr.i][j];
						Push(&top,j,t+T[curr.i][j]);
					}	
				}
					
			}	
			
		}
		

		int min=INT_MAX;
		int ind;
		for(i=0;i<=M;i++)
			if(min > DP[N][i])
			{
				min = DP[N][i];
				ind =i;
			}	
		
		printf("%d %d\n",min, ind);
	}
	return 0;
}
	