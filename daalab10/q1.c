#include <stdio.h>

#define MAX 10  // maximum number of vertices

void warshall(int n, int adj[MAX][MAX]) {
    int i, j, k;

    // Applying Warshall's Algorithm
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                adj[i][j] = adj[i][j] || (adj[i][k] && adj[k][j]);
            }
        }
    }
}

void printMatrix(int n, int matrix[MAX][MAX]) {
    int i, j;
    printf("\nTransitive Closure (Reachability Matrix):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, i, j;
    int adj[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use 1 for edge, 0 for no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    warshall(n, adj);
    printMatrix(n, adj);

    return 0;
}
