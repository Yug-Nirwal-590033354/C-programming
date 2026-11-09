#include <stdio.h>
#include <stdlib.h>

void add(int *A, int *B, int *C, int r, int c)
{
    for (int i = 0; i < r * c; i++)
        *(C + i) = *(A + i) + *(B + i);
}

void subtract(int *A, int *B, int *C, int r, int c)
{
    for (int i = 0; i < r * c; i++)
        *(C + i) = *(A + i) - *(B + i);
}

void multiply(int *A, int *B, int *C, int r1, int c1, int c2)
{
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            *(C + i * c2 + j) = 0;

            for (int k = 0; k < c1; k++)
            {
                *(C + i * c2 + j) +=
                    *(A + i * c1 + k) * *(B + k * c2 + j);
            }
        }
    }
}

void display(int *M, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            printf("%d ", *(M + i * c + j));

        printf("\n");
    }
}

int main()
{
    int r1, c1, r2, c2;

    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns of Matrix B: ");
    scanf("%d %d", &r2, &c2);

    int *A = (int *)malloc(r1 * c1 * sizeof(int));
    int *B = (int *)malloc(r2 * c2 * sizeof(int));

    if (A == NULL || B == NULL)
    {
        printf("Memory allocation failed.\n");
        free(A);
        free(B);
        return 1;
    }

    printf("Enter elements of Matrix A:\n");
    for (int i = 0; i < r1 * c1; i++)
        scanf("%d", A + i);

    printf("Enter elements of Matrix B:\n");
    for (int i = 0; i < r2 * c2; i++)
        scanf("%d", B + i);

    // Addition and Subtraction
    if (r1 == r2 && c1 == c2)
    {
        int *C = (int *)malloc(r1 * c1 * sizeof(int));

        if (C != NULL)
        {
            add(A, B, C, r1, c1);
            printf("\nAddition:\n");
            display(C, r1, c1);

            subtract(A, B, C, r1, c1);
            printf("\nSubtraction:\n");
            display(C, r1, c1);

            free(C);
        }
    }
    else
    {
        printf("\nAddition and subtraction are not possible.\n");
    }

    // Multiplication
    if (c1 == r2)
    {
        int *C = (int *)malloc(r1 * c2 * sizeof(int));

        if (C != NULL)
        {
            multiply(A, B, C, r1, c1, c2);

            printf("\nMultiplication:\n");
            display(C, r1, c2);

            free(C);
        }
    }
    else
    {
        printf("\nMultiplication is not possible.\n");
    }

    free(A);
    free(B);

    return 0;
}
