// Online C compiler to run C program online
#include <stdio.h>
int p[9];
int r[9];

void makeSet(int x)
{
    p[x] = x;
    r[x] = 0;
}
void unionSet(int x, int y)
{
    x = find(x);
    y = find(y);
    link(x, y);
}
int find(int x)
{
    if (x != p[x])
    {
        p[x] = find(p[x]);
    }
    return p[x];
}
void link(int x, int y)
{
    if (r[x] > r[y])
    {
        p[y] = x;
    }
    else
    {
        p[x] = y;
        if (r[x] == r[y])
        {
            r[y] = r[y] + 1;
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
        printf("Perent of %d is %d", i, p[i]);
        printf(" rank of %d is %d \n", i, r[i]);
    }

    return 0;
}