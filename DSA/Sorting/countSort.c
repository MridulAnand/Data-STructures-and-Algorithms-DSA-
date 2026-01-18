#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

void printArray(int arr[], int n){
    for (int i = 0 ;i < n; i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
int maximum(int arr[], int n){
    int max = INT_MIN;    
    for (int i = 0; i < n; i++){
        if (max<arr[i]){
            max = arr[i];
        }
    }

    return max;
}

void countSort(int arr[], int n){
    int max = maximum(arr, n);  // find the maximum elements in A  
    int * count = (int *)malloc(sizeof(int)*(max+1));  // create the count array
    for (int i = 0; i < max+1; i++){ // initiallize the array elements to 0
        count[i] = 0;
    }
    for (int i = 0; i < n; i++){ // increment the corresponding index in the count array
        count[arr[i]] += 1;
    }
    int i = 0; 
    int j = 0;
    while(i<=max){
        if(count[i]>0){
            arr[j] = i;
            count[i] = count[i]-1;
            j++;
        }
        else{
            i++;
        }    
    }
    free(count);
}   

int main(){
      int arr[] = {1,0,5,2,4,3};
    //   int arr[] = {0,1,2,3,4,5};
      int n = sizeof(arr)/sizeof(arr[0]);

      printf("Printing array before sorting :\n");
      printArray(arr, n);

      printf("Printing array after sorting :\n");
      countSort(arr, n);
      printArray(arr, n);

    return 0;
}
