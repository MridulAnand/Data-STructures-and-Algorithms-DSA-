#include<stdio.h>

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

int check(char str[]){

    for(int i = 0; str[i] != '\0'; i++){

        if (str[i]  == '(' || str[i]  == '{' || str[i]  == '['){
            int check1 = push(str[i]);
            if (check1 == -1){
                return -1;
            }

        }
        if (str[i] == ')' || str[i] == '}' || str[i] == ']'  ){
            char check2 = pop();
            if (check2 == -1){
                // printf("Parenthesis is unbalanced\n");
                return -2;
            }
            if (check2 == '(' && str[i] != ')'){
                // printf("Parenthesis is unbalanced\n");
                return -2;
            }
            if (check2 == '{' && str[i] != '}'){
                // printf("Parenthesis is unbalanced\n");
                return -2;
            }
            if (check2 == '[' && str[i] != ']'){
                // printf("Parenthesis is unbalanced\n");
                return -2;
            }

        }
    }
    if (top == -1){
        // printf("Parenthesis is balanced\n");
        return 0;
    }
    else{
        // printf("Parenthesis is unbalanced");
        return -2;
    }

}


int main(){
//   struct Stack * s = (struct stack *)malloc(sizeof(struct Stack));
//   s->top = -1;
//   s->size = 100;      
//   s->arr = (char*)malloc(sizeof(char)*s->size);

    char str[50] = "[{((1+2)*(3+(4-5))+(6/2))}]";

    int result = check(str);
    if (result == -1){
        printf("Stack Overflow\n");
    }
    else if (result == -2){
        printf("Parenthesis is unbalanced\n");
    }
    else if (result == 0){
        printf("Parenthesis is balanced\n");
    }


return 0;
}