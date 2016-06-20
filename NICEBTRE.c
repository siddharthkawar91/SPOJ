/*************************************
Author :- Kawar Siddharth Rajendra
Problem Statement :-
http://www.spoj.com/problems/NICEBTRE
*************************************/
#include<stdio.h>
#include<string.h>
int Index=0;
int MaxHeight(char str[])
{		
		if(str[Index]=='l')
		{
			Index++;
			return 1;
		}	
		Index++;
		int l,r;
		l = 1+MaxHeight(str);
		r = 1+MaxHeight(str);
		if(l>r)
			return l;
		else 
			return r;
}
int main()
{
	int TC;
	scanf("%d",&TC);
	
	while(TC--)
	{
		char str[10050];
		Index=0;
		scanf("%s",str);
		printf("%d\n",MaxHeight(str)-1);
		Index=0;
	}
	return 0;
}