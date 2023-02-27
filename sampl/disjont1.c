// Online C compiler to run C program online
#include <stdio.h>
int parent[9];
int rank[9];

void makeSet(int x)
{
    parent[x] = x;
    rank[x] = 0;
}
void unionSet(int x, int y)
{
    x = findSet(x);
    y = findSet(y);
    link(x, y);
}
int findSet(int x)
{
    if (x != parent[x])
    {
        parent[x] = findSet(parent[x]);
    }
    return parent[x];
}
void link(int x, int y)
{
    if (rank[x] > rank[y])
    {
        parent[y] = x;
    }
    else
    {
        parent[x] = y;
        if (rank[x] == rank[y])
        {
            rank[y] = rank[y] + 1;
        }
    }
}

int main()
{
    int i;
    makeSet(0);
    makeSet(1);
    makeSet(2);
    makeSet(3);
    makeSet(4);
    makeSet(5);
    makeSet(6);
    makeSet(7);
    makeSet(8);
    unionSet(2, 1);
    unionSet(4, 3);
    unionSet(6, 5);
    unionSet(3, 1);
    unionSet(5, 1);
    unionSet(8, 7);
    unionSet(7, 1);
    for (i = 1; i < 9; i++)
    {
        printf("Parent of %d is %d.", i, parent[i]);
        printf("Rank of %d is %d.\n", i, rank[i]);
    }
    return 0;
}