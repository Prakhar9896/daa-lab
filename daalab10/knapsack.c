#include <stdio.h>

// Function to find maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int weights[], int values[], int n, int capacity) {
    int dp[n + 1][capacity + 1];

    // Build dp table in bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];  // Return the result
}

int main() {
    int n;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int weights[n], values[n];

    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    printf("Enter values of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }

    int capacity;
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    int result = knapsack(weights, values, n, capacity);
    printf("Maximum value in knapsack: %d\n", result);

    return 0;
}
