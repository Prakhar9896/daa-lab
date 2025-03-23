#include <stdio.h>

// Function to perform bottom-up max heapify
void bottomUpHeapify(int arr[], int index) {
    int parent = (index - 1) / 2;
    int temp = arr[index];

    while (index > 0 && arr[parent] < temp) {
        arr[index] = arr[parent];
        index = parent;
        parent = (index - 1) / 2;
    }
    arr[index] = temp;
}

// Function to build max heap using bottom-up method
void buildMaxHeap(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        bottomUpHeapify(arr, i);
    }
}

// Function to perform heapify down after swapping root with last element
void heapifyDown(int arr[], int n, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != index) {
        int temp = arr[index];
        arr[index] = arr[largest];
        arr[largest] = temp;
        heapifyDown(arr, n, largest);
    }
}

// Heap Sort function
void heapSort(int arr[], int n) {
    // Step 1: Build Max Heap
    buildMaxHeap(arr, n);

    // Step 2: Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Swap root (maximum) with last element
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Heapify root element to maintain max heap
        heapifyDown(arr, i, 0);
    }
}

// Utility function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function
int main() {
    int arr[] = {20, 5, 15, 22, 10, 3, 8, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}
