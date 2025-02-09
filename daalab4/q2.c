#include <stdio.h>
#include <stdlib.h>

struct Node {
    int dest;
    struct Node* next;
};

int main() {
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    struct Node** adjList = (struct Node**)malloc(V * sizeof(struct Node*));
    for (int i = 0; i < V; i++) adjList[i] = NULL;

    printf("Enter edges (source destination):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        // Add edge from u to v
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->dest = v;
        newNode->next = adjList[u];
        adjList[u] = newNode;

        // Add edge from v to u for undirected graphs (remove this block for directed)
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->dest = u;
        newNode->next = adjList[v];
        adjList[v] = newNode;
    }

    // Print adjacency list
    printf("Adjacency List:\n");
    for (int i = 0; i < V; i++) {
        struct Node* current = adjList[i];
        printf("Vertex %d: ", i);
        while (current) {
            printf("-> %d ", current->dest);
            current = current->next;
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < V; i++) {
        struct Node* current = adjList[i];
        while (current) {
            struct Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(adjList);

    return 0;
}