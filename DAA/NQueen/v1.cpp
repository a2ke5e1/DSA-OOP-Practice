#include <stdio.h>

int board[10][10];
int n;

void printBoard()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int isSafe(int board[10][10], int row, int col)
{

    for (int i = 0; i < col; i++)
        if (board[row][i])
            return 0;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;

    for (int i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return 0;

    return 1;
}

int solveNQUtil(int board[10][10], int col)
{

    if (col >= n)
        return 1;

    for (int i = 0; i < n; i++)
    {

        if (isSafe(board, i, col))
        {

            board[i][col] = 1;

            if (solveNQUtil(board, col + 1))
                return 1;

            board[i][col] = 0; // BACKTRACK
        }
    }

    return 0;
}

int solveNQ()
{

    if (solveNQUtil(board, 0) == 0)
    {
        printf("Solution does not exist");
        return 0;
    }

    printBoard();
    return 1;
}

int main()
{

    printf("Enter the value of n: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }

    solveNQ();
    return 0;
}
