#include <stdio.h>
#include <limits.h>

#define N 3  // Change this for different sizes

int calculate_cost(int cost_matrix[N][N], int assignment[N]) {
    int total_cost = 0;
    for (int worker = 0; worker < N; worker++) {
        total_cost += cost_matrix[worker][assignment[worker]];
    }
    return total_cost;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permute(int cost_matrix[N][N], int assignment[N], int l, int r, int *min_cost, int best_assignment[N]) {
    if (l == r) {
        int cost = calculate_cost(cost_matrix, assignment);
        if (cost < *min_cost) {
            *min_cost = cost;
            for (int i = 0; i < N; i++) {
                best_assignment[i] = assignment[i];
            }
        }
        return;
    }
    for (int i = l; i <= r; i++) {
        swap(&assignment[l], &assignment[i]);
        permute(cost_matrix, assignment, l + 1, r, min_cost, best_assignment);
        swap(&assignment[l], &assignment[i]); // backtrack
    }
}

void brute_force_assignment(int cost_matrix[N][N]) {
    int assignment[N];
    int best_assignment[N];
    int min_cost = INT_MAX;
    
    for (int i = 0; i < N; i++) {
        assignment[i] = i;
    }
    
    permute(cost_matrix, assignment, 0, N - 1, &min_cost, best_assignment);
    
    printf("Optimal Assignment: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", best_assignment[i]);
    }
    printf("\nMinimum Cost: %d\n", min_cost);
}

int main() {
    int cost_matrix[N][N];
    
    printf("Enter the cost matrix (%dx%d):\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &cost_matrix[i][j]);
        }
    }
    
    brute_force_assignment(cost_matrix);
    return 0;
}
