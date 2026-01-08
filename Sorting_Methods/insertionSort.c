#include<stdio.h>


void insertionSort(int arr[], int size){
    for(int i = 1; i<size; i++){
        int key = arr[i];
        int j = i - 1;
        while (j>=0 && arr[j]>key)  
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void insert(int arr[], int size){
    for(int i  = 1; i< size; i++){
        int key = arr[i];
        int j = i-1;
        while (j>=0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key
    }
}

void printArray(int arr[], int size){
    for(int i = 0; i<size; i++){
            printf("%d ", arr[i]);
        }
}


int main(){
    int arr[] = {9,8,7,6,5,4,3,2,1,0,11};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Array Before Sorting :- ");
    printArray(arr, size);

    insertionSort(arr, size);

    printf("\nArray After Sorting :- ");
    printArray(arr, size);
}