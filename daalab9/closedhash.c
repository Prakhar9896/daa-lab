#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EMPTY -1
#define MAX_KEYS 200
#define MAX_SEARCHES 1000

typedef struct {
    int* table;
    int size;
} HashTable;

// Hash function
int hash(int key, int m) {
    return key % m;
}

// Initialize hash table
HashTable* createHashTable(int m) {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    ht->size = m;
    ht->table = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        ht->table[i] = EMPTY;
    }
    return ht;
}

// Insert using linear probing
void insert(HashTable* ht, int key) {
    int index = hash(key, ht->size);
    int startIndex = index;
    while (ht->table[index] != EMPTY) {
        index = (index + 1) % ht->size;
        if (index == startIndex) {
            printf("Hash Table Full! Cannot insert key %d\n", key);
            return;
        }
    }
    ht->table[index] = key;
}

// Search and count comparisons
int search(HashTable* ht, int key, int* comparisons) {
    int index = hash(key, ht->size);
    int startIndex = index;
    while (ht->table[index] != EMPTY) {
        (*comparisons)++;
        if (ht->table[index] == key) {
            return 1;  // Found
        }
        index = (index + 1) % ht->size;
        if (index == startIndex) {
            break;  // Looped through table
        }
    }
    return 0;  // Not found
}

// Free table
void freeHashTable(HashTable* ht) {
    free(ht->table);
    free(ht);
}

void analyzeHashTable(int m, int n) {
    HashTable* ht = createHashTable(m);
    int keys[MAX_KEYS];
    int maxKeyValue = n * 10;

    // Generate random keys and insert
    for (int i = 0; i < n; i++) {
        keys[i] = rand() % maxKeyValue;
        insert(ht, keys[i]);
    }

    // Successful search comparisons
    int totalSuccessComparisons = 0;
    for (int i = 0; i < MAX_SEARCHES; i++) {
        int index = rand() % n;
        int key = keys[index];
        int comparisons = 0;
        search(ht, key, &comparisons);
        totalSuccessComparisons += comparisons;
    }

    // Unsuccessful search comparisons
    int totalFailureComparisons = 0;
    for (int i = 0; i < MAX_SEARCHES; i++) {
        int key = maxKeyValue + rand() % maxKeyValue;  // Ensure key is not in table
        int comparisons = 0;
        search(ht, key, &comparisons);
        totalFailureComparisons += comparisons;
    }

    double avgSuccess = (double)totalSuccessComparisons / MAX_SEARCHES;
    double avgFailure = (double)totalFailureComparisons / MAX_SEARCHES;
    double loadFactor = (double)n / m;

    printf("Hash Table Size (m) = %d, Keys Inserted (n) = %d, Load Factor = %.2f\n", m, n, loadFactor);
    printf("Average Comparisons - Success: %.2f, Failure: %.2f\n\n", avgSuccess, avgFailure);

    freeHashTable(ht);
}

int main() {
    srand(time(NULL));

    int mValues[] = {10, 20, 50};
    int nValues[] = {5, 10, 15};  // n must be <= m for linear probing to avoid full table

    for (int i = 0; i < sizeof(mValues)/sizeof(mValues[0]); i++) {
        for (int j = 0; j < sizeof(nValues)/sizeof(nValues[0]); j++) {
            if (nValues[j] <= mValues[i]) {  // Ensure table doesn't overflow
                analyzeHashTable(mValues[i], nValues[j]);
            }
        }
    }

    return 0;
}
