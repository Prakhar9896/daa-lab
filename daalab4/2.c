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

int pop(Stack* s) {
    if (s->top == -1) {
        return -1;
    }
    return s->arr[(s->top)--];
}

void dfs(int** adj_mat, int n, int start) {
    int* visited = (int*)calloc(n, sizeof(int));
    Stack s;
    s.top = -1;

    printf("\nPush Order: ");
    push(&s, start);
    visited[start] = 1;
    printf("%d ", start);

    while (s.top != -1) {
        int node = s.arr[s.top];
        int found = 0;

        for (int i = 0; i < n; i++) {
            if (adj_mat[node][i] == 1 && visited[i] == 0) {
                push(&s, i);
                visited[i] = 1;
                printf("%d ", i);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("\nPop: %d", pop(&s));
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

    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &start);

    dfs(adj_mat, n, start);
    printf("\n");

    for (int i = 0; i < n; ++i) {
        free(adj_mat[i]);
    }
    free(adj_mat);

    return 0;
}
