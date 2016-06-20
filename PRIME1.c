/*************************************
Author :- Kawar Siddharth Rajendra
Problem Statement :-
http://www.spoj.com/problems/PRIME1
*************************************/
#include<stdio.h>
#include<math.h>
int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		char a[1000001];
		int test;
		unsigned long int m,n,i,j;
		for(i=0;i<1000001;i++)
		a[i]='1';
		scanf("%lu %lu",&m,&n);
		if(m==1)
		m++;
		for(j=2;j<=sqrt(n);j++)
		{
			if(m%j!=0)
			i=m/j+1;
			else
			i=m/j;
			if(i==1||i==0)i=2;
			for(;i<=n/j;i++)
			{
				a[i*j-m]='0';
			}
			
		}
		for(i=0;i<=n-m;i++)
		{
			if(a[i]=='1')
			printf("%lu\n",i+m);
		}
	}
	return 0;
}
