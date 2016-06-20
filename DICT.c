/*************************************
Author :- Kawar Siddharth Rajendra
Problem Statement :-
http://www.spoj.com/problems/DICT
*************************************/

#include<stdio.h>
#include<cstdio>
struct NTrie
{
	int value;
	int prefix;
	struct NTrie *children[26];
};
void Traverse_Trie(struct NTrie*, int, char[], int);
struct NTrie* getNode()
{
	struct NTrie *pNode;
	pNode = new NTrie();
	pNode->value = 0;
	pNode->prefix = 0;
	int i=0;
	for(i=0;i<26;i++)
		pNode->children[i] = NULL;
		
	return pNode;
}
int Strlen(char key[])
{
	int i=0;
	while(key[i]!='\0')
		i++;
	
	return i;
}
void Insert(struct NTrie *pTrie, char Key[])
{
	int level;
	int length = Strlen(Key);
	int index;
	struct NTrie *pCrawl;
	
	pCrawl = pTrie;
	int flag=0;
	for(level=0;level < length; level++)
	{
		flag=0;
		index = Key[level] - 'a';
		
		if(!pCrawl->children[index])
		{
			pCrawl->children[index] = new struct NTrie();
			flag=1;
		}	
		else
		{
			pCrawl->children[index]->value=0;
		}	
		pCrawl = pCrawl->children[index]; 
	}
	if(flag)
	{
		pCrawl->value = 1;
	}	
	pCrawl->prefix = 1;
}

void Traverse_Trie1(struct NTrie *pTrie, int level,char str[],int index)
{
	//printf("Traverse1\n");
	//printf("%d \n",level);
	if(pTrie==NULL)
	{
		printf("No match.\n");
	}
	if(pTrie->value)
	{
		//printf("Reached the end.....\n");
		str[level] = 'a' + index;
		level++;
		str[level] = '\0';
		printf("%s\n",str);
	}
	//printf("%d-\n",pTrie->prefix);
	if(pTrie->prefix && pTrie->value!=1&&index!=-1)
	{
		//printf("check1 %d\n",index);
		
		str[level] = 'a' + index;
		
		int i;
		for(i=0;i<=level;i++)
			printf("%c",str[i]);
		
		printf("\n");
	}
	int i=0;
	if(index!=-1)
	{
		//printf("%c \n",'a' + index);
		str[level] = 'a' + index;
	}	
	for(i=0;i<26;i++)
	{
		if(pTrie->children[i])
			Traverse_Trie1(pTrie->children[i],level+1,str,i);	
	}	
}
int main()
{
	int N;
	scanf("%d",&N);
	struct NTrie *pTrie,*pCrawl;
	pTrie = getNode();
	int i;
	char Key[21];
	char str[21];

	for(i=0;i<N;i++)
	{
		scanf("%s",Key);
		Insert(pTrie,Key);
	}
	int M;
	scanf("%d",&M);
	int j;
	for(j=1;j<=M;j++)
	{
		scanf("%s",Key);
		printf("Case #%d:\n",j);
		int level;
		int length = Strlen(Key);
		int index;
		int flag=0;
		pCrawl = pTrie;
		for(level = 0; level < length; level++)
		{
			index = Key[level] - 'a';
			str[level] = Key[level];
			if(!pCrawl->children[index])
			{
				flag=1;
				break;
			}	
			pCrawl = pCrawl->children[index];
		}
		
		if(!flag)
		{	
			Traverse_Trie1(pCrawl,level-1,str,-1);
		}		
		else
			printf("No match.\n");
	}		
}