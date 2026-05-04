#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAXN 100005
typedef struct {
    int v;
    int w;
    struct Node* next;
} Node;

Node* adj[MAXN];
int visited[MAXN];
int key[MAXN];

void addEdge(int u, int v, int w) {
    Node* node1 = (Node*)malloc(sizeof(Node));
    node1->v = v; node1->w = w; node1->next = adj[u];
    adj[u] = node1;

    Node* node2 = (Node*)malloc(sizeof(Node));
    node2->v = u; node2->w = w; node2->next = adj[v];
    adj[v] = node2;
}

int primMST(int n) {
    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    key[1] = 0; // start from node 1
    int totalWeight = 0;

    for (int count = 1; count <= n; count++) {
        // pick min key vertex not yet included
        int u = -1, minKey = INT_MAX;
        for (int v = 1; v <= n; v++) {
            if (!visited[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        visited[u] = 1;
        totalWeight += key[u];

        // update keys of adjacent vertices
        for (Node* p = adj[u]; p != NULL; p = p->next) {
            int v = p->v, w = p->w;
            if (!visited[v] && w < key[v]) {
                key[v] = w;
            }
        }
    }

    return totalWeight;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    int result = primMST(n);
    printf("%d\n", result);

    return 0;
}