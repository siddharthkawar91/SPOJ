/***********************************

http://www.spoj.com/problems/CANTON
***********************************/
#include<stdio.h>
int main()
{
	int n,t;
	scanf("%d",&n);
	for(t=0;t<n;t++)
	{	
		unsigned long int term;
		scanf("%lu",&term);
		total(&term);
	}
	return 0;
}
total(unsigned long int *term)
{
	unsigned long int c=0,i,k,j,nr,dr;
	for(i=0;i<(*term);)
	{
		c++;
		k=i;
		for(j=0;j<c;j++)
		{
			i++;
		}
	}
	c++;
	k++;
	//printf("%d %d\n",c,k);
	if((c%2)==0)
	{
		nr = c-1 - (*term-k);
		dr = 1 + (*term-k);
	}	
	else
	{
		nr = 1 + (*term-k);
		dr = c-1-(*term-k);
	}
	printf("TERM %lu IS %lu/%lu\n",*term,nr,dr);
}
