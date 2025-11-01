#include<stdio.h>
#include<stdlib.h>

void conquer(int arr[], int l, int m, int r){
    int *temp  = (int *)malloc((r-l+1)*sizeof(int));
    int idx1 = l;
    int idx2 = m+1;
    int i = 0;

    while(idx1<=m && idx2<=r){
        if(arr[idx1]<arr[idx2]){
            temp[i++] = arr[idx1++];
        }else{
            temp[i++] = arr[idx2++];
        }
    }
    while(idx1<=m){temp[i++] = arr[idx1++];}
    while(idx2<=r){temp[i++] = arr[idx2++];}

    for(int j = 0; j<i; j++){
        arr[j+l] = temp[j];
    }
    free(temp);
}

void mergeSort(int arr[], int l, int r){
    if(l<r){
        int m = l + (r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        conquer(arr, l, m, r);
    }
}

void printArray(int arr[], int size){
    for(int i = 0; i<size; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int arr[] = {9,8,7,6,5,4,3,2,1,0};
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("Array Before Sorting :- ");
    printArray(arr, size);

    mergeSort(arr, 0, size-1);

    printf("\nArray After Sorting :- ");
    printArray(arr, size);
}