#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a[100];
    int f, r;
} queue;

queue* init() {
    queue* q = (queue*)malloc(sizeof(queue));
    q->f = 0;
    q->r = -1;
    return q;
}

void enqueue(queue* q, int x) {
    q->a[++(q->r)] = x;
}

int dequeue(queue* q) {
    return q->a[(q->f)++];
}

int isEmpty(queue* q) {
    return q->f > q->r;
}

void topoKahn(int** adj_mat, int v, int* indegree) {
    queue* q = init();
    int* topo_order = (int*)malloc(v * sizeof(int));
    int index = 0;

    // Enqueue all vertices with in-degree 0
    for (int i = 0; i < v; i++) {
        if (indegree[i] == 0) {
            enqueue(q, i);
        }
    }

    while (!isEmpty(q)) {
        int node = dequeue(q);
        topo_order[index++] = node;

        // Reduce the in-degree of all neighbors
        for (int i = 0; i < v; i++) {
            if (adj_mat[node][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    enqueue(q, i);
                }
            }
        }
    }

    // Check for cycle (if all nodes are not processed)
    if (index != v) {
        printf("Graph has a cycle, topological sorting not possible.\n");
    } else {
        printf("\nTopological Order: ");
        for (int i = 0; i < index; i++) {
            printf("%d ", topo_order[i]);
        }
        printf("\n");
    }

    free(q);
    free(topo_order);
}

int main() {
    int v, e;
    printf("Enter the number of vertices: ");
    scanf("%d", &v);
    printf("Enter the number of edges: ");
    scanf("%d", &e);

    int** adj_mat = (int**)malloc(v * sizeof(int*));
    for (int i = 0; i < v; i++) {
        adj_mat[i] = (int*)calloc(v, sizeof(int));
    }

    int n, m;
    printf("Enter the edges (from to):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &n, &m);
        adj_mat[n][m] = 1;
    }

    // Compute in-degree of each vertex
    int* indegree = (int*)calloc(v, sizeof(int));
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            indegree[i] += adj_mat[j][i];
        }
    }

    // Perform Kahn's Algorithm for Topological Sorting
    topoKahn(adj_mat, v, indegree);

    // Free allocated memory
    for (int i = 0; i < v; i++) {
        free(adj_mat[i]);
    }
    free(adj_mat);
    free(indegree);

    return 0;
}
