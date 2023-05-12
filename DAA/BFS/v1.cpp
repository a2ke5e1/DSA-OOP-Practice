#include<stdio.h>

int a[20][20],reach[20],n;
int queue[20], front = 0, rear = -1;

void bfs(int v) {
    for (int i = 1; i <= n; i++) {
        if (a[v][i] && !reach[i]) {
            queue[++rear] = i;
        }
    }

    if (front <= rear) {
        reach[queue[front]] = 1;
        bfs(queue[++front]);
    }

}

int main() {
    int v;
    printf("\n Enter number of vertices:");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        reach[i] = 0;
        queue[i] = 0;
    
    }

    printf("\n Enter the adjacency matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    }

    printf("\n Enter the starting vertex:");
    scanf("%d", &v);
    bfs(v);

    printf("\n");
    for (int i = 1; i <= n; i++) {
        if (reach[i]) {
            printf("%d ", i);
        }
    }
}