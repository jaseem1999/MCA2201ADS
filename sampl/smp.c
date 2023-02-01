#include <stdio.h>
#include <stdlib.h>

void main()
{
    int arr1[5], arr2[5], arr[10]; // DECLARING ARRAYS
    int merge;                     // DECLARING VARIABLE MERGIN MAIN ARRAY AND SECOND ARRAY
    int i, j ,temp, temp2;                      // DECLARING VARIABLES FOR LOOP

    printf("Enter the values of first array: \n");
    for (i = 0; i < 5; i++) // READING USER INPUT FOR FIRST ARRAY
    {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the values of second array: \n");
    for (i = 0; i < 5; i++) // READING USER INPUT FOR SECOND ARRAY
    {
        scanf("%d", &arr2[i]);
    }
    // sorting array1 and array2
    for (i = 0; i < 5; i++)
    {
        for (j = i + 1; j < 5; j++)
        {
            if (arr1[i] > arr1[j] && arr2[i]>arr2[j])
            {
                temp = arr1[i];
                temp2 = arr2[i];
                arr1[i] = arr1[j];
                arr2[i] = arr2[j];
                arr1[j] = temp;
                arr2[j] = temp2;
            }
        }
    }

    // merging array 1 and array 2

    merge = 0;
    for (i = 0; i < 10; i++)
    {
        arr[i] = arr1[i];
        if (i > 4)
        {
            arr[i] = arr2[merge];
            merge++;
        }
    }
    // displaying the merged array
    printf("The merged array is: \n");
    for (i = 0; i < 10; i++)
    {
        for (j = i + 1; j < 10; j++)
        {
            if (arr[j] < arr[i])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    // displaying the merged array
    for (i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
}