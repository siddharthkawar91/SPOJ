/*************************************
Author :- Kawar Siddharth Rajendra
Problem Statement :-
http://www.spoj.com/problems/POUR1
*************************************/
#include<stdio.h>
int gcd(int a,int b);
int main()
{
	int testcases;
	scanf("%d",&testcases);
	while(testcases--)
	{
		int i=0;
		int a,b,c,g;
		scanf("%d %d %d",&a,&b,&c); 
		g = gcd(a,b);
		if((c>a && c>b) || c%g!=0)
		{
			printf("-1\n");
			continue;
		}
		int max=0;
		int A=0,B=0;
		int dummy;
		if(a>b)
		{
			dummy = b;
			b = a;
			a = dummy;
		}
		A=a;int steps=1;
		//printf("%d %d\n",A,B);
		//for(;A!=0 && B!=b;B++,A--)
		while(A!=c && B!=c)
		{
			if(A==0)
			{
				steps++;
				A=a;
				//printf("%d %d\n",A,B);
	
				if(A==c || B==c)
				break;	
			}
			else if(B!=b)
			{
				if(b>A + B)
				{
					B = A + B;
					A = 0;
				}
				else
				{
					dummy = b - B;
					A = A - dummy;
					B = b;
				}
				steps++;
				//printf("%d %d\n",A,B);						
				if(B==c || A==c)
				{
					//printf("Its done\n");
					break;
				}
				else if(B==b)
				{
					B=0;
					steps++;
					//printf("%d %d\n",A,B);
				}
			}
		}
		//printf("Steps:-%d\n",steps);
		max = steps;
		dummy = a;
		a = b;
		b = dummy;
		A=0;B=0;
		A=a;steps=1;
		//printf("%d %d\n",A,B);
		//for(;A!=0 && B!=b;B++,A--)
		while(A!=c && B!=c)
		{
			if(A==0)
			{
				steps++;
				A=a;
				//printf("%d %d\n",A,B);
	
				if(A==c || B==c)
				break;	
			}
			else if(B!=b)
			{
				if(A > b - B)
				{
					A = A - (b - B);
					B = b;
				}
				else
				{
					B = A;
					A = 0;
				}
				steps++;
				//printf("%d %d\n",A,B);						
				if(B==c || A==c)
				{
					//printf("Its done\n");
					break;
				}
				else if(B==b)
				{
					B=0;
					steps++;
					//printf("%d %d\n",A,B);
				}
			}
		}
		if(max >steps)max = steps;
		printf("%d\n",max);
	}
	return 0;
}
int gcd(int a,int b)
{
	if(a%b == 0 )
	{
		return b;
	}
	return gcd(b,a%b);
}

