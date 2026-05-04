#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
void addEdge(Node* adj[], int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
    newNode = createNode(u);   
    newNode->next = adj[v];
    adj[v] = newNode;
}
void printGraph(Node* adj[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        Node* temp = adj[i];
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Node* adj[n];
    for (int i = 0; i < n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    printGraph(adj, n);
    return 0;
}