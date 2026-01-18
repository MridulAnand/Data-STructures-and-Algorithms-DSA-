#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void linkedlistTraversal(struct Node * ptr){
    struct Node * temp = ptr;
    while(ptr->next != temp){
        printf("Element: %d\n",ptr->data);
        ptr = ptr->next;
    }
    printf("Element: %d\n",ptr->data);
}

struct Node * insertatFirst(struct Node * ptr ,int data){
    struct Node * p = (struct Node *) malloc (sizeof(struct Node)), *temp = NULL;
    temp = ptr;
    while(temp->next != ptr){
        temp = temp->next;
    }
    p->data = data;
    p->next = ptr;
    temp->next = p;

    ptr = p;

    return ptr;
}

int main(){
    struct Node * head,* second,* third,* fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    
    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;
  
    fourth->data = 4;
    fourth->next = head; // pointing the first Node to make it circular
    
    linkedlistTraversal(head);

    printf("\n");
    printf("Above is before insertion and below is after insertion\n");
    printf("\n");

    head = insertatFirst(head, 5);
    linkedlistTraversal(head);
    return 0;
}