/*************************************
Author :- Kawar Siddharth Rajendra
Problem Statement :-
http://www.spoj.com/problems/PHONELST
*************************************/
#include<cstdio> 
#include<string.h> 
bool ans; 
struct trie_node{ 
    bool end; 
    trie_node *child[10]; 
}; 
trie_node* getnode(){ 
    trie_node *temp = new trie_node(); 
    temp->end=false; 
    for(int i=0;i<10;i++) 
        temp->child[i]=NULL; 
    return temp; 
} 
void insert(trie_node *root,char num[],int n){ 
    int index; 
    for(int i=0;i<n;i++){ 
        index=num[i]-'0'; 
        if(!root->child[index]) 
            root->child[index]=getnode(); 
        else{ 
            if(i+1==n) 
                ans=true; 
        } 
        root=root->child[index]; 
        if(root->end) 
            ans=true; 
    } 
    root->end=true; 
} 
void deletetrie(trie_node *root){ 
    for(int i=0;i<10;i++){ 
        if(root->child[i]) 
            deletetrie(root->child[i]); 
    } 
    delete(root); 
    root=NULL; 
} 
int main(){ 
    int t,tc=0,n,index,len; 
    scanf("%d",&t); 
    getchar(); 
    char num[11]; 
    while(t--){ 
        ans=false; 
        scanf("%d",&n); 
        getchar(); 
        while(n>0){ 
            scanf("%s",num); 
            trie_node *root = getnode(); 
            trie_node *temp=root; 
            len=strlen(num); 
            for(int i=0;i<len;i++){ 
                index=num[i]-'0'; 
                if(!temp->child[index]) 
                    temp->child[index]=getnode(); 
                temp=temp->child[index]; 
            } 
            temp->end=true; 
            n--; 
            while(n--){ 
                scanf("%s",num); 
                if(!ans) 
                    insert(root,num,strlen(num)); 
            } 
            deletetrie(root); 
        } 
        printf("%s\n",ans?"NO":"YES"); 
    } 
} 