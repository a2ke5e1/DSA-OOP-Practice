#include <stdio.h>
#include <limits.h>
#include <math.h>
#define MAX = 10

int fnPlace(int K, int I, int X[10])
{
    int J;
    for (J = 1; J <= K - 1; J++)
    {
        if (X[J] == I || abs(J - K) == abs(X[J] - I))
            return 0;
    }
    return 1;
}

void fnQueens(int K, int N)
{
    int I, J, L;
    static int Count, X[10];
    for (I = 1; I <= N; I++)
    {
        if (fnPlace(K, I, X))
        {
            X[K] = I;
            if (K == N)
            {
                printf("\nFeassible solution : %d", ++Count);
                printf("\nSolutions are : ");
                for (J = 1; J <= N; J++)
                    printf(" %d ", X[J]);
                for (J = 1; J <= N; J++)
                {
                    printf("\n");
                    for (L = 1; L <= N; L++)
                    {
                        if (L == X[J])
                            printf(" X ");
                        else
                            printf(" 0 ");
                    }
                }
            }
            else
                fnQueens(K + 1, N);
        }
    }
}
int main()
{
    int No;
    // clrscr();
    printf("Enter the no of Queenes : ");
    scanf("%d", &No);
    fnQueens(1, No);
    // getch();
    return 0; 
}
