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
struct Node* recursionInsert(struct Node * root, int key){
    if (root == NULL){
        struct Node * ptr = NULL;
        ptr = createNode(key);
        root = ptr;
        return root;
    }
    else if (root->data < key){
        root->right = recursionInsert(root->right, key);
    }
    else if (root->data > key){
        root->left = recursionInsert(root->left, key);
    }
    return root;
    
}

void iterationInsert(struct Node * root, int key){
    struct Node * prev = NULL;
    struct Node * ptr = createNode(key);
    while(root != NULL){
        prev = root;
        if (key == root->data){
            printf("Can't insert duplicate values\n");
            return ;
        }
        else if(key > root->data){
            root = root->right;
        }
        else{
            root = root->left;
        }
    }
    if (key > prev->data){
        prev->right = ptr;;
    }
    else{
        prev->left = ptr;
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

      iterationInsert(p, 6);
      inOrder(p);
      printf("\n");

      recursionInsert(p, 0);
      inOrder(p);
      printf("\n");
 
    return 0;
}

        