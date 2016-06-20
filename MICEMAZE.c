/*************************************
Author :- Kawar Siddharth Rajendra
Problem Statement :-
http://www.spoj.com/problems/MICEMAZE
*************************************/
#include<stdio.h>
int main()
{
	int V;
	int Ex;
	int T;
	int E;
	int MAT[128][128];
	memset(MAT, 0x3f, sizeof MAT);
	scanf("%d",&V);
	scanf("%d",&Ex);
	scanf("%d",&T);
	scanf("%d",&E);
	int i=0;
	int a,b;
	int cost;
	for(i=1;i<=V;i++)
	{
		MAT[i][i] = 0;
	}
	for(i=0;i<E;i++)
	{
		scanf("%d %d %d",&a,&b,&cost);
		MAT[a][b] = cost;
	}	
	
	int k,j;
	
	for(k=1;k<=V;k++)
	{
		for(i=1;i<=V;i++)
		{
			for(j=1;j<=V;j++)
			{
				if(MAT[i][k] + MAT[j][k] < MAT[i][j])
					MAT[i][j] = MAT[i][k] + MAT[j][k];
			}
		}	
	}
	//printf("---------\n");
	int ct=0;
	for(i=1;i<=V;i++)
	{
		if(MAT[i][Ex] <= T)
		{
			//printf("%d %d %d \n",i,Ex,MAT[i][Ex]);
			ct++;
		}	
	}
	printf("%d\n",ct);
	return 0;
}