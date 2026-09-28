#include <stdio.h>

// Function to check whether main diagonal elements are distinct
void checkDistinct(int n, int a[n][n])
{
    int i, j;

    printf("Main diagonal elements: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i][i]);

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i][i] == a[j][j])
            {
                printf("\nMain diagonal elements are not distinct.\n");
                return;
            }
        }
    }

    printf("\nAll the main diagonal elements are distinct.\n");
}


// Function to find sum of main diagonal
void diagonalSum(int n, int a[n][n])
{
    int i, sum = 0;

    for (i = 0; i < n; i++)
    {
        sum = sum + a[i][i];
    }

    printf("Sum of main diagonal elements: %d\n", sum);
}


// Function for diagonal traversal
void diagonalTraversal(int n, int a[n][n])
{
    int d, i, j;

    printf("Diagonal traversal: ");

    // d represents sum of row and column index
    for (d = 0; d <= 2 * n - 2; d++)
    {
        if (d % 2 == 0)
        {
            // Downward-left direction
            i = (d < n) ? 0 : d - n + 1;
            j = d - i;

            while (i < n && j >= 0)
            {
                printf("%d ", a[i][j]);
                i++;
                j--;
            }
        }
        else
        {
            // Upward-right direction
            j = (d < n) ? 0 : d - n + 1;
            i = d - j;

            while (j < n && i >= 0)
            {
                printf("%d ", a[i][j]);
                i--;
                j++;
            }
        }
    }

    printf("\n");
}


int main()
{
    int n, i, j, choice;

    printf("Enter size of square matrix: ");
    scanf("%d", &n);

    int a[n][n];

    printf("Enter matrix elements:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    do
    {
        printf("\n--- MENU ---\n");
        printf("1. Check distinct main diagonal elements\n");
        printf("2. Sum of main diagonal elements\n");
        printf("3. Diagonal traversal\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                checkDistinct(n, a);
                break;

            case 2:
                diagonalSum(n, a);
                break;

            case 3:
                diagonalTraversal(n, a);
                break;

            case 4:
                printf("Program terminated.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}
