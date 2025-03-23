#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int arr[100];
    int size;
} heap;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to "bubble up" the newly inserted element
void bubbleUp(heap* h, int i) {
    int parent = (i - 1) / 2; // Parent index

    // If the current node is greater than its parent, swap them
    if (i > 0 && h->arr[i] > h->arr[parent]) {
        swap(&h->arr[i], &h->arr[parent]);
        bubbleUp(h, parent); // Recursively check the parent
    }
}

// Insert function using top-down approach
void insert(heap* h, int x) {
    if (h->size >= 100) {
        printf("Heap is full!\n");
        return;
    }

    // Insert the new element at the end
    h->arr[h->size] = x;
    h->size++;

    // Bubble up the new element to maintain the heap property
    bubbleUp(h, h->size - 1);
}

int main() {
    int n, x;
    heap* h = (heap*)malloc(sizeof(heap));
    h->size = 0;

    printf("Enter the number of elements in array: ");
    scanf("%d", &n);

    if (n > 100) {
        printf("Number of elements cannot exceed 100.\n");
        free(h);
        return 1;
    }

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insert(h, x);
    }

    printf("Heap created: ");
    for (int i = 0; i < h->size; i++) {
        printf("%d ", h->arr[i]);
    }
    printf("\n");

    free(h);
    return 0;
}