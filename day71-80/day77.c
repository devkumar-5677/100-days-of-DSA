#include <stdio.h>
#include <stdlib.h>
int **adj;       
int *adjSize;   
int *adjCap;    
int *visited;
void addEdge(int u, int v) {
    if (adjSize[u] == adjCap[u]) {
        adjCap[u] = adjCap[u] ? adjCap[u] * 2 : 2;
        adj[u] = realloc(adj[u], adjCap[u] * sizeof(int));
    }
    adj[u][adjSize[u]++] = v;
}

void dfs(int u) {
    visited[u] = 1;
    for (int i = 0; i < adjSize[u]; i++) {
        int v = adj[u][i];
        if (!visited[v]) dfs(v);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    adj = (int**)malloc(n * sizeof(int*));
    adjSize = (int*)calloc(n, sizeof(int));
    adjCap  = (int*)calloc(n, sizeof(int));
    visited = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) adj[i] = NULL;
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--; 
        addEdge(u, v);
        addEdge(v, u);
    }

    dfs(0);

    int connected = 1;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            connected = 0;
            break;
        }
    }
    if (connected) printf("CONNECTED\n");
    else printf("NOT CONNECTED\n");
    for (int i = 0; i < n; i++) free(adj[i]);
    free(adj); free(adjSize); free(adjCap); free(visited);

    return 0;
}