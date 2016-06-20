/*************************************
Author :- Kawar Siddharth Rajendra
Problem Statement :-
http://www.spoj.com/problems/NHAY
*************************************/
/*This is a program to implement the Knuth-prat-morris algorithm(KMP)*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *p;
char  s[1000000];
unsigned long long int *T;
int count=0;
void preprocess_kmp(unsigned long long int);
int Kmp_Search(unsigned long long int,unsigned long long int);
int main()
{
	unsigned long long int len;
	while(scanf("%llu",&len)!=EOF)
	{	count=0;
		unsigned long long int i,j,m,k,num;
		unsigned long long int counter=0;
		char ch;
		
		
		p=(char *)malloc((len+1)*sizeof(char));
		T=(unsigned long long int *)malloc((len+1)*sizeof(unsigned long long int));

		ch=getchar();
		do{
			ch=getchar();
			p[counter]=ch;
			counter++;
		}while(ch!='\n');
		counter--;
		p[counter]='\0';

		
		counter=0;num=1;
		
	
		do{
			ch=getchar();
			s[counter]=ch;
			counter++;
		}while(ch!='\n');
		counter--;
		s[counter]='\0';
		j=strlen(s);

		T[0] = -1;T[1] = 0;
		preprocess_kmp(len);
		Kmp_search(len,j);
		printf("\n");
	}
	return 0;
}	
void preprocess_kmp(unsigned long long int len_patt)
{
	unsigned long long int i=2,sub=0;
	
	while(i<len_patt)
	{
		if(p[i-1] == p[sub])
		{
			sub++;
			T[i] = sub;
			i++;
		}

		else if(sub > 0)
		sub = T[sub];

		else{
		T[i] = 0;
		i++;}		

	}
}			
int Kmp_search(unsigned long long int len_patt,unsigned long long int len_text)
{
	unsigned long long int j=0,i=0;
	while(i+j<len_text)
	{
		
		if(p[i] == s[j+i])
		{
			if(i == len_patt - 1)
			{
				 printf("%llu\n",j);
          			 j = j + i -T[i];
				 i = T[i];
			}
			i++;
		}
		else
		{
			j = j+i-T[i];
			if (T[i] > -1)
				i = T[i];
			else
				i=0;	
		}
	}
	return len_text;
}	
						
		
