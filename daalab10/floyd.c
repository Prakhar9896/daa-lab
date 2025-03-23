#include <stdio.h>

#define MAX 100
#define INF 99999  // Represents infinity

void floydWarshall(int n, int graph[MAX][MAX], int dist[MAX][MAX]) {
    // Initialize distance matrix same as graph
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = graph[i][j];

    // Floyd-Warshall Algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

void printMatrix(int n, int matrix[MAX][MAX]) {
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, graph[MAX][MAX], dist[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use %d to represent INF):\n", INF);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    floydWarshall(n, graph, dist);
    printMatrix(n, dist);

    return 0;
}
