#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define V 5
int perent[V];
int find(int i)
{
    while (perent[i] != i)
        i = perent[i];
    return i;
}
void setUnion(int i, int j)
{
    int a = find(i);
    int b = find(j);
    perent[a] = b;
}

void kruskalMST(int cost[][V])
{
    int i, j, a, b;
    int mincost = 0;
    for (i = 0; i < V; i++)
        perent[i] = i;
    int edge_count = 0;
    while (edge_count < V - 1)
    {
        int min = INT_MAX;
        for (i = 0; i < V; i++){
            for (j = 0; j < V; j++){
                if( find(i) != find(j) && cost[i][j] < min)
                {
                    min = cost[i][j];
                    a =i;
                    b =j;
                }
            }
        }
        setUnion(a, b);
        printf("Edge %d:(%d, %d) cost:%d \n",edge_count++, a, b, min);
        mincost += min;
    }
    printf("\n Minimum cost= %d \n", mincost);

}
int main()
{
    int cost[][V] = { 
        { INT_MAX, 2, INT_MAX, 6, INT_MAX }, 
        { 2, INT_MAX, 3, 8, 5 }, 
        { INT_MAX, 3, INT_MAX, INT_MAX, 7 }, 
        { 6, 8, INT_MAX, INT_MAX, 9 }, 
        { INT_MAX, 5, 7, 9, INT_MAX },
    };
    kruskalMST(cost);
    return 0;
}