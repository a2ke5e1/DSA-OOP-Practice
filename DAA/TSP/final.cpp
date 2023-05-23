#include <stdio.h>
int c[10][10], g[10][10][10][10], n; 
// formula: 
// g{i, S} = min{c{i, j} + g{j, S - {j}}}
int min(int a, int b) { return a < b ? a : b; }
void calg(int x, int y) {
    g[x][y][0][0] = c[x][y] + g[y][0][0][0]; 
    g[y][x][0][0] = c[y][x] + g[x][0][0][0];
}
void calg(int x, int y, int z) {
    int temp1 = c[x][y] + g[y][z][0][0];
    int temp2 = c[x][z] + g[z][y][0][0];
    g[x][y][z][0] = min(temp1, temp2);
}
void calg(int x, int y, int z, int w) {
    int temp1 = c[x][y] + g[y][z][w][0];
    int temp2 = c[x][z] + g[z][y][w][0];
    int temp3 = c[x][w] + g[w][y][z][0];
    g[x][y][z][w] = min(temp1, temp2);
    g[x][y][z][w] = min(g[x][y][z][w], temp3);
}
void tsp() {
    for (int i = 2; i <= n; i++) {
        g[i][0][0][0] = c[i][1];
    }
    calg(2, 3);
    calg(2, 4);
    calg(3, 4);
    calg(2, 3, 4);
    calg(3, 2, 4);
    calg(4, 2, 3);
    calg(1, 2, 3, 4);
}
int main() {
    printf("Enter the number of cities: ");
    scanf("%d", &n);
    printf("Enter the cost matrix: \n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &c[i][j]);
        }
    }
    tsp();
    printf("The minimum cost is: %d\n", g[1][2][3][4]);
    return 0;
}