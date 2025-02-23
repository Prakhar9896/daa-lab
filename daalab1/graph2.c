#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* next;
} Node;

typedef struct graph {
    int num_vertices;
    Node** list;
} Graph;

Node* create_node(int v) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->value = v;
    n->next = NULL;
    return n;
}

void insert(Node** head, int v) {
    Node* n = create_node(v);
    if (*head == NULL) {
        *head = n;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
}

void add_edge(Graph* g, int sv, int ev) {
    insert(&g->list[sv],ev);
    insert(&g->list[ev],sv);
}

void display(Graph* g) {
    for (int i = 0; i < g->num_vertices; i++) {
        printf("%d :", i);
        Node* temp = g->list[i];
        while (temp != NULL) {
            printf(" %d ->", temp->value);
            temp = temp->next;
        }
        printf(" NULL\n");
    }
}

int main() {
    int v, e;
    printf("Enter the number of vertices in graph: ");
    scanf("%d", &v);
    printf("Enter the number of edges in graph: ");
    scanf("%d", &e);

    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->num_vertices = v;
    g->list = (Node**)malloc(v * sizeof(Node*));

    // Initialize adjacency list
    for (int i = 0; i < v; i++) {
        g->list[i] = NULL;
    }

    printf("Enter the edges (start end): \n");
    for (int i = 0; i < e; i++) {
        int m, n;
        scanf("%d %d", &m, &n);
        add_edge(g, m, n);
    }

    printf("Adjacency List Representation:\n");
    display(g);

    return 0;
}
