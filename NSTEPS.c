/*************************************
Author :- Kawar Siddharth Rajendra
Problem Statement :-
http://www.spoj.com/problems/NSTEPS
*************************************/
#include<stdio.h>
int main()
{
	int n1;
	scanf("%d",&n1);
	while(n1--){
	int a,b;
	scanf("%d %d",&a,&b);
	if(b>a)printf("No Number\n");
	else if((a%2==0)&&(b%2==0)&&((a+b)%2==0)&&((a==b)||(b==a-2)))printf("%d\n",a+b);
	else if((a%2!=0)&&(b%2!=0)&&((a+b)%2==0)&&((a==b)||(b==a-2))) printf("%d\n",a+b-1);
	else 
	printf("No Number\n");}
return 0;
}