#include <stdio.h>
#include <stdlib.h>
void dfs(int v, int* visited, int** adj, int* adjSize) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < adjSize[v]; i++) {
        int u = adj[v][i];
        if (!visited[u]) {
            dfs(u, visited, adj, adjSize);
        }
    }
}
int main() {
    int n, s;
    scanf("%d", &n);
    int** adj = (int**)malloc(n * sizeof(int*));
    int* adjSize = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k); 
        adjSize[i] = k;
        adj[i] = (int*)malloc(k * sizeof(int));
        for (int j = 0; j < k; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    scanf("%d", &s); 
    int* visited = (int*)calloc(n, sizeof(int));
    dfs(s, visited, adj, adjSize);
    for (int i = 0; i < n; i++) {
        free(adj[i]);
    }
    free(adj);
    free(adjSize);
    free(visited);
    return 0;
}