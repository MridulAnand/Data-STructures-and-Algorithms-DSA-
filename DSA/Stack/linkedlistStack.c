#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

struct Node * push(struct Node * head, int value){
    struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL){
        printf("Stack Overflow\n");
        return head;
    }
    temp->data = value;
    temp->next = head;
    head = temp;
    return head;
}

struct Node * pop(struct Node * head){
    struct Node * temp = NULL;
    if (head == NULL){
        printf("Stack Underflow\n");
        return head;
    }
    printf("Popped value is %d\n",head->data);
    temp = head;
    head = temp->next;
    free(temp);

    return head;
}

void traverseStack(struct Node * head){
    while(head != NULL){
        printf("%d\n",head->data);
        head = head->next;
    }
}

void peek(struct Node * head){
    if (head != NULL)
     printf("Peek value is %d\n",head->data);    
    else
     printf("Empty Stack\n"); 
}

void isEmpty(struct Node * head){
    if (head == NULL){
        printf("Stack is Empty\n");
    }
    else{
         printf("Stack is not Empty\n");
    }
}


int main(){
    struct Node * head = NULL;
    head = push(head,1);
    head = push(head,2);
    traverseStack(head);

    peek(head);
    head = pop(head);
    head = pop(head);
    head = pop(head);
    traverseStack(head);

    peek(head);
    isEmpty(head);
    return 0;
}