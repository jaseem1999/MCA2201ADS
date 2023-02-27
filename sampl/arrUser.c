#include <stdio.h>
#include <stdlib.h>
int a1[100], a2[100];
int main()
{
    int a1_s, a2_s, i, j, total, k = 0;
    printf("\nEnter first array size");
    scanf("%d", &a1_s);
    printf("\nEnter second array size");
    scanf("%d", &a2_s);
    printf("\nEnter first array element::");
    for (i = 0; i < a1_s; i++)
    {
        scanf("%d", &a1[i]);
    }
    printf("\nEnter first array element::");
    for (i = 0; i < a2_s; i++)
    {
        scanf("%d", &a2[i]);
    }
    total = a1_s + a2_s;
    for (i = a1_s; i < total; i++)
    {
        a1[i] = a2[k];
        k++;
    }
    printf("after merge: \n");
    for (i = 0; i < total; i++)
    {
        printf(" %d ", a1[i]);
    }
    printf("\nafter sort: \n");
    for (i = 0; i < total; i++)
    {
        for (j = i + 1; j < total; j++)
        {
            if (a1[i] > a1[j])
            {
                int temp = a1[i];
                a1[i] = a1[j];
                a1[j] = temp;
            }
        }
        printf(" %d ", a1[i]);
    }
    return 0;
}