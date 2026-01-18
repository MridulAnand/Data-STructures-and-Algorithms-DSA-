#include<stdio.h>

void printArray(int arr[], int n){
    for (int i = 0 ;i < n; i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

 int partition(int arr[], int low, int high){ // not stable and it is inplace algorithm
        int pivot = arr[low];
        int i = low+1;
        int j = high;
        do{
            while(arr[i] <= pivot){
                i++;
            }
            while(arr[j] > pivot){
                j--;
            }
            if (i<j){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }while (i<j);

        int temp = arr[j];
        arr[j] = arr[low];
        arr[low] = temp;
        return j;

 }

void quickSort(int arr[], int low, int high){

    if(low<high){
    int partitionIndex = partition(arr, low, high);  // index of pivot after partition
    quickSort(arr, low, partitionIndex-1); // sort left subarray
    quickSort(arr, partitionIndex+1, high); // sort right subarray
    }
      
}

int main(){
      int arr[] = {1,0,5,2,4,3};
    //   int arr[] = {0,1,2,3,4,5};
      int n = sizeof(arr)/sizeof(arr[0]);

      printf("Printing array before sorting :\n");
      printArray(arr, n);

      printf("Printing array after sorting :\n");
      quickSort(arr, 0, n-1);
      printArray(arr, n);

    return 0;
}

// best case and average case : O(nlog n) 
// worst case : If array is already sorted : O(n^2)