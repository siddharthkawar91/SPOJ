/*************************************
Author :- Kawar Siddharth Rajendra
Problem Statement :-
http://www.spoj.com/problems/FARIDA
*************************************/

#include<stdio.h>
unsigned long long int max(unsigned long long int a, unsigned long long int b);
int main()
{
	int TC;
	scanf("%d",&TC);
	int j=0;
	while(TC--)
	{
	
			j++;
			int N,i;
			scanf("%d",&N);
			unsigned long long int a[10050];
			unsigned long long int dp[10050]={0};
			for(i=0;i<N;i++)
			{
			
					scanf("%llu",&a[i]);
			}
	
			dp[0] = a[0];
			dp[1] = max(dp[0],a[1]);
	
			for(i=2;i<N;i++)
			dp[i] = max(dp[i-1],a[i] + dp[i-2]);
	
			printf("Case %d: %llu\n",j,dp[N-1]);
			
	}
	return 0;
}
unsigned long long int max(unsigned long long int a, unsigned long long int b)
{
	if(a>b)
	return a;
	
	return b;
}