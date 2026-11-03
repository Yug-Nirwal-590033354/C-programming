#include <stdio.h>

#define MAX 10

int multiplyCell(int A[MAX][MAX], int B[MAX][MAX],
                 int row, int col, int k, int n)
{
    if (k == n)
        return 0;

    return A[row][k] * B[k][col] +
           multiplyCell(A, B, row, col, k + 1, n);
}

void multiplyMatrix(int A[MAX][MAX], int B[MAX][MAX],
                    int C[MAX][MAX], int row, int col, int n)
{
    if (row == n)
        return;

    C[row][col] = multiplyCell(A, B, row, col, 0, n);

    if (col + 1 < n)
        multiplyMatrix(A, B, C, row, col + 1, n);
    else
        multiplyMatrix(A, B, C, row + 1, 0, n);
}

int main()
{
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int n;

    scanf("%d", &n);

    // Input first matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    // Input second matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    // Recursive multiplication
    multiplyMatrix(A, B, C, 0, 0, n);

    // Display result
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", C[i][j]);

        printf("\n");
    }

    return 0;
}
