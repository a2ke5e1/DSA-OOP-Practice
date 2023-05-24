#include <stdio.h>
#define INF 9999999
#define V 10

int G[V][V], n, selected[V];

void prims()
{
    int no_edge;
    for (int i = 0; i < n; i++)
        selected[i] = false;

    no_edge = 0;
    selected[0] = true;

    int x;
    int y;
    int total_cost = 0;

    while (no_edge < n - 1)
    {

        int min = INF;
        x = 0;
        y = 0;

        for (int i = 0; i < n; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (!selected[j] && G[i][j])
                    { // not in selected and there is an edge
                        if (G[i][j] < min)
                        {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        printf("%d - %d : %d\n", x, y, G[x][y]);
        selected[y] = true;
        total_cost += G[x][y];
        no_edge++;
    }

    printf("Total cost of MST: %d\n", total_cost);
}

int main()
{

    printf("Enter no. of vertices:");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%d", &G[i][j]);
    }

    prims();

    return 0;
}