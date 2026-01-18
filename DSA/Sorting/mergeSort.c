#include<stdio.h>

void printArray(int arr[], int n){
    for (int i = 0 ;i < n; i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

void merge(int arr[], int low, int mid, int high){
   int c[50];
   int i,j,k;
   i = k = low;
   j = mid+1;
   while(i<=mid && j<=high){
     if (arr[i] >= arr[j]){
          c[k] = arr[j];
          j++;
          k++;
     }
     else{
        c[k] = arr[i];
        i++;
        k++;
     }
    }
   while(i<=mid){
    c[k] = arr[i];
    i++;
    k++;
   }
   while(j<=high){
    c[k] = arr[j];
    j++;
    k++;
   }
   for(i = low;i<=high;i++){ // copying sorted value in original array;
    arr[i] = c[i];
   }

}

void mergeSort(int arr[], int low, int high){ // stable algorithm
    if (low<high){
    int mid = (low+high)/2;
    mergeSort(arr,low,mid); // for left half
    mergeSort(arr,mid+1,high); // for right side
    merge(arr,low,mid,high); // merge sorted arrays
    }
}

int main(){
      int arr[] = {1,0,5,2,4,3};
    //   int arr[] = {0,1,2,3,4,5};
      int n = sizeof(arr)/sizeof(arr[0]);

      printf("Printing array before sorting :\n");
      printArray(arr, n);

      printf("Printing array after sorting :\n");
      mergeSort(arr, 0, n-1);
      printArray(arr, n);

    return 0;
}
