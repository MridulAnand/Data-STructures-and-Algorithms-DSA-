#include<stdio.h>

void printArray(int arr[], int n){
    for (int i = 0 ;i < n; i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

void selectionSort(int arr[], int n){  // neither stable nor addaptive algorithm
    int indexOfMin;
    for(int i = 0; i < n-1; i++){
        indexOfMin = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[indexOfMin]){
                indexOfMin = j;
            }
        }  
        int temp = arr[i];
        arr[i] = arr[indexOfMin];
        arr[indexOfMin] = temp;
                
    }
      
}

int main(){
      int arr[] = {1,0,5,2,4,3};
    //   int arr[] = {0,1,2,3,4,5};
      int n = sizeof(arr)/sizeof(arr[0]);

      printf("Printing array before sorting :\n");
      printArray(arr, n);

      printf("Printing array after sorting :\n");
      selectionSort(arr, n);
      printArray(arr, n);

    return 0;
}