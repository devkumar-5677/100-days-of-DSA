#include <stdio.h>
#include <stdlib.h>
#define MAXN 100005
int n, m;
int *adj[MAXN];
int deg[MAXN];
int visited[MAXN];

void dfs(int u) {
    visited[u] = 1;
    for (int i = 0; i < deg[u]; i++) {
        int v = adj[u][i];
        if (!visited[v]) dfs(v);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u] = realloc(adj[u], (deg[u] + 1) * sizeof(int));
        adj[v] = realloc(adj[v], (deg[v] + 1) * sizeof(int));
        adj[u][deg[u]++] = v;
        adj[v][deg[v]++] = u;
    }

    int components = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            components++;
        }
    }

    printf("%d\n", components);
    return 0;
}