#include<stdio.h>
#include<stdlib.h>


struct myArray{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct myArray * a, int TSize, int USize){   // here a is pointer the structure example marks (here a is pointer to marks)
    (*a).total_size = TSize; // a -> total_size setting total size (we can also access this way)
    (*a).used_size = USize;
    (*a).ptr = (int *) malloc(TSize * sizeof(int));
            // or we can also use arrow operator (both the methods are same)
    // a->total_size = TSize;
    // a->used_size = USize;
    // a->ptr = (int *) malloc(TSize * sizeof(int));

}

void show(struct myArray * a){
    for(int i = 0; i < a->used_size; i++){
        printf("%d\n", (a->ptr)[i]);
    }
}

void setVal(struct myArray * a){
    for(int i = 0; i < a->used_size; i++){
        int n;
        printf("Enter element %d:",i);
        scanf("%d",&n);
        (a->ptr)[i] = n;
    }
}

int main(){
    struct myArray marks;
    createArray(&marks, 10, 2); // here address of marks is paased along with other parameters
    printf("We are running setVal now\n");
    setVal(&marks);
    printf("We are running show now\n");
    show(&marks);
    return 0;
}