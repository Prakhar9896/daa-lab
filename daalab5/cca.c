#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Utility function to create a new tree node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to find the closest common ancestor
struct Node* findCCA(struct Node* root, int n1, int n2) {
    if (root == NULL)
        return NULL;

    // If either n1 or n2 matches with root's key, return root
    if (root->data == n1 || root->data == n2)
        return root;

    // Look for keys in left and right subtrees
    struct Node* left_cca = findCCA(root->left, n1, n2);
    struct Node* right_cca = findCCA(root->right, n1, n2);

    // If both left and right calls return non-NULL, root is the CCA
    if (left_cca && right_cca)
        return root;

    // Otherwise, return the non-NULL subtree result
    return (left_cca != NULL) ? left_cca : right_cca;
}

int main() {
    // Constructing the tree
    struct Node* root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);

    int n1 = 10, n2 = 14;
    struct Node* cca = findCCA(root, n1, n2);
    if (cca != NULL)
        printf("Closest Common Ancestor of %d and %d is %d\n", n1, n2, cca->data);
    else
        printf("No common ancestor found.\n");

    return 0;
}