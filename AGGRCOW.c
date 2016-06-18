/*****************************************************

Link to the problem

http://www.spoj.com/problems/AGGRCOW
*****************************************************/

#include<stdio.h>
#include<stdlib.h>
void BinarySearch(unsigned long long int arr[], unsigned long int N,unsigned long int C);
int F(unsigned long long int [],unsigned long int,unsigned long int,unsigned long int);
int cmpfunc(const void* a,const void* b)
{
	return (*(unsigned long long int*)a - *(unsigned long long int*)b);
}
int main()
{
	int TC;
	scanf("%llu",&TC);
	while(TC--)
	{
		unsigned long int N,C,i;
		scanf("%lu %lu",&N,&C);
		unsigned long long int arr[100050]={0};
		int max;
		for(i=0;i<N;i++)
			scanf("%llu",&arr[i]);
		
		qsort(arr,N,sizeof(unsigned long long int),cmpfunc);
		
		BinarySearch(arr, N, C);
	}
	return 0;
}
void BinarySearch(unsigned long long int arr[], unsigned long int N,unsigned long int C)
{
	unsigned long int i;
	unsigned long int low = arr[1] - arr[0];
	unsigned long int high = arr[N-1] - arr[0];	
	for(i=1;i<N-1;i++)
		if(low>arr[i+1]-arr[i])
			low = arr[i+1]-arr[i];	
			
	
	unsigned long int mid;
	while(low < high)
	{
		mid = (low+high)/2;
		if(F(arr,mid,N,C)==1)
			low = mid + 1;
		else
			high = mid;
	}
	printf("%lu\n",low-1);
}
int F(unsigned long long int arr[],unsigned long int x,unsigned long int N,unsigned long int C)
{
	unsigned long int cowplaced = 1;
	unsigned long long int LPos = arr[0];
	unsigned long int i;
	for(i=1;i<N;i++)
	{
		if(arr[i]-LPos>=x)
		{
			cowplaced++;
			LPos = arr[i];
		}	
			if(cowplaced == C)
				return 1;
	}	
	return 0;
}