#include<stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b; 
    *b = temp;
}

void selectionSort(int arr[], int size){
    for(int i = 0; i<size-1; i++){
        int min = i;
        for(int j = i+1; j<size; j++){
            if(arr[j]<arr[i]){
                min = j;
            }
        }
        if(min!=i){
            swap(&arr[i], &arr[min]);
        }
    }
}
void printArray(int arr[], int size){
    for(int i = 0; i<size; i++){
            printf("%d ", arr[i]);
        }
}

int main(){
    int arr[] = {10, 9,8,7,6,5,4,3,11,2, 10};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Array Before Sorting :- ");
    printArray(arr, size);

    selectionSort(arr, size);

    printf("\nArray After Sorting :- ");
    printArray(arr, size);
}