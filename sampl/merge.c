// Online C compiler to run C program online
#include <stdio.h>

int main()
{
    int arr1[5], arr2[5];
    int arr3[10], i, j;
    int c = 0;
    printf("Enter your arr elements");
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &arr1[i]);
    }
    printf("Enter your arr elements");
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &arr2[i]);
    }

    for (i = 0; i < 10; i++)
    {
        arr3[i] = arr1[i];
        if (i > 4)
        {
            arr3[i] = arr2[c];
            c++;
        }
    }
    printf("Enter your arr mareged\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d ,", arr3[i]);
    }
    for (i = 0; i < 10; i++)
    {
        for (j = i + 1; j < 10; j++)
        {
            if (arr3[i] > arr3[j])
            {
                int temp = arr3[i];
                arr3[i] = arr3[j];
                arr3[j] = temp;
            }
        }
    }
    printf("\nmerged sorted array\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d ,", arr3[i]);
    }

    return 0;
}
