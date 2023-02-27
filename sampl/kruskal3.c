#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 5
#define INT_MAX 999

void dijkstra(int cost[][V], int start, int *dist)
{
    int visited[V] = {0};
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[start] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        int u = -1;
        for (int j = 0; j < V; j++)
        {
            if (!visited[j] && (u == -1 || dist[j] < dist[u]))
            {
                u = j;
            }
        }
        visited[u] = 1;
        for (int v = 0; v < V; v++)
        {
            if (cost[u][v] != INT_MAX && dist[u] + cost[u][v] < dist[v])
            {
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }
}

int main()
{
    int cost[V][V] = {
        {INT_MAX, 2, INT_MAX, 6, INT_MAX},
        {2, INT_MAX, 3, 8, 5},
        {INT_MAX, 3, INT_MAX, INT_MAX, 7},
        {6, 8, INT_MAX, INT_MAX, 9},
        {INT_MAX, 5, 7, 9, INT_MAX},
    };

    int min_cost = INT_MAX;
    for (int i = 0; i < V; i++)
    {
        int dist[V];
        dijkstra(cost, i, dist);
        for (int j = 0; j < V; j++)
        {
            if (i != j && dist[j] < min_cost)
            {
                min_cost = dist[j];
            }
        }

        printf("Minimum cost from %d: %d \n", i, min_cost);
    }
    printf("Minimum cost: %d\n", min_cost);

    return 0;
}
