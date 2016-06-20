/*************************************
Author :- Kawar Siddharth Rajendra
Problem Statement :-
http://www.spoj.com/problems/STPAR
*************************************/
#include<stdio.h>
int main() 
{
	while(1)
	{	
		
		int a[1000],i,j,n;
		scanf("%d",&n);
		if(n==0)
		{
			break;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}	
	
	
		int count = 1,side_road[1000],k=0,in=0;	
		for(j=1;j<=n;j++)
		{
			if(a[j] == count)
			{
				count++;	
				while(k>0 && count == side_road[k])
				{
					k--;
					count++;
				}			
			}
			else if(a[j] != count)
			{
				k++;
				side_road[k] = a[j];
				if(k>1 && side_road[k-1] < side_road[k])
				{
					in++;
					if(in==1)
					printf("no\n");
				}
				
			}
			
		}	
		if(in == 0)	
		{
			printf("yes\n");
		}
			
	}
	return 0;
}	
