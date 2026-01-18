#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void linkedlistTraversal(struct Node * ptr){
    struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
    temp = ptr;

    while(temp != NULL){
        printf("Element: %d\n",temp->data);
        temp = temp->next;
    }
}

int main(){
    struct Node * head,* second,* third,* fourth;

    // Allocate memory in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    
    // Link first and second nodes
    head->data = 1;
    head->next = second;
    
    // similarly
    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;
  
    fourth->data = 4;
    fourth->next = NULL;
    
    linkedlistTraversal(head);
    return 0;
}