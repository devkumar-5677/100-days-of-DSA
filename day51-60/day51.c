/*Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
6 2 8 0 4 7 9
2 8

Output:
6*/
#include <stdio.h>
#include <stdlib.h>

// Define structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct Node* insert(struct Node* root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Find LCA
struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL)
        return NULL;

    // If both values are smaller, go left
    if (n1 < root->data && n2 < root->data)
        return findLCA(root->left, n1, n2);

    // If both values are greater, go right
    if (n1 > root->data && n2 > root->data)
        return findLCA(root->right, n1, n2);

    // Otherwise, this is LCA
    return root;
}

int main() {
    int n, i, val, n1, n2;
    struct Node* root = NULL;

    // Input number of nodes
    scanf("%d", &n);

    // Insert nodes
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    // Input two nodes
    scanf("%d %d", &n1, &n2);

    struct Node* lca = findLCA(root, n1, n2);

    if (lca != NULL)
        printf("%d\n", lca->data);

    return 0;
}