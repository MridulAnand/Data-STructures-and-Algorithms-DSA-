#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// struct Stack{
//     int top;
//     int size;
//     char *arr;
// };

char arr[50];
int top = -1;

int push(char c){
    if (top == 49){
        // printf("Stack Overflow");
        return -1;
    }
    else{
        top++;
        arr[top] = c;
        return 0;
    }
}

char pop(){
    if (top == -1){
        return -1;
    }
    else{
        top--;
        return arr[top + 1];
    }
}

int precedence(char ch){
     if (ch == '*' || ch == '/'){
        return 3;
     }
     else if (ch == '+' || ch == '-'){
        return 2;
     }
     else{
        return 0;
     }

}

int isOperator(char ch){
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/'){
        return 1;
    }
    else{
        return 0;
    }
}

char * infixtoPostfix(char * infix){
    char *postfix = (char*)malloc((strlen(infix) + 1) * sizeof(char));

    int i = 0; //Track infix traversal
    int j = 0; //Track postfix addition
    while(infix[i] != '\0'){
        if (!isOperator(infix[i])){
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else{
            if (top == -1 || precedence(infix[i])>precedence(arr[top])){
                push(infix[i]);
                i++;
            }
            else{
                postfix[j] = pop();
                j++;
            }
        }
    }
    while(top != -1){
        postfix[j] = pop();
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}


int main(){
//   struct Stack * s = (struct stack *)malloc(sizeof(struct Stack));
//   s->top = -1;
//   s->size = 100;      
//   s->arr = (char*)malloc(sizeof(char)*s->size);

    char * infix = "(a+b)*c";
    printf("Postfix is %s", infixtoPostfix(infix));
      

return 0;
}