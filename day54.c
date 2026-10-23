#include <stdio.h>

void max_subarray_sum(int *arr, int size, int k)
{
    if (k <= 0 || k >= size)
    {
        printf("-1");
        return;
    }

    int maxSum = 0;

    // Sum of first subarray of size k
    for (int i = 0; i < k; i++)
    {
        maxSum += *(arr + i);
    }

    // Check remaining subarrays
    for (int i = 1; i <= size - k; i++)
    {
        int sum = 0;

        for (int j = i; j < i + k; j++)
        {
            sum += *(arr + j);
        }

        if (sum > maxSum)
        {
            maxSum = sum;
        }
    }

    printf("Maximum subarray sum: %d", maxSum);
}

int main()
{
    int size, k;

    printf("Enter size: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter array elements: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    max_subarray_sum(arr, size, k);

    return 0;
}
