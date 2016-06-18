/***********************************

http://www.spoj.com/problems/CANDY
***********************************/
#include<stdio.h>
#include<stdlib.h>
int int_cmp(const void *a, const void *b) 
{ 
    const int *ia = (const int *)a; // casting pointer types 
    const int *ib = (const int *)b;
    return *ia  - *ib; 

} 
int main()
{
	int a[10010],i,sum,avg,moves,n;
	while(scanf("%d",&n)==1)
	{
		sum=0;avg=0;moves=0;
		if(n==-1)break;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		qsort(a,n,sizeof(int),int_cmp);

		for(i=0;i<n;i++)
		sum = sum + a[i];
		
		if(sum%n!=0)printf("-1\n");
		else
		{	avg = sum/n;
			for(i=0;i<n;i++)
			{
				if(a[i]<avg)
				moves = moves + avg - a[i];	
			}printf("%d\n",moves);	
		}			
		
	}
	return 0;
}
