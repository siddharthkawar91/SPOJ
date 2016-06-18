
/*****************************************************

Link to the problem

http://www.spoj.com/problems/ANARC08F
*****************************************************/
#include<stdio.h>
#include <cstdio>
#include <map>
#include <string>
#include<string.h>
#include<limits.h>
using namespace std;

map <string,int> cn;
int ct;
int q[1028];
int add_city(const char *name)
{
	int &x = cn[name];
	if(!x) x = ct++;
	return x;
}
int main()
{
	int N,C,R;
	int MAT[121][121];
	int t=1;
	while(1)
	{
		//printf("Scanning the input...\n");
		scanf("%d %d %d",&N,&C,&R);
		if(!N)
			break;
		
		int i;
		int j;
		cn.clear();
		/*for(i=0;i<=N;i++)
			for(j=0;j<=N;j++)
				MAT[i][j] = 9999999;*/
				
		memset(MAT, 0x3f, sizeof MAT);
				
		ct=1;
		char Garage[11];
		char CarLoc[1010][12];
		
		cn[Garage] = ct;
		//printf("---%s - %d\n",Garage,cn[Garage]);
		ct++;
		++C;
		char c1[11],c2[11],edge[11];
		for(i=0;i<C;i++)
		{
			scanf("%s",c1);
			q[i] = add_city(c1);
			
		}
		int cost;
		int a,b;
		for(i=0; i<R; i++)
		{
			scanf("%s %s %s",c1,edge,c2);
			sscanf(edge+2,"%d",&cost);
			a = add_city(c1);
			b = add_city(c2);
			int len = strlen(edge);
			if(edge[0] == '<')
			{
				
				MAT[b][a] = min(cost,MAT[b][a]);
				
			}
			if(edge[len-1] == '>')
				MAT[a][b] = min(cost,MAT[a][b]);
		}
		
		/*for(i=1;i<ct;i++)
		{
			for(j=1;j<ct;j++)
				printf("%d ",MAT[i][j]);
				
			printf("\n");	
		}*/
		int k;
		//printf("%d\n",ct);
		for(k=1;k<ct;k++)
			for(i=1;i<ct;i++)
				for(j=1;j<ct;j++)
				{
					if(MAT[i][k] + MAT[k][j] < MAT[i][j])
						MAT[i][j] = MAT[i][k] + MAT[k][j];
				}
			
	
		int ans=0,origin = q[0];
		for(i=1;i<C;i++)
			ans = ans + MAT[origin][q[i]] + MAT[q[i]][origin];
			
		printf("%d. %d\n",t,ans);
		t++;
	}
	
	return 0;
}
