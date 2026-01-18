#include<stdio.h>

void printArray(int arr[], int n){
    for (int i = 0 ;i < n; i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

void insertionSort(int arr[], int n){  // stable and addaptive algorithm
      for (int i = 1; i < n; i++){  // loop for passes
        int j = i - 1;
        int key = arr[i];
        while (j>=0 && arr[j] > key){ // loop for each pass
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
      }
      
}

int main(){
      int arr[] = {1,0,5,2,4,3};
    //   int arr[] = {0,1,2,3,4,5};
      int n = sizeof(arr)/sizeof(arr[0]);

      printf("Printing array before sorting :\n");
      printArray(arr, n);

      printf("Printing array after sorting :\n");
      insertionSort(arr, n);
      printArray(arr, n);

    return 0;
}