#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleS(int a[], int n, int* op) {
    for (int i = 0; i < n; i++) {
        int flag = 1;  // Assume the array is sorted
        for (int j = 0; j < n - i - 1; j++) {
            (*op)++;  // Count comparison
            if (a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1]); 
                flag = 0; // Array is not sorted
            }
        }
        if (flag == 1) {
            break;  // Early exit if no swaps occurred
        }
    }
}

int main() {
    int a[] = {7, 6, 1, 9, 3,4,5,6,10,12};
    int n = sizeof(a) / sizeof(a[0]);
    int opc = 0;
    bubbleS(a, n, &opc);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\nOperation Counter: %d", opc);
    return 0;
}
