#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* lchild;
    struct Node* rchild;
};

typedef struct Node* Nodeptr;

Nodeptr getnode() {
    Nodeptr newNode = (Nodeptr)malloc(sizeof(struct Node));
    newNode->lchild = newNode->rchild = NULL;
    return newNode;
}

// Recursive function to create the binary tree
Nodeptr CreateBinaryTree(int item) {
    int x;
    if (item != -1) { // continue until input is -1
        Nodeptr temp = getnode();
        temp->data = item;
        printf("Enter the left child of %d (-1 for no child): ", item);
        scanf("%d", &x);
        temp->lchild = CreateBinaryTree(x);
        printf("Enter the right child of %d (-1 for no child): ", item);
        scanf("%d", &x);
        temp->rchild = CreateBinaryTree(x);
        return temp;
    }
    return NULL;
}

void postorder(Nodeptr root,int* c) {
    if (root != NULL) {
        (*c)++;
        postorder(root->lchild,c);
        postorder(root->rchild,c);
        printf("%d ", root->data);
    }
}

int main() {
    Nodeptr root = NULL;
    int item;
    int c=0;
    printf("Creating the tree:\n");
    printf("Enter the root value (-1 for no root): ");
    scanf("%d", &item);
    root = CreateBinaryTree(item);

    printf("Post-order traversal: ");
    postorder(root,&c);
    printf("\n");

    printf("number of nodes in the tree: %d ",c);
    return 0;
}
