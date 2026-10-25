#include <stdio.h>

void first_negative(int *arr, int size, int k)
{
    int i, j, found;

    // Check if k is invalid
    if (k <= 0 || k > size)
    {
        printf("-1");
        return;
    }

    // Move the sliding window
    for (i = 0; i <= size - k; i++)
    {
        found = 0;

        // Check elements inside the current window
        for (j = i; j < i + k; j++)
        {
            if (*(arr + j) < 0)
            {
                printf("%d", *(arr + j));
                found = 1;
                break;
            }
        }

        // No negative element found
        if (found == 0)
        {
            printf("0");
        }

        if (i < size - k)
        {
            printf(" ");
        }
    }
}

int main()
{
    int size, k, i;

    scanf("%d", &size);

    int arr[size];

    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &k);

    // Pass array using its address
    first_negative(arr, size, k);

    return 0;
}
