/*************************************
Author :- Kawar Siddharth Rajendra
Problem Statement :-
http://www.spoj.com/problems/FENCE1
*************************************/
#include<stdio.h>
int main()
{
	float L;
	float f;
	//printf("%f\n",acos(-1.0));
	while(1)
	{
		scanf("%f",&L);
		if(L==0.00)break;
		printf("%.2f\n",(L*L/2)/acos(-1.0));
		
	}
	return 0;
}