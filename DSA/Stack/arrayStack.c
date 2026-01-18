#include<stdio.h>

int arr[20],size = 10,top = -1;

void push(int value){
    if (top + 1 == size){
        printf("Stack Overflow\n");
    }
    else{
        top++;
        arr[top] = value;
    }
}

void pop(){
    if (top == -1){
        printf("Stack Underflow\n");
    }
    else{
        printf("Poped value is %d\n",arr[top]);
        top--;
    }
}

void peek(){
    if (top == -1){
        printf("Empty Stack\n");
    }
    else{
        printf("Peek value is %d\n",arr[top]);
    }
}

void isEmpty(){
    if (top == -1){
        printf("Stack is empty\n");
    }
    else{
        printf("Stack is not empty\n");
    }
}

void isFull(){
    if (top+1 == size){
        printf("Stack is Full\n");
    }
    else{
        printf("Stack is not Full\n");
    }
}


int main(){
    
    push(1);
    push(2);
    for(int i = 0;i <= top;i++){
        printf("%d\n",arr[i]);
    }
    peek();
    pop();
    pop();
    pop();
    for(int i = 0;i <= top;i++){
        printf("%d\n",arr[i]);
    }
    peek();
    isEmpty();
    isFull();

    return 0;
}