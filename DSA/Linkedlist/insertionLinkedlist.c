#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void linkedlistTraversal(struct Node * ptr){
    while(ptr != NULL){
        printf("Element: %d\n",ptr->data);
        ptr = ptr->next;
    }
}

void insertatFirst(struct Node ** ptr ,int data){
    struct Node * temp = (struct Node *) malloc (sizeof(struct Node));

    temp->data = data;
    temp->next = *ptr;
    *ptr = temp;
}

struct Node * insertinBetween(struct Node * ptr ,int data, int index){
    struct Node * temp, * p;
    temp = NULL;
    p = (struct Node *) malloc (sizeof(struct Node));
    
    temp = ptr;
    int i = 0;

    while(i != index-1 && temp != NULL){
        temp = temp->next;
        i++;
    }
    if (temp != NULL){
    p->data = data;
    p->next = temp->next;
    temp->next = p;
    }

    return ptr;
}

struct Node * insertatLast(struct Node * ptr ,int data){
    struct Node * p = (struct Node *) malloc (sizeof(struct Node)), *temp = NULL;
    temp = ptr;
    while(temp->next != NULL){
        temp = temp->next;
    }
    p->data = data;
    p->next = NULL;
    temp->next = p;

    return ptr;
}

struct Node * insertafterNode(struct Node * ptr, struct Node * prevNode ,int data){
    struct Node * temp = (struct Node *) malloc (sizeof(struct Node));
    
    temp->data = data;
    temp->next = prevNode->next;
    prevNode->next = temp;

    return ptr;
}


int main(){
    struct Node * head;
    head = NULL;
    insertatFirst(&head,1);
    head = insertinBetween(head,2,1);
    head = insertatLast(head,4);
    head = insertafterNode(head,head->next,3); // Here let the second Node as a given previous Node
    linkedlistTraversal(head);
    return 0;
}