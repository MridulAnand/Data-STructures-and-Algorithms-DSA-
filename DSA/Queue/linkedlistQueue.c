#include<stdio.h>

struct Queue{
    int data;
    struct Queue * next;
};

void enqueue(struct Queue ** front,struct Queue ** rear, int val){
     struct Queue * ptr = (struct Queue *)malloc(sizeof(struct Queue));
     if (ptr == NULL){
        printf("Queue Overflow\n");
        return;
     }
     ptr->data = val;
     ptr->next = NULL;
     if (*front == NULL){
        *front = ptr;
        *rear = ptr;
     }
     else{
        (*rear)->next = ptr;
        *rear = ptr;
     }
}

void dequeue(struct Queue ** front,struct Queue ** rear){
    if (*front == NULL){
        printf("Queue Underflow\n");
        return;
    }
    else{
        struct Queue * ptr = *front;
        *front = (*front)->next;
        if (*front == NULL){
            *rear = NULL;
        }
        printf("Dequeuedd element is %d\n",ptr->data); 
        free(ptr);
    }
}

void display(struct Queue * front){
    if (front == NULL){
        printf("Queue is empty\n");
        return;
    }
    else{
        printf("Queue is:\n");
        while (front != NULL){
            printf("%d\n",front->data);
            front = front->next;
        }
    }
}

void peek(struct Queue * front){
    if (front == NULL){
        printf("Queue is empty\n");
        return;
    }
    else{
        printf("Peek element is %d\n",front->data);
    }
}

int main(){
      struct Queue * front = NULL;
      struct Queue * rear = NULL;

      enqueue(&front,&rear,10);
      enqueue(&front,&rear,20);
      enqueue(&front,&rear,30);
      enqueue(&front,&rear,40);
      
      peek(front);
      display(front);

      dequeue(&front,&rear);
      dequeue(&front,&rear);
      
      peek(front);
      display(front);
      
    return 0;
}