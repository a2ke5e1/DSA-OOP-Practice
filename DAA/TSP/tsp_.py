

cost_matrix = [[0 for _ in range(10)] for _ in range(10)]
g = [[[[0 for _ in range(10)] for _ in range(10)] for _ in range(10)] for _ in range(10)]

def calg2(x, y):
    g[x][y][0][0] = cost_matrix[x][y] + g[y][0][0][0]
    g[y][x][0][0] = cost_matrix[y][x] + g[x][0][0][0]

def calg3(x, y, z):
    temp1 = cost_matrix[x][y] + g[y][z][0][0]
    temp2 = cost_matrix[x][z] + g[z][y][0][0]

    if temp1 < temp2:
        g[x][y][z][0] = temp1
    else:
        g[x][y][z][0] = temp2


def calg4(x, y, z, w):
    temp1 = cost_matrix[x][y] + g[y][z][w][0]
    temp2 = cost_matrix[x][z] + g[z][y][w][0]
    temp3 = cost_matrix[x][w] + g[w][y][z][0]

    if temp1 < temp2:
        if temp1 < temp3:
            g[x][y][z][w] = temp1
        else:
            g[x][y][z][w] = temp3
    else:
        if temp2 < temp3:
            g[x][y][z][w] = temp2
        else:
            g[x][y][z][w] = temp3

def tsp(n):
    for i in range(2, n+1):
        g[i][0][0][0] = cost_matrix[i][1]
    
    calg2(2, 3)
    calg2(2, 4)
    calg2(3, 4)
    calg3(2, 3, 4)
    calg3(3, 2, 4)
    calg3(4, 2, 3)
    calg4(1, 2, 3, 4)

def main():
    n = int(input("Enter the number of cities: "))
    print("Enter the cost matrix: ")
    for i in range(1, n+1):
        for j in range(1, n+1):
            cost_matrix[i][j] = int(input())

    tsp(n)
    print("The minimum cost is: ", g[1][2][3][4])

if __name__ == "__main__":
    main()
