#include<stdio.h>

int linearSearch(int arr[],int n,int target){
    for(int i=0;i<n;i++){
        if (arr[i] == target){
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[],int target,int n){
    int left = 0, right = n-1;

    while (left <= right){

    int mid = (left + right)/2;

    if (arr[mid] == target){
        return mid;
    }
    else if (arr[mid] < target){
        left = mid+1;
    }
    else{
        right = mid-1;
    } 
    }
    return -1;
 }

int main(){
    int arr[] = {10,20,30,40,50,60};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 20;
    // int found = 0;
    
    // for(int i=0;i<n;i++){
    //     if (arr[i] == target){
    //         printf("Found at index %d\n",i);
    //         found = 1;
    //         break;
    //     }
    // }
    // if (!found){
    //     printf("Not found");
    // }
    int index = linearSearch(arr,n,target);
    if (index != -1){
        printf("Found at index %d\n",index);
    }
    else{
        printf("Not found\n");
    }
    
    index = binarySearch(arr,target,n);
    if (index != -1){
        printf("Found at index %d\n",index);
    }
    else{
        printf("Not found\n");
    } 
    return 0;
}