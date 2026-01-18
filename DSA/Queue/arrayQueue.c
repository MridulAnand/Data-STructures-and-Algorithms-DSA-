#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int size;
    int f;
    int r;
    int * arr;
};

int isEmpty(struct Queue * q){
    if (q->r == q->f){
        return 1;
    }
    return 0;
}

int isFull(struct Queue * q){
    if (q->r+1 == q->size){
        return 1;
    }
    return 0;
}

void enqueue(struct Queue * q, int val){
    if (!isFull(q)){
        q->r++;
        q->arr[q->r] = val;    
    }
    else{
        printf("Queue is Full\n");
    }
}

void dequeue(struct Queue * q){
    if (!isEmpty(q)){
        printf("Dequeued element is %d\n",q->arr[q->f+1]);
        q->f++;    
    }
    else{
        printf("Queue is Empty\n");
    }
}

void display(struct Queue * q){
    for(int i = q->f+1;i<=q->r;i++){
        printf("%d\n",q->arr[i]);
    }
}

void peek(struct Queue * q){
    if (!isEmpty(q)){
        printf("Front element is %d\n",q->arr[q->f+1]);
    }
    else{
        printf("Queue is empty\n");
    }
}

int main(){
      struct Queue * q = (struct Queue *)malloc(sizeof(struct Queue));
      q->size = 50;
      q->f = -1;
      q->r = -1;
      q->arr = (int *)malloc(sizeof(int)*(q->size));

      enqueue(q, 10);
      enqueue(q, 20);
      enqueue(q, 30);
      enqueue(q, 40);
      display(q);
      dequeue(q);
      display(q);
      dequeue(q);
      display(q);
      peek(q);

    return 0;
}