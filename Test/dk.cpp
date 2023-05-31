#include<stdio.h>
int g[20][20], dist[20], n; 

void dk(int source) {
    for (int i = 1; i <= n; i++) 
        dist[i] = g[source][i]; 
    dist[source] = 0; 

    for (int i = 1; i <= n; i++) {
        if ( i == source) continue; 
        for (int j = 1; j <=n ; j++) {
            if ( j == source) continue; 
            if ( g[i][j] >= 999) continue; 
            if ( g[j][i] + dist[j] < dist[i]) {
                dist[i] = g[j][i] + dist[j]; 
            }
        }
    } 

    for ( int i = 1; i <= n; i++) {
        if ( i == source) continue; 
        printf("%d -> %d = %d\n", source, i, dist[i]); 
    }
}

int main() {
    scanf("%d", &n); 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &g[i][j]); 
        }
    }

    dk(5); 
    return 0; 
}