#include <stdio.h>
#include <stdlib.h>
int dfs(int node, int** adj, int* adjSize, int* visited, int* recStack) {
    if (!visited[node]) {
        visited[node] = 1;
        recStack[node] = 1;
        for (int i = 0; i < adjSize[node]; i++) {
            int next = adj[node][i];
            if (!visited[next] && dfs(next, adj, adjSize, visited, recStack))
                return 1;
            else if (recStack[next])
                return 1;
        }
    }
    recStack[node] = 0;
    return 0;
}
int main() {
    int V, E;
    scanf("%d %d", &V, &E);
    int** adj = (int**)malloc(V * sizeof(int*));
    int* adjSize = (int*)calloc(V, sizeof(int));
    for (int i = 0; i < V; i++) adj[i] = (int*)malloc(V * sizeof(int));
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][adjSize[u]++] = v;
    }
    int* visited = (int*)calloc(V, sizeof(int));
    int* recStack = (int*)calloc(V, sizeof(int));
    for (int i = 0; i < V; i++) {
        if (dfs(i, adj, adjSize, visited, recStack)) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}