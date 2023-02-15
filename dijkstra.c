#include <stdio.h>
int graph[5][5] =
{
    { 0, 10, 0, 5, 0 },
    { 0, 0, 1, 2, 0 },
    { 0, 0, 0, 0, 7 },
    { 0, 3, 9, 0, 2 },
    { 7, 0, 6, 0, 0 },
};
char c[] = {'s','t','x','y','z'};
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
    printf("Vertex \tDistance from source\n");
    for (int i = 0; i < 5; i++)
    printf("%c    %d\n",c[i], key[i]);
}

void MST(){
    for(int i=0; i<5; i++){
        key[i]=2147483647;
    }

    key[1] = 0;
    parent[1] = -1;

    for(int i=0; i<5; i++){
        int u = minValue();
        visited[u] = 1;
        for(int j=0; j<5; j++){
            if (graph[u][j] != 0 && visited[j] == 0 && key[u] != 2147483647 && key[u] + graph[u][j] < key[j]){
                parent[j] = u;
                key[j] = key[u] + graph[u][j];
            }
        }
    }
    printMST();
}
int main(){
    MST();
}
