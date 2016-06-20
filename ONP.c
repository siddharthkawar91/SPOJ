/*************************************
Author :- Kawar Siddharth Rajendra
Problem Statement :-
http://www.spoj.com/problems/ONP
*************************************/
#include<stdio.h>
int strlength(char *exp);
int check(char expr,char stack[],int a[]);
int push(char expr,char stack[],int a[]);
int print(char stack[],int a[]);
int i=-1;
int main()
{
	int q=0,m=0,n;
	scanf("%d",&q);
	n=q;
	do
	{	n--;
		char exp[405],stack[405];
		int len;
		int a[94],t=0,j=0,k=0;
		for(k=0;k<94;k++)
		a[k]=0;
		a['+'] = 1;a['-'] = 2;a['*']=3;a['/']=4;a['^']=5;
		a['(']=-1;a[')']=0;
		scanf("%s",exp);
		len=strlength(exp);
		for(j=0;j<len;j++)
		{
			if( (exp[j]>=65&&exp[j]<=90) || (exp[j]>=97&&exp[j]<=122) )
			{
				printf("%c",exp[j]);
			}
			else if( (a[exp[j]]>0)&&(a[exp[j]]<6) )
			{
				t=check(exp[j],stack,a);
				if(t==1)
				{
					print(stack,a);
					push(exp[j],stack,a);
				}													
				if(t==2)
				push(exp[j],stack,a);
			}
			else if( a[exp[j]]==-1 )
			push(exp[j],stack,a);
			else if(a[exp[j]]==0)
			print(stack,a);
		}
		while(i--)
		{	
			if(a[stack[i]]!=-1)
			printf("%c",stack[i]);
		}
		printf("\n");
	}while(n);
	return 0;
}
int strlength(char *str)
{
	int k=0;
	while(*(str++))
	k++;
	return k;
}
int check(char expr,char stack[],int a[])		
{	
	if(i==0)
	return 2;
	else if( a[stack[i]]>a[expr] )
	{
		printf("Enter\n");
		return 1;
	}
	else
	return 2;
}		
int push(char expr,char stack[],int a[])
{
	i++;	
	stack[i]=expr;
}
int print(char stack[],int a[])
{
	if(a[stack[i]]==-1)
	{
		while(a[stack[i]]==-1)
		i--;
	}
	while(a[stack[i]]!=-1)
	{	
		printf("%c",stack[i]);
		i--;
	}
}	
