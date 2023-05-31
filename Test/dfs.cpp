#include<stdio.h>

int g[10][10], visited[10], n; 

void dfs(int v) {
    visited[v] = 1; 
    for ( int i = 0;  i < n; i++) {
        if (!visited[i] && g[v][i]) {
            printf("%d -> %d \n", v, i); 
            dfs(i); 
        }
    }
}

int main() {
    scanf("%d", &n); 
    for (int i = 0; i < n;i++) {
        visited[i]=0;
        for (int j = 0; j < n; j++)
            scanf("%d", &g[i][j]); 
    }
    dfs(0); 
}   