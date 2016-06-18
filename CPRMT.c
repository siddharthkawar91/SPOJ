/***********************************

http://www.spoj.com/problems/CPRMT

***********************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	
	int c[26],b[26],i,j,t,count=0,ct=-1;
	char st1[1001],st2[1001],str3[1001];
	while((scanf("%s\n",st1)!=EOF)&&(scanf("%s",st2)!=EOF))
	{
		
		if((atoi(st1)==EOF)||(atoi(st2)==EOF))return 0;		
                for(i=0;i<26;i++)
		{
			c[i]=0;b[i]=0;
		}
		for(j=0;st1[j];j++)
		c[st1[j]-'a']++;
		for(j=0;st2[j];j++)
		b[st2[j]-'a']++;
		for(i=0;i<26;i++)
		{
			if(c[i]>=b[i])
			{
				
				for(t=0;t<b[i];t++){
				ct++;
				str3[ct]=i+'a';}				
			}
			else
			{
				
				for(t=0;t<c[i];t++){
				 ct++;
				str3[ct]=i+'a';	}
			}
			
		}
		ct++;str3[ct]='\0';
		printf("%s\n",str3);								
		
		ct=-1;
	}
	return 0;
}

