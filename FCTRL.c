/*************************************
Author :- Kawar Siddharth Rajendra
Problem Statement :-
http://www.spoj.com/problems/FCTRL
*************************************/
#include<stdio.h>
#include<math.h>
int main()
{
	int n,i,j=1;
	unsigned long int num1,p=0,k=0;
	scanf("%d\n",&n);
	for(i=0;i<n;i++)
	{	k=0,j=1;
		//unsigned long int num1,k=0;
		scanf("%lu",&num1);
		p=pow(5,j);
		while(num1/p)
		{
			k=k+num1/p;
			j++;
			p=pow(5,j);
		}
		printf("%lu\n",k);
	}
	return 0;
}
