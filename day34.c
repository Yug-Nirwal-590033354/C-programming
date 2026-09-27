#include <stdio.h>

void readMatrix(int r, int c, int a[r][c])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

void printMatrix(int r, int c, int a[r][c])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int r, int c,
               int a[r][c], int b[r][c], int result[r][c])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrix(int r1, int c1, int c2,
                    int a[r1][c1],
                    int b[c1][c2],
                    int result[r1][c2])
{
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            result[i][j] = 0;

            for (int k = 0; k < c1; k++)
            {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int compareMatrix(int r, int c,
                  int a[r][c], int b[r][c])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (a[i][j] != b[i][j])
                return 0;
        }
    }

    return 1;
}

void leftDistributive()
{
    int m, n, p;

    printf("Enter m, n and p: ");
    scanf("%d %d %d", &m, &n, &p);

    int A[m][n], B[n][p], C[n][p];
    int BC[n][p];

    int LHS[m][p];
    int AB[m][p], AC[m][p];
    int RHS[m][p];

    printf("Enter Matrix A:\n");
    readMatrix(m, n, A);

    printf("Enter Matrix B:\n");
    readMatrix(n, p, B);

    printf("Enter Matrix C:\n");
    readMatrix(n, p, C);

    // LHS = A * (B + C)
    addMatrix(n, p, B, C, BC);
    multiplyMatrix(m, n, p, A, BC, LHS);

    // RHS = (A * B) + (A * C)
    multiplyMatrix(m, n, p, A, B, AB);
    multiplyMatrix(m, n, p, A, C, AC);
    addMatrix(m, p, AB, AC, RHS);

    printf("\nA * (B + C):\n");
    printMatrix(m, p, LHS);

    printf("\n(A * B) + (A * C):\n");
    printMatrix(m, p, RHS);

    if (compareMatrix(m, p, LHS, RHS))
        printf("\nLeft distributive property is verified.\n");
    else
        printf("\nLeft distributive property is not verified.\n");
}

void rightDistributive()
{
    int m, n, p;

    printf("Enter m, n and p: ");
    scanf("%d %d %d", &m, &n, &p);

    int A[m][n], B[m][n], C[n][p];
    int AB[m][n];

    int LHS[m][p];
    int AC[m][p], BC[m][p];
    int RHS[m][p];

    printf("Enter Matrix A:\n");
    readMatrix(m, n, A);

    printf("Enter Matrix B:\n");
    readMatrix(m, n, B);

    printf("Enter Matrix C:\n");
    readMatrix(n, p, C);

    // LHS = (A + B) * C
    addMatrix(m, n, A, B, AB);
    multiplyMatrix(m, n, p, AB, C, LHS);

    // RHS = (A * C) + (B * C)
    multiplyMatrix(m, n, p, A, C, AC);
    multiplyMatrix(m, n, p, B, C, BC);
    addMatrix(m, p, AC, BC, RHS);

    printf("\n(A + B) * C:\n");
    printMatrix(m, p, LHS);

    printf("\n(A * C) + (B * C):\n");
    printMatrix(m, p, RHS);

    if (compareMatrix(m, p, LHS, RHS))
        printf("\nRight distributive property is verified.\n");
    else
        printf("\nRight distributive property is not verified.\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n----- MENU -----\n");
        printf("1. Verify Left Distributive Property\n");
        printf("2. Verify Right Distributive Property\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                leftDistributive();
                break;

            case 2:
                rightDistributive();
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 3);

    return 0;
}
