#include <stdio.h>

int main()
{
    int a1[5] = {5, 2, 5, 1, 4}, a2[5] ={1, 11, 5, 12, 13}, r[10];
    int i, j=0;
    for (i = 0; i < 10; i++)
    {
        r[i] = a1[i];
        if (i > 4)
        {
            r[i] = a2[j];
            j++;
        }
    }
    printf("after merge: \n");
    for (i = 0; i < 10; i++)
    {
        printf(" %d ", r[i]);
    }
    printf("\nafter sort: \n");
    for (i = 0; i < 10; i++)
    {
        for (j = i + 1; j < 10; j++)
        {
            if (r[i] > r[j])
            {
                int temp = r[i];
                r[i] = r[j];
                r[j] = temp;
            }
        }
        printf(" %d ", r[i]);
    }
    return 0;
}