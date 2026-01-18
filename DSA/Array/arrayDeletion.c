#include<stdio.h>

void display(int arr[],int n){ 
    for(int i = 0; i < n ; i++){
        printf("%d\n",arr[i]);
    }
}

void indDeletion(int arr[], int n, int index){       
 for (int i = index; i < n-1; i++){
        arr[i] = arr[i+1];
 }
arr[n-1] = 0;

}

int main(){
   int arr[4] = {10,20,30,40};   
   int n = 4, index = 2;
     indDeletion(arr, n, index);
     n -= 1;
     display(arr,n);
   return 0;
}