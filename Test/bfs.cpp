#include <stdio.h>

int g[20][20], reach[20],  n; 
int q[20], front = 0 , rear = -1; 

void bfs(int v) {
    for (int i = 0; i < n; i++) {
        if ( g[v][i] && !reach[i]) {
            q[++rear] = i; 
        }
    }

    if ( front <= rear) {
        reach[q[front]] = 1; 
        bfs(q[++front]); 
    }
}

int main() {
    scanf("%d", &n); 
    for (int i = 0; i < n;i++) {
        reach[i] = 0; 
        for (int j = 0; j < n; j++)
            scanf("%d", &g[i][j]); 
    }
    bfs(0); 

    for(int i = 0; i < n; i++) {
          if (reach[i]) {
            printf("%d ", i);
        }
    }
    return 0; 
}