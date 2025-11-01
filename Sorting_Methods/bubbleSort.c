#include<stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubbleSort(int arr[], int size){
    for(int i = 0; i<size; i++){
        for(int j = 0; j<size-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void printArray(int arr[], int size){
    for(int i = 0; i<size; i++){
            printf("%d ", arr[i]);
        }
}

int main(){
    int arr[] = {36,10,9,8,8,5,4,3,2,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, size);
    
    printArray(arr, size);
}