/*************************************
Author :- Kawar Siddharth Rajendra
Problem Statement :-
http://www.spoj.com/problems/JULKA
*************************************/
#include<stdio.h>
int Divison(char a[],char r[]);
int subtract(char a[], char s[], char r[],char r2[]);
int main()
{

    int n=0;
    for(n=0;n<10;n++)
    {
        char a[200];
        char a1[200];
        scanf("%s",a);
        int i=0,j=0;
        while(*(a+i)!='\0')
        {
            a1[j] = *(a+i);
            i++;
            j++;
        }
        a1[j] = '\0';

        char s[200];
        scanf("%s",s);

        char r[200];
        char r1[200];
        char r2[200];
        subtract(a,s,r,r2);
        Divison(r2,r1);
        subtract(a1,r1,r,r2);

        i=0;
        while(*(r2+i) == '0')
        {
            if(*(r2+i+1)=='\0')
            printf("0");
            i++;
        }
        while(*(r2 + i) != '\0')
        {
            printf("%c",*(r2+i));
            i++;
        }
        printf("\n");
        i=0;
        while(*(r1+i)=='0')
        {
            if(*(r1+i+1)=='\0')
            printf("0");
            i++;
        }
        while(*(r1 + i) != '\0')
        {
            printf("%c",*(r1+i));
            i++;
        }
        printf("\n");
    }
	return 0;
}
int subtract(char a[], char s[], char r[], char r2[])
{
    int i=0;
    int back =0;
    int lena;
    int lens;
    while(*(a+i) != '\0')
        i++;
    lena = i;
    i=0;
    while(*(s+i) != '\0')
        i++;
    lens = i;
    int k=0,j=0;
    for(i=lena-1,j=lens-1; i>=0 && j>=0; i--,j--)
    {
        if(a[i] >= s[j])
        {
            r[k] = '0' + a[i] - s[j];
            k++;
        }
        else
        {
            r[k] = '0' + 10 + a[i] - s[j];
            k++;
            a[i-1]--;
        }
    }
    int m=0;
    if(i>=0)
    {
        for(m=i; m>=0; m--)
        {
            if(a[m] >= '0')
            {
                r[k] =  a[m];
                k++;
            }
            else
            {
                r[k] =  a[m]+ 10 ;
                k++;
                a[m-1]--;
            }
        }
    }
    m = k-1;
    if(r[m]=='0')m--;
    for(i=0;m>=0;m--,i++)
    {
        r2[i] = r[m];
    }
    r2[i] = '\0';
    return 0;
}
int Divison(char a[],char r[])
{
    int i=0;
	int back=0;
	int num;
	int j=0;

	while(*(a+i) != '\0')
	{
		if(*(a+i) < '2')
		{
		    if(back==0)
		    {
                back = *(a+i)-'0';
                r[j] = '0';
                j++;
            }
			else
			{
			    num = ( back *10 + (*(a+i)-'0') )/2 ;
			    back = ( back *10 + (*(a+i)-'0') )%2;
			    r[j] = '0' + num;
                j++;
			}
		}
		else if(*(a+i) >= '2')
		{
            num = ( back *10 + (*(a+i)-'0' ) )/2 ;
            back=( back *10 + (*(a+i)-'0' ) )%2 ;
            r[j]= '0' + num;
            j++;
		}
	    i++;
	}
	r[j] = '\0';
    return 0;
}
