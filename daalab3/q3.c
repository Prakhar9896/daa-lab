#include <stdio.h>

int isSubsetSum(int arr[], int n, int sum) {

    if (sum == 0)
        return 1;
    if (n == 0 && sum != 0)
        return 0;

    if (arr[n - 1] > sum)
        return isSubsetSum(arr, n - 1, sum);

    return isSubsetSum(arr, n - 1, sum) || isSubsetSum(arr, n - 1, sum - arr[n - 1]);
}

int findPartition(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    if (sum % 2 != 0)
        return 0;

    return isSubsetSum(arr, n, sum / 2);
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    if (findPartition(arr, n))
        printf("The given set can be partitioned into two subsets of equal sum.\n");
    else
        printf("The given set cannot be partitioned into two subsets of equal sum.\n");
    
    return 0;
}
