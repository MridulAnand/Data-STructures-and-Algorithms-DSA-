#include<stdio.h>

void printArray(int arr[], int n){
    for (int i = 0 ;i < n; i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

//  stable algorithm
void bubbleSort(int arr[], int n){
    
    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-1; j++){   // for optimisation we can use j < n-1-i
           if (arr[j] > arr[j+1]){
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
           }
        }
       
    }
}

void bubbleSort_addaptive(int arr[], int n){
    
    for (int i = 0; i < n-1; i++){
        int is_sorted = 0;
        for (int j = 0; j < n-1; j++){   // for optimisation we can use j < n-1-i
           if (arr[j] > arr[j+1]){
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
            is_sorted = 1;
           }
        }
        if (!is_sorted){ // or if (is_sorted == 0){}
            break;  //array is sorted
        }
    }
}

int main(){
      int arr[] = {1,0,5,2,4,3};
    //   int arr[] = {0,1,2,3,4,5};
      int n = sizeof(arr)/sizeof(arr[0]);

      int arr1[] = {1,0,4,2,3,3};
      int n1 = sizeof(arr1)/sizeof(arr1[0]);

      printf("Printing array before sorting :\n");
      printArray(arr, n);

      printf("Printing array after sorting (Normal) :\n");
      bubbleSort(arr, n);
      printArray(arr, n);

      printf("Printing array before sorting :\n");
      printArray(arr1, n1);

      printf("Printing array after sorting (addaptive) :\n");
      bubbleSort_addaptive(arr1, n1);
      printArray(arr1, n1);

    return 0;
}