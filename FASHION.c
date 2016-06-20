
/*************************************
Author :- Kawar Siddharth Rajendra
Problem Statement :-
http://www.spoj.com/problems/FASHION
*************************************/
#include<stdio.h>
int int_cmp(const void *a, const void *b) 
{ 
    const int *ia = (const int *)a; 
    const int *ib = (const int *)b;
    return *ia  - *ib; 
} 
int main()
{
	int n;
	scanf("%d",&n);
	while(n--){
		int n1,i,j,sum=0,a[2][1001];
		scanf("%d",&n1);
		for(i=0;i<2;i++)
		{
			for(j=0;j<n1;j++)
			{
				scanf("%d",&a[i][j]);
			}
		qsort(a[i],n1, sizeof(int), int_cmp);
		}	
	
		for(i=0;i<n1;i++)
		{
			sum = sum + a[0][i]*a[1][i];
		}
		printf("%d\n",sum);
		
	}
	return 0;
}
 
