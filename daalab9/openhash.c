#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_KEYS 200
#define MAX_SEARCHES 1000

typedef struct Node {
    int key;
    struct Node* next;
} Node;

typedef struct HashTable {
    int size;
    Node** table;
} HashTable;

// Hash function
int hash(int key, int m) {
    return key % m;
}

// Initialize hash table
HashTable* createHashTable(int m) {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    ht->size = m;
    ht->table = (Node**)malloc(m * sizeof(Node*));
    for (int i = 0; i < m; i++) {
        ht->table[i] = NULL;
    }
    return ht;
}

// Insert into hash table (chaining)
void insert(HashTable* ht, int key) {
    int index = hash(key, ht->size);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = ht->table[index];
    ht->table[index] = newNode;
}

// Search with comparison count (1 for success, 0 for failure)
int search(HashTable* ht, int key, int* comparisons) {
    int index = hash(key, ht->size);
    Node* current = ht->table[index];
    while (current != NULL) {
        (*comparisons)++;
        if (current->key == key) {
            return 1;  // Found
        }
        current = current->next;
    }
    return 0;  // Not found
}

// Free hash table
void freeHashTable(HashTable* ht) {
    for (int i = 0; i < ht->size; i++) {
        Node* current = ht->table[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(ht->table);
    free(ht);
}

void analyzeHashTable(int m, int n) {
    HashTable* ht = createHashTable(m);
    int keys[MAX_KEYS];
    int maxKeyValue = n * 10;  // To ensure fewer collisions for random keys

    // Generate and insert keys
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
        int key = maxKeyValue + rand() % maxKeyValue;  // Ensure not in inserted keys
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
    int nValues[] = {50, 100, 200};

    for (int i = 0; i < sizeof(mValues)/sizeof(mValues[0]); i++) {
        for (int j = 0; j < sizeof(nValues)/sizeof(nValues[0]); j++) {
            analyzeHashTable(mValues[i], nValues[j]);
        }
    }

    return 0;
}
