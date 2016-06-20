/*************************************
Author :- Kawar Siddharth Rajendra
Problem Statement :-
http://www.spoj.com/problems/PARTY
*************************************/
#include<stdio.h>
int max(int i,int j)
{
	if(i>j)
	return i;
	return j;
}
int main()
{
	int best;
	int dp[505][505]={0};
	int w,cost,fun;
	int v,n,i;
	while(scanf("%d %d",&v,&n)==2)
	{
		if(!v && !n) break;
		for(i=1;i<=n;i++)
		{
			scanf("%d %d",&cost,&fun);
			for(w=1;w<=v;w++)
			{
				if(cost>w) dp[i][w] = dp[i-1][w];
				else
				dp[i][w] = max(dp[i-1][w],dp[i-1][w-cost] + fun);
			}
		}
		for(w=v,best = dp[n][v];;w--)
		if(dp[n][w] < best)break;

		printf("%d %d\n",w+1,dp[n][v]);
	}
	return 0;
}
