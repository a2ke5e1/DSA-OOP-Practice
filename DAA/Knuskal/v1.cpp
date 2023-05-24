#include <stdio.h>
#define V 10

int G[V][V], n, edges[V][3]; 

int main() {
    printf("Enter no. of vertices:");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &G[i][j]);
            
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (G[i][j] != 0) {
                edges[i][0] = i;
                edges[i][1] = j;
                edges[i][2] = G[i][j];
            }
        }
    }




    return 0; 
}