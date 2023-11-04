#include <stdio.h>
#include "Queue.h"
#define N 100
int Graph[N][N];
int vertices, edges;
int u, v;
int i, j;
void createGraph()
{
    printf("Enter vertices and Edges:\n");
    scanf("%d%d", &vertices, &edges);
    vertices += 1;
    // Reset graph
    for (i = 0; i <= vertices; ++i)
        for (j = 0; j <= vertices; ++j)
            Graph[i][j] = 0;

    // Input Graph
    printf("Enter (u v):\n");
    for (i = 0; i < edges; ++i)
    {
        scanf("%d%d", &u, &v);
        // Here value of 1 represents there is an edge (u,v)
        Graph[u][v] = Graph[v][u] = 1;
    }
}
void displayGraph()
{
    // Print the current Graph
    printf("\n");
    printf("Graph:\n");
    for (i = 0; i < vertices; ++i)
    {
        for (j = 0; j < vertices; ++j)
            printf("%d ", Graph[i][j]);
        printf("\n");
    }
    printf("\n");
}
void BFS(int Graph[N][N], int start)
{
    int i = start, j;
    int visited[7] = {0};
    printf("%d ", i);
    visited[i] = 1;
    enqueue(i);
    while (!isEmpty())
    {
        i = dequeue();
        for (j = 1; j < vertices; j++)
        {
            if (Graph[i][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
}
void DFS(int Graph[N][N], int start)
{
    static int visited[7] = {0};
    int j;
    /*printf("Enter the starting index: ");
    scanf("%d", &start);*/
    if (visited[start] == 0)
    {
        printf("%d ", start);
        visited[start] = 1;
        for (j = 1; j < vertices; j++)
        {
            if (Graph[start][j] == 1 && visited[j] == 0)
                DFS(Graph, j);
        }
    }
}
int main()
{
    /*int choice;

    while (1)
    {
        switch (choice)
        {
        case 1:
            createGraph();
            break;
        case 2:
            displayGraph();
            break;
        case 3:
            BFS();
            break;
        case 4:
            DFS();
            break;
        }
    }*/
    printf("Undirected Unweighted Graph:\n");
    printf("============================\n\n");

    createGraph();
    displayGraph();
    /*int G[7][7] = {{0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 1, 0, 0}};
    DFS(G, 4, 7);*/
    DFS(Graph, 4);
    return 0;
}