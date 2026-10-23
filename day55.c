#include <stdio.h>

void window_maximum(int *arr, int size, int k)
{
    if (k <= 0 || k > size)
    {
        printf("-1");
        return;
    }

    // Check every sliding window
    for (int i = 0; i <= size - k; i++)
    {
        int max = *(arr + i);

        // Find maximum in current window
        for (int j = i + 1; j < i + k; j++)
        {
            if (*(arr + j) > max)
            {
                max = *(arr + j);
            }
        }

        printf("%d", max);

        if (i < size - k)
        {
            printf(" ");
        }
    }
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

    window_maximum(arr, size, k);

    return 0;
}
