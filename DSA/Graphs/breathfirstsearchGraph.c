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

int dequeue(struct Queue * q){
    if (!isEmpty(q)){
        // printf("Dequeued element is %d\n",q->arr[q->f+1]);
        // q->f++;   
        return q->arr[++q->f];
    }
    else{
        // printf("Queue is Empty\n");
        return -1;
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
    
    // Method used for bfs here is by using queue data structure for exploration queue in which we will store those which are visited but their neighbours are yet to
    // be explored after full exploration we will deque the element from the exploration queue and update the visited array from 0 to 1 for corresponding 
    // index (or value here) and repeat this for other elements untill the queue is empty
    
    // BFS Implementation

    int u;
    int i = 0;
    int visited[10] = {0,0,0,0,0,0,0,0,0,0};
    int graph [10][10] = {
        {0,1,1,0,0,0,0,0,0,0},
        {1,0,0,1,1,0,0,0,0,0},
        {1,0,0,0,1,0,0,0,0,0},
        {0,1,0,0,0,1,1,0,0,0},
        {0,1,1,0,0,0,0,1,0,0},
        {0,0,0,1,0,0,0,0,1,1},
        {0,0,0,1,0,0,0,0,0,1},
        {0,0,0,0,1,0,0,0,0,1},
        {0,0,0,0,0,1,0,0,0,1},
        {0,0,0,0,0,1,1,1,1,0}
    };    // Adjacency Matrix Representation of Graph

    printf("%d ",i);
    visited[i] = 1;
    enqueue(q, i);
    while (!isEmpty(q)){
        int node = dequeue(q);
        for (int j = 0; j < 10; j++){
            if (graph[node][j] == 1 && visited[j] == 0){
                printf("%d ",j);
                visited[j] = 1;
                enqueue(q, j);

          }
        }  
    }
    printf("\n");

    return 0;
}