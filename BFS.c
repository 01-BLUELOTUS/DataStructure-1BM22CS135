#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>

#define MAX 50

typedef struct graph
{
    int v;
    bool adj[MAX][MAX];
}graph;

graph* createGraph(int v)
{
    graph* g = (graph*)malloc(sizeof(graph));
    g->v=v;
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            g->adj[i][j]=false;
        }
    }
    return g;
}

void graphDestroy(graph* g)
{
    free(g);
}

void graphAddEdge(graph* g, int v, int w)
{
    g->adj[v][w]=true;
}

void graphBFS(graph* g, int s)
{
    bool visited[MAX];
    for(int i=0;i<g->v;i++)
    {
        visited[i]=false;
    }
    int queue[MAX];
    int front = 0, rear = 0;
    visited[s]=true;
    queue[rear++]=s;
    while(front!=rear)
    {
        s=queue[front++];
        printf("%d",s);
        for(int adjacent=0;adjacent<g->v;adjacent++)
        {
            if(g->adj[s][adjacent]&& !visited[adjacent])
            {
                visited[adjacent]=true;
                queue[rear++]=adjacent;
            }
        }
    }
}

int main()
{
    int numVertices, numEdges, sourceVertex;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);

    graph* g = createGraph(numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    printf("Enter the edges (vertex1 vertex2): \n");
    for (int i = 0; i < numEdges; i++)
    {
        int v, w;
        scanf("%d %d", &v, &w);
        graphAddEdge(g, v, w);
    }

    printf("Enter the source vertex for BFS: ");
    scanf("%d", &sourceVertex);

    printf("BFS traversal starting from vertex %d: ", sourceVertex);
    graphBFS(g, sourceVertex);
    printf("\n");
    graphDestroy(g);

    return 0;
}
