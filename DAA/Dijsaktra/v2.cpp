#include <stdio.h>

void dijkstra(int cost[100][100], int n)
{
    int source, dist[100];
    int i, cnt = 0, z, k, j, u;

    printf("Enter the source node whose shortest path is to be determined: ");
    scanf("%d", &source);
    for (i = 0; i < n; i++)
    {
        dist[i] = cost[source][i];
    }

    for (u = 0; u < n; u++)
    {
        cnt = 0; // reset the counter for each node
        for (z = 0; z < n; z++)
        {
            if (cost[z][u] != 1000)
            {
                cnt += 1;
            }
        }
        if (cnt != 0)
        {
            for (i = 0; i < n; i++)
            {
                if (dist[u] > (dist[i] + cost[i][u]))
                {
                    dist[u] = dist[i] + cost[i][u];
                }
            }
        }
    }

    printf("The shortest path from %d to all other nodes is: ", source);
    for (i = 0; i < n; i++)
    {
        if (i != source)
        {
            printf("\n%d : %d", i, dist[i]);
        }
    }
}

int main()
{
    int n, i, j, cost[100][100];
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the cost matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }
    dijkstra(cost, n);
    return 0;
}
