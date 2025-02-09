#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int arr[100];  
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = -1;
}

int isEmpty(Queue* q) {
    return (q->front == -1 || q->front > q->rear);
}

void enqueue(Queue* q, int x) {
    if (q->rear == 99) {
        printf("Queue overflow!\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->arr[++(q->rear)] = x;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        return -1; 
    }
    return q->arr[(q->front)++];
}

void bfs(int** adj_mat, int n, int start) {
    int* visited = (int*)calloc(n, sizeof(int));
    Queue q;
    initQueue(&q);

    printf("\nBFS Order: ");
    enqueue(&q, start);
    visited[start] = 1;

    while (!isEmpty(&q)) {
        int node = dequeue(&q);
        printf("%d ", node);

        for (int i = 0; i < n; i++) {
            if (adj_mat[node][i] == 1 && visited[i] == 0) {
                enqueue(&q, i);
                visited[i] = 1;
            }
        }
    }

    free(visited);
}

void display(int** adj_mat, int n) {
    printf("\nThe adjacency matrix is:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", adj_mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int u, v, n, m, start;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);

    int** adj_mat = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; ++i) {
        adj_mat[i] = (int*)calloc(n, sizeof(int)); 
    }

    printf("Enter the edges (u v):\n");
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &u, &v);
        adj_mat[u][v] = 1;
        adj_mat[v][u] = 1;
    }

    display(adj_mat, n);

    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &start);

    bfs(adj_mat, n, start);
    printf("\n");

    for (int i = 0; i < n; ++i) {
        free(adj_mat[i]);
    }
    free(adj_mat);

    return 0;
}
