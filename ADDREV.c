/*****************************************************

Link to the problem

http://www.spoj.com/problems/ADDREV/
*****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	int i,n;

	scanf("%d",&n);
	for(i=0;i<n;i++){
	char nu1[1000],nu2[1000],nr1[1000],nr2[1000],nr3[1000];
	int num1,i,p=-1,num2,j=0,num3;
	int rev=0,k;
	num3=0;
	scanf("%s %s",nu1,nu2);
	reverse(&nu1,&nr1);
	reverse(&nu2,&nr2);
	num1=atoi(nr1);
	num2=atoi(nr2);
	num3=num1+num2;
	k=multiple(num3);
	rev=reversen(num3,k);
	printf("%d\n",rev);	
	
}return 0;}
reverse(char *nu1,char *nr1)
{
	int p=0,j=0;
	while(*(nu1+p))
	{	
		//printf("check1\n");
		p++;
	}
	p--;
	while(p>=0)
	{
		*(nr1+j)=*(nu1+p);
		j++;
		p--;
	}
	
	*(nr1+j)='\0';
}
int reversen(int num,int j)
     {
        int c=0;
        if(num>=0&&num<=9)
        return num;
        else
        return (num%10)*pow(10,j-1) + reversen(num/10,j-1);
     }
     int multiple(int num)
     {
        int c,j=0;
        c=num;
	while(c!=0)
        {
	    c= c/10;
            j++;
        }
        return j;
     }
