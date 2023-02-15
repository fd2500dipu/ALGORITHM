#include <stdio.h>
#include <limits.h>
#define V 8

char c[8][10] = { "Farmgate", "Shahabagh", "Mogbazar", "Gulistan", "Pilkhana", "Sayedabad", "Motijhil"};

int minDistance(int dist[], int Set[]){
    int min = INT_MAX, min_index;

    for (int i = 0; i < V; i++)
        if (Set[i] == 0 && dist[i] <= min)
            min = dist[i], min_index = i;

    return min_index;
}

void printPath(int parent[], int i){
    if (parent[i]==-1)
        return;

    printPath(parent, parent[i]);

    printf("-> %s", c[i]);
}

int printSolution(int dist[], int n, int parent[]){
    int src = 0;

    for (int i = 1; i < V; i++)
    {
        printf("\n%s -> %s \t\t %d\t\t%s ", c[src], c[i], dist[i], c[src]);
        printPath(parent, i);
    }
}

void dijkstra(int graph[V][V], int src){
    int dist[V];
    int Set[V];
    int parent[V];

    for (int i=0; i<V; i++)
    {
        parent[0] = -1;
        dist[i] = INT_MAX;
        Set[i] = 0;
    }

    dist[src] = 0;

    for (int i=0; i<V-1; i++)
    {
        int u = minDistance(dist, Set);

        Set[u] = 1;


        for (int v = 0; v < V; v++)

            if (Set[v]==0 && graph[u][v] && dist[u] + graph[u][v] < dist[v])
            {
                parent[v]  = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }

    printSolution(dist, V, parent);
}

int main()
{

    int graph[V][V] = {
        { 0, 8, 5, 0, 0, 4, 0, 0 },
        { 8, 0, 4, 3, 0, 0, 0, 0 },
        { 5, 4, 0, 2, 3, 5, 0, 0 },
        { 0, 3, 2, 0, 2, 0, 0, 6 },
        { 0, 0, 3, 2, 0, 6, 3, 0 },
        { 4, 0, 5, 0, 6, 0, 5, 0 },
        { 0, 0, 0, 0, 3, 5, 0, 3 },
        { 0, 0, 0, 6, 0, 0, 3, 0 }
        };

    dijkstra(graph, 1);

    return 0;
}
