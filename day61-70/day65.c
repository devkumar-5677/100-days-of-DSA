#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int adj[MAX][MAX];   
int visited[MAX];
int V, E;
int dfs(int u, int parent) {
    visited[u] = 1;
    for (int v = 0; v < V; v++) {
        if (adj[u][v]) {
            if (!visited[v]) {
                if (dfs(v, u)) return 1;  
            } else if (v != parent) {
                return 1;  
            }
        }
    }
    return 0;
}
int main() {
    scanf("%d %d", &V, &E);   
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1;  
    }

    for (int i = 0; i < V; i++) visited[i] = 0;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                printf("YES\n");
                return 0;
            }
        }
    }
    printf("NO\n");
    return 0;
}