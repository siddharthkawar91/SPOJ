/*************************************
Author :- Kawar Siddharth Rajendra
Problem Statement :-
http://www.spoj.com/problems/PT07Y
*************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Edge
{
    int src, dest;
};
struct Graph
{
    int V, E;
    struct Edge* edge;
};
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph) );
    graph->V = V;
    graph->E = E;

    graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );

    return graph;
}

int find(int parent[], int i)
{
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

int isCycle( struct Graph* graph )
{
   
    int *parent = (int*) malloc( graph->V * sizeof(int) );


    memset(parent, -1, sizeof(int) * graph->V);

 
    int i;
    for(i = 0; i < graph->E; ++i)
    {
        int x = find(parent, graph->edge[i].src);
        int y = find(parent, graph->edge[i].dest);

        if (x == y)
            return 1;

        parent[x] = y;
    }
    return 0;
}


int main()
{
   
	int non,noe;
    scanf("%d %d",&non,&noe);
    struct Graph* graph = createGraph(non, noe);
    int i;
	int a,b;
    for(i=0;i<noe;i++)
    {
        scanf("%d %d",&a,&b);
		a--;b--;
		graph->edge[i].src=a;
		graph->edge[i].dest=b;
    }
    // add edge 0-1
    /*graph->edge[0].src = 0;
    graph->edge[0].dest = 1;

    // add edge 1-2
    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;

    // add edge 0-2
    graph->edge[2].src = 0;
    graph->edge[2].dest = 2;*/

    if (isCycle(graph))
        printf( "NO\n" );
    else
        printf( "YES\n" );

    return 0;
}
