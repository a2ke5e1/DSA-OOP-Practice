// #include <stdio.h>

// void dijkstra(int cost[100][100], int n)
// {
//     int c = 1, s, i, dist[100], cnt = 0, z, k, j, u, v;
//     while (c)
//     {
//         printf("Enter the source node whose shortest path is to be determined: ");
//         scanf("%d", &s);
//         for (i = 1; i <= n; i++)
//         {
//             dist[i] = cost[s][i];
//         }
//         for (k = 2; k < n; k++)
//         {
//             for (u = 1; u <= n; u++)
//             {
//                 for (z = 1; z <= n; z++)
//                 {
//                     if (cost[z][u] != 1000)
//                     {
//                         cnt += 1;
//                     }
//                 }
//             }
//             if ( cnt != 0) {
//                 cnt = 0;
//                 for (i = 1; i <= n; i++)
//                 {
//                     if ( dist[u] > ( dist[i] + cost[i][u] ) )
//                     {
//                         dist[u] = dist[i] + cost[i][u];
//                     }
//                 }
//             }
//         }
//         printf("The shortest path from %d to all other nodes is: ", s);
//         for (i = 1; i <= n; i++)
//         {
//             if (i != s)
//             {
//                 printf("\n%d : %d",i, dist[i]);
//             }
//         }
//         printf("\nDo you want to continue? (1/0): ");
//         scanf("%d", &c);
//     }
// }

// int main() {
//     int n, i, j, cost[100][100];
//     printf("Enter the number of nodes: ");
//     scanf("%d", &n);
//     for (i = 1; i <= n; i++)
//     {
//         for (j = 1; j <= n; j++)
//         {
//            scanf("%d", &cost[i][j]);
//         }
//     }
//     dijkstra(cost, n);
//     return 0;
// }


#include <stdio.h>

void dijkstra(int cost[100][100], int n)
{
    int c = 1, s, i, dist[100], cnt = 0, z, k, j, u, v;
    while (c)
    {
        printf("Enter the source node whose shortest path is to be determined: ");
        scanf("%d", &s);
        for (i = 1; i <= n; i++)
        {
            dist[i] = cost[s][i];
        }
        for (k = 2; k < n; k++)
        {
            for (u = 1; u <= n; u++)
            {
                cnt = 0; // reset the counter for each node
                for (z = 1; z <= n; z++)
                {
                    if (cost[z][u] != 1000)
                    {
                        cnt += 1;
                    }
                }
                if ( cnt != 0) {
                    for (i = 1; i <= n; i++)
                    {
                        if ( dist[u] > ( dist[i] + cost[i][u] ) )
                        {
                            dist[u] = dist[i] + cost[i][u];
                        }
                    }
                }
            }
        }
        printf("The shortest path from %d to all other nodes is: ", s);
        for (i = 1; i <= n; i++)
        {
            if (i != s)
            {
                printf("\n%d : %d",i, dist[i]);
            }
        }
        printf("\nDo you want to continue? (1/0): ");
        scanf("%d", &c);
    }
}

int main() {
    int n, i, j, cost[100][100];
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the cost matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
           scanf("%d", &cost[i][j]);
        }
    }
    dijkstra(cost, n);
    return 0;
}
