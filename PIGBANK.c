/*************************************
Author :- Kawar Siddharth Rajendra
Problem Statement :-
http://www.spoj.com/problems/PIGBANK
*************************************/
#include<stdio.h>
unsigned long int Min(unsigned long int , unsigned long int);
unsigned long int Max(unsigned long int , unsigned long int);
int main()
{
	unsigned long int testcases;
	//printf("%d\n",1<<30);
	scanf("%lu",&testcases);
	
	while(testcases--)
	{
		unsigned long int E,F,gross;
		unsigned long int V[505]={0},W[505]={0};
		scanf("%lu %lu",&E,&F);
		gross = F - E;
		unsigned long int N,i,j;
		unsigned long int K[15000]={0};
		
		
	scanf("%lu",&N);
	for(i=0;i<N;i++)
	{
		scanf("%lu %lu",&V[i],&W[i]);	
	}	
	unsigned long int best = 1<<30,w;
	K[0]=0;
	for ( w=1; w <= gross; w++) 
	{
		K[w] = 1<<30;
  		for (i=0; i<N; i++) 
		{
			
			if (w >= W[i] ) 
			{	
		    	best = K[ w - W[i] ] + V[i];
   				if(best < K[w])
			   	{
                	K[w] = best;
                 }

  			}
		}
	}
	//printf("%d\n",best);
	/*for(w=1; w <= gross; w++)
	{
		for(i=0; i<N; i++)
		{
			printf("%d ",a[w][i]);		
		}
		printf("\n");
	}*/
	
		
		if(K[gross] != 1<<30)
		printf("The minimum amount of money in the piggy-bank is %lu.\n",K[gross]);
		else
		printf("This is impossible.\n");
	}
	return 0;
	
}
unsigned long int Min(unsigned long int M,unsigned long int N)
{
	if(M>N)
	return N;
	else
	return M;		
}
unsigned long int Max(unsigned long int M,unsigned long int N)
{
	if(M>N)
	return M;
	else
	return N;		
}
