#include <stdio.h>
#define MAX 1000

int n, cost[MAX][MAX], source; 

void dijkstra(int cost[MAX][MAX], int source) {
    int distances[MAX]; 
    for (int i = 1; i <= n; i++) {
        distances[i] = cost[source][i];
    }
    distances[source] = 0;
    for (int i = 1; i <= n; i++) {
        if (i == source) continue;
        for (int j = 1; j <= n; j++) {
            if (j == source) continue;
            if ( cost[j][i] >= 1000 ) continue; // no edge from j to i

            if (distances[i] > distances[j] + cost[j][i]) {
                distances[i] = distances[j] + cost[j][i];
            }
        }   
    }


    printf("Shortest distances from source %d:\n", source);
    for (int i = 1; i <= n; i++) {
        if (i == source) continue;
        printf("%d -> %d: %d\n", source, i, distances[i]);
    }

}


int main()
{
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the cost matrix:\n");
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }
    printf("Source: "); 
    scanf("%d", &source); 
    dijkstra(cost, source);
    return 0;
}
