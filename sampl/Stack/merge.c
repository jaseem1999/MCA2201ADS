// Online C compiler to run C program online
#include <stdio.h>
int arr1[50];
int arr2[50];
int main()
{
    int i;
    int k = 0;
    int total;
    int a1_size = 0;
    int a2_size = 0;
    int j = 0;
    printf("\nEnter the 1array size:: ");
    scanf(" %d", &a1_size);
    printf("\nEnter the 2array size::");
    scanf(" %d", &a2_size);
    printf("\nEnter the 1array elements::");
    for (i = 0; i < a1_size; i++)
    {
        scanf(" %d", &arr1[i]);
    }

    printf("\nEnter the 2array elements::");
    for (i = 0; i < a2_size; i++)
    {
        scanf(" %d",&arr2[i]);
    }
    total = a1_size + a2_size;
    for (i = a1_size; i < total; i++)
    {
        arr1[i] = arr2[k];
        k = k + 1;
    }
    for (i = 0; i < total; i++)
    {
        printf("Array_[%d] is : %d\n", i, arr1[i]);
    }
    for (i = 0; i < total; i++)
    {
        for(j = i+1; j < total; j++)
        {
            if(arr1[i] > arr1[j])
            {
                int temp = arr1[i];
                arr1[i] = arr1[j];
                arr1[j] = temp;
            }
        }
    }
    printf("\nAfter sorting the array is::\n");
    for (i = 0; i < total; i++)
    {
        printf("Array_[%d] is : %d\n", i, arr1[i]);
    }

    return 0;
}