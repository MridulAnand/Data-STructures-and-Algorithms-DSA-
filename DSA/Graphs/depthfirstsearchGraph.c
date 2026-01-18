#include<stdio.h>
#include<stdlib.h>


int visited[10] = {0,0,0,0,0,0,0,0,0,0};
int graph [10][10] = {
    {0,1,1,0,0,0,0,0,0,0},
    {1,0,0,1,1,0,0,0,0,0},
    {1,0,0,0,1,0,0,0,0,0},
    {0,1,0,0,0,1,1,0,0,0},
    {0,1,1,0,0,0,0,1,0,0},
    {0,0,0,1,0,0,0,0,1,1},
    {0,0,0,1,0,0,0,0,0,1},
    {0,0,0,0,1,0,0,0,0,1},
    {0,0,0,0,0,1,0,0,0,1},
    {0,0,0,0,0,1,1,1,1,0}
};    // Adjacency Matrix Representation of Graph

void DFS(int i){
    int j;
    printf("%d ",i);
    visited[i] = 1;
    for (int j = 0; j < 10; j++){
        if (graph[i][j] == 1 && visited[j] == 0){
            DFS(j);
        }
    }
    
}

int main(){
    
    // DFS Implementation
      
    DFS(0);
    printf("\n");
    return 0;
}