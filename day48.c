#include <stdio.h>

void pivot_index(int *arr, int n)
{
    int totalSum = 0;
    int leftSum = 0;
    int rightSum;

    // Calculate total sum
    for (int i = 0; i < n; i++)
    {
        totalSum += *(arr + i);
    }

    // Find the leftmost pivot index
    for (int i = 0; i < n; i++)
    {
        rightSum = totalSum - leftSum - *(arr + i);

        if (leftSum == rightSum)
        {
            printf("Pivot index: %d\n", i);
            return;
        }

        leftSum += *(arr + i);
    }

    // No pivot index found
    printf("-1\n");
}

int main()
{
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Passing array using its address
    pivot_index(arr, n);

    return 0;
}
