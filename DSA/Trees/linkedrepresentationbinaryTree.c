#include<stdio.h>
#include<stdlib.h>

struct Node{
   int data;
   struct Node * left;
   struct Node * right;
};

struct Node * createNode(int data){
      struct Node * n;   // creating the node pointer
      n = (struct Node *)malloc(sizeof(struct Node)); // allocating memory in the heap
      n->data = data; // setting the data
      n->left = NULL; // setting left children to null
      n->right = NULL; // setting right children to null
      return n; // finally returning the created node
}

int main(){
      struct Node * p;
      struct Node * p1;
      struct Node * p2;
      
      p = (struct Node *)malloc(sizeof(struct Node));   // root and first node
      p->data = 2;
      p->left = NULL;
      p->right = NULL;

      p1 = (struct Node *)malloc(sizeof(struct Node));  // second node
      p1->data = 3;
      p1->left = NULL;
      p1->right = NULL;

      p2 = (struct Node *)malloc(sizeof(struct Node));  // third node
      p2->data = 2;
      p2->left = NULL;
      p2->right = NULL;

      // linking the nodes

      p->left = p1;
      p->right = p2;

      // now creating node using function

      struct Node * p3 = createNode(1);
      struct Node * p4 = createNode(5);
      struct Node * p5 = createNode(6);

      // linking the nodes

      p3->left = p4;
      p3->right = p5;    
    return 0;
}