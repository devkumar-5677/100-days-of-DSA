/*Level Order Traversal

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications
*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct QueueNode {
    struct Node* treeNode;
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode *front, *rear;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue* q, struct Node* node) {
    struct QueueNode* temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->treeNode = node;
    temp->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

struct Node* dequeue(struct Queue* q) {
    if (q->front == NULL)
        return NULL;

    struct QueueNode* temp = q->front;
    struct Node* node = temp->treeNode;

    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return node;
}

void levelOrder(struct Node* root) {
    if (root == NULL)
        return;

    struct Queue* q = createQueue();
    enqueue(q, root);

    while (q->front != NULL) {
        struct Node* current = dequeue(q);
        printf("%d ", current->data);

        if (current->left != NULL)
            enqueue(q, current->left);

        if (current->right != NULL)
            enqueue(q, current->right);
    }
}

int main() {

    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);

    printf("Level Order Traversal: ");
    levelOrder(root);

    return 0;
}