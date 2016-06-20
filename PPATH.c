/*************************************
Author :- Kawar Siddharth Rajendra
Problem Statement :-
http://www.spoj.com/problems/PPATH
*************************************/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int Prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int Queue[9024][2];
bool Visited[10000]={false};
bool IsPrime(int u)
{
	int i;
	for(i=0;i<25;i++)
		if(u%Prime[i] == 0)
			return false;
			
	return true;
}
int main()
{
	int TC;
	scanf("%d",&TC);
	
	while(TC--)
	{
		int a,b;
		char S[5],E[5];
		scanf("%s %s",S,E);
		a = atoi(S);
		b = atoi(E);
		
		memset(Visited,false,sizeof(Visited));
		int rpos = 0;
		int wpos = 0;
		
		Queue[wpos][0] = a;
		Queue[wpos][1] = 0;
		Visited[a]=1;
		wpos++;
		int min = 100000;
		
		while(rpos!=wpos)
		{
			int u = Queue[rpos][0];
			int count  = Queue[rpos][1];
			
			//printf("Element popped %d with count %d\n",u,count);
			
			if(u == b)
			{
				if(min > count)
					min = count;
					
				break;
			}				
			rpos++;
			
			int I,J,K;
			for(I = 1000,J=0; I >= 1; I = I/10,J++)
			{
				int v=-1;
				if(J==0)
					v = 0;
				
				
				//printf("Working on element at Index %d\n",v,J);
				
				int In;
				while(v<=8)
				{
					v++;
					S[J] = '0' + v;
					//printf("Checking for %s\n",S);
					In = atoi(S);
					if(In <= 9999 && IsPrime(In) && !Visited[In])
					{
						//printf("This number passed the prime test : %d\n",In);
						Visited[In] = true;
						Queue[wpos][0] = In;
						Queue[wpos][1] = count  + 1;
						wpos++;
					}
				}
				sprintf(S,"%d",u);
				
			}
			
		}
		printf("%d\n",min);
	}
	
	return 0;
}