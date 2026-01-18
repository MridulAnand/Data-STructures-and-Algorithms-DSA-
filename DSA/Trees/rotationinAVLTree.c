#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * left;
    struct Node * right;
    int height;
};

int max(int a, int b){
    return (a>b)?a:b; // using ternary operator
}

int getHeight(struct Node * root){
    if (root == NULL){
        return 0;
    }
    return root->height;    
}

struct Node * createNode(int key){
    struct Node * n = (struct Node *)malloc(sizeof(struct Node));
    n->data = key;
    n->left = NULL;
    n->right = NULL;
    n->height = 1; //because when node is created, its height is 1
    return n;
}

int getbalanceFactor(struct Node * root){
    if (root == NULL){
        return 0;
    }
    return getHeight(root->left) - getHeight(root->right);
}

struct Node * rightRotate(struct Node * y){
    struct Node * x = y->left;
    struct Node * T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->right), getHeight(y->left))+1;
    x->height = max(getHeight(x->right), getHeight(x->left))+1;

    return x;
}

struct Node * leftRotate(struct Node * x){
    struct Node * y = x->right;
    struct Node * T2 = y->left;

    y->left = x;
    x->right = T2;

    y->height = max(getHeight(y->right), getHeight(y->left))+1;
    x->height = max(getHeight(x->right), getHeight(x->left))+1;

    return y;
}

struct Node * insert(struct Node * root, int key){
    if (root == NULL){
        return createNode(key);
    }
    if (key > root->data){
        root->right = insert(root->right, key);
    }
    else if (key < root->data){
        root->left = insert(root->left, key);
    }
    // return root;
    
    root->height = 1+max(getHeight(root->left), getHeight(root->right));
    int bf = getbalanceFactor(root);

    // left left case
    if (bf>1 && key < root->left->data){
        return rightRotate(root);
    }
    // right right case
    if (bf<-1 && key > root->right->data){
        return leftRotate(root);
    }
    // left right case
    if (bf>1 && key > root->left->data){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // right left case
    if (bf<-1 && key < root->right->data){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;

}

void inorder(struct Node * root){
    if (root != NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(struct Node * root){
    if (root != NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}


int main(){
      struct Node * p = NULL;

      p = insert(p, 1);
      p = insert(p, 2);
      p = insert(p, 3);
      p = insert(p, 5);
      p = insert(p, 4);
      p = insert(p, 6);
      inorder(p);
      printf("\n");

      preorder(p);
      printf("\n");

      
    return 0;
}