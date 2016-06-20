/*************************************
Author :- Kawar Siddharth Rajendra
Problem Statement :-
http://www.spoj.com/problems/PIR
*************************************/
#include<stdio.h>
#include<math.h>
int main(){
		int o,n;
		scanf("%d",&n);
		for(o=0;o<n;o++){
		long double u, v, w, W, V, U,Volume;
		scanf("%Lf %Lf %Lf %Lf %Lf %Lf",&u,&v, &w, &W, &V, &U);
		long double u2=pow(u,2);
		long double U2=pow(U,2);
		long double w2=pow(w,2);
		long double W2=pow(W,2);
		long double v2=pow(v,2);
		long double V2=pow(V,2);	
		Volume=sqrt(4*((u2)*(v2)*(w2)) - (u2)*pow(((v2)+(w2)-(U2)),2) - (v2)*pow(((w2)+(u2)-(V2)),2) - 
		(w2)*pow(((u2)+(v2)-(W2)),2) + ((v2)+(w2)-(U2))*((w2)+(u2)-(V2))*((u2)+(v2)-(W2)))/12;
	
			printf("%.4Lf\n",Volume);		
	}
	return 0;
	
}	
