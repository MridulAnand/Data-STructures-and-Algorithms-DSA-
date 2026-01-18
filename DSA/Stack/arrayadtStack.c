#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack * ptr){
    if (ptr->top == -1){
        return -1;
    }
    return 0;
}

int isFull(struct stack * ptr){
    if (ptr->top+1 == ptr->size){
        return -1;
    }
    return 0;
}

int push(struct stack * ptr, int value){
    if (isFull(ptr) == -1){
        printf("Stack Overflow\n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
    return ptr;
}

int pop(struct stack * ptr){
    if (isEmpty(ptr) == -1){
        printf("Stack Underflow\n");
    }
    else{
        printf("Poped value is %d\n",ptr->arr[ptr->top]);
        ptr->top--;
    }
    return ptr;
}

void peek(struct stack * ptr){
    if (isEmpty(ptr) == -1){
        printf("Empty Stack\n");
    }
    else{
        printf("Peek value is %d\n",ptr->arr[ptr->top]);
    }
}

void traverseStack(struct stack * ptr){
    for(int i = 0;i<=ptr->top;i++){
        printf("%d\n",ptr->arr[i]);
    }
}

int main(){
    // struct stack s;
    // s.size = 80;
    // s.top = -1;
    // s.arr = (int *)malloc(s.size*sizeof(int));

    struct stack * s; // or struct stack * s = (struct stack *)malloc(sizeof(struct stack));  to avoid segmentation fault
    s->size = 80;
    s->top = -1;
    s->arr = (int *)malloc(s->size*sizeof(int));

    s = push(s,1);
    s = push(s,2);
    traverseStack(s);
    peek(s);

    s = pop(s);
    s = pop(s);
    s = pop(s);
    traverseStack(s);
    peek(s);

    if (isEmpty(s) == -1){
        printf("Stack is Empty\n");
    }
    else{
        printf("Stack is not Empty");
    }
    if (isFull(s) == -1){
        printf("Stack is Full\n");
    }
    else{
        printf("Stack is not Full");
    }
      
    return 0;
}