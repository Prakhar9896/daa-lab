#include <stdio.h>

#define N 4  // Change this based on the problem size
#define INF 999999  // A large value to represent infinity

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to calculate cost for a given assignment
int calculateCost(int costMatrix[N][N], int perm[N]) {
    int totalCost = 0;
    for (int i = 0; i < N; i++) {
        totalCost += costMatrix[i][perm[i]];
    }
    return totalCost;
}

// Function to generate all permutations and find the minimum cost
void findMinCost(int costMatrix[N][N], int perm[N], int l, int r, int *minCost, int bestAssignment[N]) {
    if (l == r) {  
        int cost = calculateCost(costMatrix, perm);
        if (cost < *minCost) {  
            *minCost = cost;
            for (int i = 0; i < N; i++) {
                bestAssignment[i] = perm[i];  
            }
        }
        return;
    }

    for (int i = l; i <= r; i++) {
        swap(&perm[l], &perm[i]);
        findMinCost(costMatrix, perm, l + 1, r, minCost, bestAssignment);
        swap(&perm[l], &perm[i]);  // Backtrack
    }
}

// Driver function
int main() {
    int costMatrix[N][N] = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };

    int perm[N];  // Array to store task assignments
    for (int i = 0; i < N; i++) {
        perm[i] = i;  
    }

    int minCost = INF;  // Replace INT_MAX with a large value
    int bestAssignment[N];  

    // Generate all permutations and find the optimal assignment
    findMinCost(costMatrix, perm, 0, N - 1, &minCost, bestAssignment);

    // Print results
    printf("Optimal Assignment: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", bestAssignment[i]);
    }
    printf("\nMinimum Cost: %d\n", minCost);

    return 0;
}
