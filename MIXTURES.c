/*************************************
Author :- Kawar Siddharth Rajendra
Problem Statement :-
http://www.spoj.com/problems/MIXTURES
*************************************/
#include<stdio.h>
#define INF 2222222;
int mix[128][128];
int a[128];
int dp[128][128];
int solve(int,int);
int main()
{
	int n,i,j;
	while(scanf("%d",&n)==1)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}		
		for(i=0;i<n;i++)
		{	
			mix[i][i] = a[i];
			dp[i][i] = 0;
			for(j=i+1;j<n;j++)
			{
				mix[i][j] = mix[i][j-1] + a[j];
				dp[i][j] = -1;
				if(mix[i][j]>=100)mix[i][j] = mix[i][j] - 100;	
			}
		}	
			
		printf("%d\n",solve(0,n-1));
	}
	return 0;
}
int solve(int s,int e)
{
	if(dp[s][e] >- 1) return dp[s][e];
	int ret = INF;int smoke;
	int i;
	for(i=s;i<e;i++)
	{
		smoke = mix[s][i]*mix[i+1][e];
		smoke = smoke + solve(s,i);
		smoke = smoke + solve(i+1,e);
		if(ret>smoke)		
			ret = smoke;
		else
		ret = ret;
		
	}


	return dp[s][e] = ret;	
}
