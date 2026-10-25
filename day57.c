#include <stdio.h>

void max_subarray_sum(int *arr, int size)
{
    int current_sum = *arr;
    int max_sum = *arr;

    for (int i = 1; i < size; i++)
    {
        // Kadane's Algorithm
        if (current_sum + *(arr + i) > *(arr + i))
        {
            current_sum = current_sum + *(arr + i);
        }
        else
        {
            current_sum = *(arr + i);
        }

        if (current_sum > max_sum)
        {
            max_sum = current_sum;
        }
    }

    printf("Maximum subarray sum: %d", max_sum);
}

int main()
{
    int size;

    scanf("%d", &size);

    int arr[size];

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Pass the array using its address
    max_subarray_sum(arr, size);

    return 0;
}
