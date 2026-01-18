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


void inOrder(struct Node * root){
      if (root != NULL){
            inOrder(root->left);
            printf("%d ",root->data);
            inOrder(root->right);
      }
}


struct Node * search(struct Node * root, int key){
      if (root == NULL){
        return NULL;
      }
      if (root->data == key){
        return root;
      }
      else if (root->data < key){
        return search(root->right, key);
      }
      else{
        return search(root->left, key);
      }
}


int main(){

      struct Node * p = createNode(4);
      struct Node * p2 = createNode(2);
      struct Node * p3 = createNode(5);
      struct Node * p4 = createNode(1);
      struct Node * p5 = createNode(3);

      p->left = p2;
      p->right = p3;

      p2->left = p4;
      p2->right = p5;

    //   preOrder(p);
    //   printf("\n");
    //   postOrder(p);
    //   printf("\n");
      inOrder(p);
      printf("\n");

      struct Node * n = search(p, 5);
      if (n != NULL){
      printf("%d",search(p, 5)->data);
      }
      else{
        printf("Element not found");
      }
      printf("\n");
      
    return 0;
}

        