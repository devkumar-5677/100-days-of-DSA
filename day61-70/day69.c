#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct {
    int v, w;
} Edge;

typedef struct {
    int dist, node;
} HeapNode;

HeapNode heap[MAX*MAX];
int heapSize = 0;

void push(int dist, int node) {
    int i = heapSize++;
    while (i && dist < heap[(i-1)/2].dist) {
        heap[i] = heap[(i-1)/2];
        i = (i-1)/2;
    }
    heap[i].dist = dist;
    heap[i].node = node;
}

HeapNode pop() {
    HeapNode root = heap[0];
    HeapNode last = heap[--heapSize];
    int i=0, child;
    while ((child=2*i+1) < heapSize) {
        if (child+1 < heapSize && heap[child+1].dist < heap[child].dist) child++;
        if (last.dist <= heap[child].dist) break;
        heap[i] = heap[child];
        i = child;
    }
    heap[i] = last;
    return root;
}

int main() {
    int n, m, src;
    scanf("%d %d %d", &n, &m, &src);

    Edge adj[MAX][MAX];
    int deg[MAX] = {0};

    for (int i=0; i<m; i++) {
        int u,v,w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][deg[u]].v = v;
        adj[u][deg[u]].w = w;
        deg[u]++;
    }

    int dist[MAX];
    for (int i=0; i<n; i++) dist[i] = INT_MAX;
    dist[src] = 0;
    push(0, src);

    while (heapSize) {
        HeapNode h = pop();
        int u = h.node;
        if (h.dist > dist[u]) continue;
        for (int i=0; i<deg[u]; i++) {
            int v = adj[u][i].v;
            int w = adj[u][i].w;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(dist[v], v);
            }
        }
    }

    for (int i=0; i<n; i++) {
        if (dist[i] == INT_MAX) printf("Node %d: INF\n", i);
        else printf("Node %d: %d\n", i, dist[i]);
    }

    return 0;
}