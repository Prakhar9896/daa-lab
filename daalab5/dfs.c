#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int arr[100];
    int top;
} Stack;

void push(Stack* s, int x) {
    if (s->top == 99) {
        printf("Stack overflow!\n");
        return;
    }
    s->arr[++(s->top)] = x;
}

void dfs(int** adj_mat, int n, int x, int* visited, Stack* s1) {
    push(s1, x);
    visited[x] = 1;
    printf("%d ", x);  // Print DFS order while traversing

    for (int i = 0; i < n; ++i) {
        if (adj_mat[x][i] == 1 && visited[i] == 0) {
            dfs(adj_mat, n, i, visited, s1);
        }
    }
}

void display(int** adj_mat, int n) {
    printf("The adjacency matrix is:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", adj_mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int u, v, n, m, x;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);

    int* visited = (int*)calloc(n, sizeof(int));
    int** adj_mat = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; ++i) {
        adj_mat[i] = (int*)calloc(n, sizeof(int));  // Zero initialization
    }

    printf("Enter the edges (u v):\n");
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &u, &v);
        adj_mat[u][v] = 1;
        adj_mat[v][u] = 1;  // Assuming undirected graph
    }

    display(adj_mat, n);
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &x);

    Stack* s1 = (Stack*)malloc(sizeof(Stack));
    s1->top = -1;  // Initialize stack top

    printf("\nDFS Order: ");
    dfs(adj_mat, n, x, visited, s1);
    printf("\n");

    // Free dynamically allocated memory
    free(visited);
    for (int i = 0; i < n; ++i) {
        free(adj_mat[i]);
    }
    free(adj_mat);
    free(s1);

    return 0;
}
