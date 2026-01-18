#include<stdio.h>

void display(int arr[],int n){         // code for traversal
    for(int i = 0; i < n ; i++){
        printf("%d\n",arr[i]);
    }
}

int indInsertion(int arr[],int n,int element,int capacity,int index){ //insertion code
    if (n >= capacity)     
      return -1;

    for (int i = n-1; i >= index; i--){
        arr[i+1] = arr[i];
    }
        arr[index] = element;

    return 1;

}   

int main(){
    int arr[100] = {1,2,6,78};
    // int n = sizeof(arr)/sizeof(arr[0]);
    int n = 4, element = 45, index = 3;
    // display(arr,n);
    if (indInsertion(arr,n,element,100,index)){
    n += 1;
    display(arr,n);
    }
    else{
        printf("Insertion in not successful");
    }
    return 0;
}

