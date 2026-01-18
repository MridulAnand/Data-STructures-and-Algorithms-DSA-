#include<stdio.h>
#include<stdlib.h>

struct circularQueue{
    int size;
    int f;
    int r;
    int * arr;
};

int isEmpty(struct circularQueue * q){
    if (q->r == q->f){
        return 1;
    }
    return 0;
}

int isFull(struct circularQueue * q){
    if ((q->r+1)%q->size == q->f){
        return 1;
    }
    return 0;
}

void encircularQueue(struct circularQueue * q, int val){
    if (!isFull(q)){
        q->r = (q->r+1)%q->size;
        q->arr[q->r] = val;    
    }
    else{
        printf("circularQueue is Full\n");
    }
}

void decircularQueue(struct circularQueue * q){
    if (!isEmpty(q)){
        printf("DecircularQueued element is %d\n",q->arr[(q->f+1)%q->size]);
        q->f = (q->f+1)%q->size;    
    }
    else{
        printf("circularQueue is Empty\n");
    }
}

void display(struct circularQueue * q){
    for(int i = (q->f+1)%q->size ; i!=(q->r+1)%q->size ; i = (i+1)%q->size){
        printf("%d\n",q->arr[i]);
    }
}

void peek(struct circularQueue * q){
    if (!isEmpty(q)){
        printf("Front element is %d\n",q->arr[(q->f+1)%q->size]);
    }
    else{
        printf("circularQueue is empty\n");
    }
}

int main(){
      struct circularQueue * q = (struct circularQueue *)malloc(sizeof(struct circularQueue));
      q->size = 50;
      q->f = -1;
      q->r = -1;
      q->arr = (int *)malloc(sizeof(int)*(q->size));

      encircularQueue(q, 10);
      encircularQueue(q, 20);
      encircularQueue(q, 30);
      encircularQueue(q, 40);
      display(q);
      decircularQueue(q);
      display(q);
      decircularQueue(q);
      display(q);
      peek(q);

    return 0;
}