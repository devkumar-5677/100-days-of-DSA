#include <stdio.h>
#include <stdlib.h>
#define MAX 100
void bfs(int n, int adj[][MAX], int s) {
    int visited[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;

    visited[s] = 1;
    queue[rear++] = s;

    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);
        for (int v = 0; v < n; v++) {
            if (adj[u][v] && !visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }
}
int main() {
    int n, s;
    scanf("%d", &n);
    int adj[MAX][MAX];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
    scanf("%d", &s);
    bfs(n, adj, s);
    return 0;
}