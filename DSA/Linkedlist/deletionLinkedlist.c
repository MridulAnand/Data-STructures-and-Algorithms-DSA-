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

struct Node * deleteFirst(struct Node * head){
    struct Node * ptr = NULL;
    ptr = head;
    head = ptr->next;

    free(ptr);
    return head;
}

struct Node * deleteInbetween(struct Node * head, int index){
    struct Node * ptr = NULL, * temp = NULL;
    temp = head;
    ptr = head->next;
    int i = 0;
    while (i != index-1){   // here out of index error is not handled for simplicity
        temp = temp->next;
        ptr = ptr->next;
        i++;
    }
    temp->next = ptr->next;
    free(ptr);

    return head;
}

struct Node * deleteLast(struct Node * head){
    struct Node * ptr = NULL, * temp = NULL; // this logic fails for single node linked list (we can add condition to handle it)
    temp = head;
    ptr = head->next;
    while (ptr->next != NULL){
        temp = temp->next;
        ptr = ptr->next;
    }
    temp->next = NULL; // or temp->next = ptr->next; is also correct here
    free(ptr);

    return head;
}

struct Node * deleteByvalue(struct Node * head,int value){ 
    struct Node * ptr = NULL, * temp = NULL; // for deleting first occurence of given value
    temp = head;
    ptr = head->next;

    if (temp->data == value){
            head = ptr;
            free(temp);
            return head;
        }

    while (ptr != NULL){
        if (ptr->data == value){
            temp->next = ptr->next;
            free(ptr);
            break;
        }
        temp = temp->next;
        ptr = ptr->next;
    }

    return head;
}


int main(){
    struct Node * head,* second,* third,* fourth,* fifth;

    // Allocate memory in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));
    
    // Link first and second nodes
    head->data = 1;
    head->next = second;
    
    // similarly
    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;
  
    fourth->data = 4;
    fourth->next = fifth;

    fifth->data = 4;
    fifth->next = NULL;

    
    printf("Before deletion\n");
    linkedlistTraversal(head);
    
    head = deleteFirst(head);
    printf("\n");
    printf("After deletion\n"); 
    linkedlistTraversal(head);

    head = deleteInbetween(head,1);

    printf("\n");
    printf("After deletion\n");
    linkedlistTraversal(head);

    head = deleteLast(head);

    printf("\n");
    printf("After deletion\n");
    linkedlistTraversal(head);
  
    head = deleteByvalue(head,4);

    printf("\n");
    printf("After deletion\n");
    linkedlistTraversal(head);
    
    return 0;
}