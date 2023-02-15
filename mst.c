#include <stdio.h>
int graph[5][5] =
{
    { 0, 2, 0, 6, 0 },
    { 2, 0, 3, 8, 5 },
    { 0, 3, 0, 0, 7 },
    { 6, 8, 0, 0, 9 },
    { 0, 5, 7, 9, 0 }
};
int visited[5];
int parent[5];
int key[5];

int minValue(){
    int min = 2147483647, min_index = -1;
    for(int i=0; i<5; i++){
        if(visited[i]==0 && key[i]<min){
            min = key [i];
            min_index = i;
        }
    }
    return min_index;
}

void printMST(){
    printf("Edge \tWeight\n");
    for (int i = 1; i < 5; i++)
    printf("%d %d \t%d\n",parent[i], i, graph[i][parent[i]]);
}

void MST(){
    for(int i=0; i<5; i++){
        key[i]=2147483647;
    }

    key[0] = 0;
    parent[0] = -1;

    for(int i=0; i<4; i++){
        int u = minValue();
        visited[u] = 1;

        for(int j=0; j<5; j++){
            if (graph[u][j] != 0 && visited[j] == 0 && graph[u][j] < key[j]) {
                parent[j] = u;
                key[j] = graph[u][j];
            }
        }
    }
    printMST();
}
int main(){
    MST();
}
