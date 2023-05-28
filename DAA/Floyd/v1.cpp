#include <stdio.h>

int g[10][10], d[10][10], n;
void floyd() {
    for ( int i = 0; i < n; i++ )
        for ( int j = 0; j < n; j++ )
            d[i][j] = g[i][j];

    for ( int k = 0; k < n; k++ )
        for ( int i = 0; i < n; i++ )
            for ( int j = 0; j < n; j++ )
                if ( d[i][k] + d[k][j] < d[i][j] )
                    d[i][j] = d[i][k] + d[k][j];

    printf("The distance matrix is:\n");
    for ( int i = 0; i < n; i++ ) {
        for ( int j = 0; j < n; j++ )
            printf("%d ", d[i][j]);
        printf("\n");
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for ( int i = 0; i < n; i++ )
        for ( int j = 0; j < n; j++ )
            scanf("%d", &g[i][j]);
    floyd();
    return 0;
}