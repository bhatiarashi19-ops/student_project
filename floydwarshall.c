#include <stdio.h>
#define INF 99999
#define V 4   


void printSolution(int dist[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%4s", "INF");
            else
                printf("%4d", dist[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void floydWarshall(int graph[V][V]) {
    int dist[V][V], i, j, k;

   
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }

        
        printf("Intermediate matrix after including vertex %d:\n", k);
        printSolution(dist);
    }
}

int main() {
    printf("Rashi bhatia / S11 / 12 \n\n");
    int graph[V][V] = {
        {0, 3, INF, 7},
        {8, 0, 2, INF},
        {5, INF, 0, 1},
        {2, INF, INF, 0}
    };

    floydWarshall(graph);
    return 0;
}
