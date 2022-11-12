#include <stdio.h>

void main(){
    int arr[10],arr1[5],arr2[5];
    int i,j,k,merge;
    printf("Enter 5 numbers:  in array 1 \n");
    for(i=0;i<5;i++){
        scanf("%d",&arr1[i]);
    }
    printf("Enter 5 numbers:  in array 2 \n");
    for(i=0;i<5;i++){
        scanf("%d",&arr2[i]);
    }
    for(i=0;i<5;i++){
        for(j=i+1;j<5;j++){
            if(arr1[i]>arr1[j]){
                k=arr1[i];
                arr1[i]=arr1[j];
                arr1[j]=k;
            }
        }
    }
    for(i=0;i<5;i++){
        for(j=i+1;j<5;j++){
            if(arr2[i]>arr2[j]){
                k=arr2[i];
                arr2[i]=arr2[j];
                arr2[j]=k;
            }
        }
    }
    merge=0;
    for(i=0;i<10;i++){
        arr[i] = arr1[i];
        if (i > 4)
        {
            arr[i] = arr2[merge];
            merge++;
        }
        
    }
    for(i=0;i<10;i++){
        printf(" %d ", arr[i]);
    }

    
}