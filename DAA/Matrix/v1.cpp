#include <stdio.h>
// formula for matrix multiplication: A[i][j] = A[i][k] + A[k+1][j] + p[i-1]*p[k]*p[j]
                                               
int matrix(int p[], int i, int j) {
    if(i == j) {
        return 0;
    }
    int min = 9999999;
    int count;
    for(int k = i; k < j; k++) {
        count = matrix(p, i, k) + matrix(p, k+1, j) + p[i-1]*p[k]*p[j];
        if(count < min) {
            min = count;
        }
    }
    return min;
}

int main() {
    int n; 
    printf("Enter no. of matrix: ");
    scanf("%d", &n);

    int p[n+1];
    printf("Enter the dimensions: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    printf("Minimum number of multiplications is %d", matrix(p, 1, n-1));
    
}