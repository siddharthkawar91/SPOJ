/*************************************
Author :- Kawar Siddharth Rajendra
Problem Statement :-
http://www.spoj.com/problems/SUMITR
*************************************/
main(){int n,n1,a[99][99],i,j;scanf("%d",&n1);while(n1--){scanf("%d",&n);for(i=0;i<n;i++)for(j=0;j<i+1;j++)scanf("%d",&a[i][j]);for(i=n-1;i>=0;i--)for(j=0;j<n;j++)a[i-1][j]=a[i-1][j]+(a[i][j]>a[i][j+1]?a[i][j]:a[i][j+1]);printf("%d\n",a[0][0]);}return 0;}
