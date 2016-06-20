/*************************************
Author :- Kawar Siddharth Rajendra
Problem Statement :-
http://www.spoj.com/problems/TEST
*************************************/
#include <stdio.h>
int main()
{
	int x;
	
	while(scanf("%d",&x)!=EOF)
	{
	   if(x!=42)
	   		printf("%d\n",x);
	   else
       		break;
	 }
	 return 0;
}