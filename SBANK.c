#include<stdio.h>
/*************************************
Author :- Kawar Siddharth Rajendra
Problem Statement :-
http://www.spoj.com/problems/SBANK
*************************************/
#include<stdlib.h>
#include<string.h>
int main()
{
	int o,f;
	scanf("%d",&o);
	for(f=0;f<o;f++){
	int n,i,j,count,temp=0;
	char a[100000][32],character;
	scanf("%d\n",&n);
	for(i=0;i<n;i++)
	{				
		scanf("%s %s %s %s %s %s",&a[i][0],&a[i][3],&a[i][12],&a[i][17],&a[i][22],&a[i][27]);
	a[i][2]=a[i][11]=a[i][16]=a[i][21]=a[i][26]=' ';				
	}
	qsort(a, n, 32, (int(*)(const void*, const void*))strcmp);
	for(i=0;i<n;i++)
	{
		count=0;
		for(j=i+1;j<n;j++)
		{
			if(!(strcmp(a[i],a[j]))){
			count++;temp = count;if(j==n-1){i=j-1;} }
			else{
			
			printf("%s %d\n",a[i],count+1);
			
			i=j-1;
			break;}
		}
	}
	
	printf("%s %d\n",a[--i],temp+1);
	printf("\n");
}return 0;}

