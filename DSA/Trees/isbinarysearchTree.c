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

void preOrder(struct Node * root){
      if (root != NULL){
            printf("%d ",root->data);
            preOrder(root->left);
            preOrder(root->right);
      }
}

void postOrder(struct Node * root){
      if (root != NULL){
            postOrder(root->left);
            postOrder(root->right);
            printf("%d ",root->data);
      }
}

void inOrder(struct Node * root){
      if (root != NULL){
            inOrder(root->left);
            printf("%d ",root->data);
            inOrder(root->right);
      }
}

int isbsTree(struct Node * root){
    static struct Node * prev = NULL; // To keep track of previous node in inOrder traversal (and kept it static because we want to retain its value accross recursive calls)
      if (root != NULL){
            if (!isbsTree(root->left)){
                return 0;
            }
            if (prev != NULL && root->data <= prev->data){
                return 0;
            }
            prev = root;
            return isbsTree(root->right);
      }
      else{
        return 1;
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
      printf("%d",isbsTree(p)); // if 1 then it is BST else if 0 then not BST
      printf("\n");
      
    return 0;
}

        