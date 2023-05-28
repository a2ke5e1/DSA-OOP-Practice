#include <stdio.h>
#include <math.h>

#define MAX_QUEENS 10

int isSafe(int row, int col, int board[MAX_QUEENS])
{
    for (int prevRow = 1; prevRow < row; prevRow++)
    {
        int prevCol = board[prevRow];
        if (prevCol == col || abs(prevRow - row) == abs(prevCol - col))
            return 0;
    }
    return 1;
}

void solveNQueens(int row, int n, int board[MAX_QUEENS], int *count)
{
    if (row > n)
    {
        printf("\nFeasible solution: %d", ++(*count));
        printf("\nSolutions are: ");
        for (int i = 1; i <= n; i++)
            printf(" %d ", board[i]);
    
        for (int i = 1; i <= n; i++)
        {
            printf("\n");
            for (int j = 1; j <= n; j++)
            {
                if (j == board[i])
                    printf(" X ");
                else
                    printf(" 0 ");
            }
        }
    }
    else
    {
        for (int col = 1; col <= n; col++)
        {
            if (isSafe(row, col, board))
            {
                board[row] = col;
                solveNQueens(row + 1, n, board, count);
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of Queens: ");
    scanf("%d", &n);

    int board[MAX_QUEENS] = {0};
    int count = 0;

    solveNQueens(1, n, board, &count);

    return 0;
}
