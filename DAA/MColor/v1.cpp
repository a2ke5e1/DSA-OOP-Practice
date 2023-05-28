#include <stdio.h>

int g[10][10], n, totalColors, vertex_color[10];


int isSafe() {
    // checks if vertex[i] and vertex[j] are adjacent and have same color
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (g[i][j] && vertex_color[i] == vertex_color[j]) {
                return 0;
            }
        }
    }
    return 1;
}


int graphColor(int nextVertex) {
    if ( nextVertex == n+1) {
        if (isSafe()) {
            // print the solution
            printf("\n"); 
            for (int i = 1; i <= n; i++) {
                printf("%d ", vertex_color[i]);
            }
            return 1;
        }
        return 0;
    }

    for (int i = 1; i <= totalColors; i++) {
        vertex_color[nextVertex] = i;
        if (graphColor(nextVertex + 1)) {
            return 1;
        }
        vertex_color[nextVertex] = 0;
    }

    return 0;
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of colors: ");
    scanf("%d", &totalColors);

    printf("Enter the adjacency matrix: \n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &g[i][j]);
        }
    }

    for (int i = 1; i <= totalColors; i++) {
        vertex_color[i] = 0;
    }

    if (!graphColor(1)) {
        printf("Solution does not exist.\n");
    }



    return 0; 
}
