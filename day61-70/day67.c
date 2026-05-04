#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int adj[MAX][MAX], n;
int visited[MAX], stack[MAX], top=-1;
void dfs(int v){
    visited[v]=1;
    for(int i=0;i<n;i++){
        if(adj[v][i] && !visited[i]) dfs(i);
    }
    stack[++top]=v;
}
int main(){
    int e;
    scanf("%d %d",&n,&e);
    for(int i=0;i<e;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        adj[u][v]=1;
    }
    for(int i=0;i<n;i++) if(!visited[i]) dfs(i);
    while(top!=-1) printf("%d ",stack[top--]);
    return 0;
}