#include <stdio.h>

void kth_smallest(int *arr, int size, int k)
{
    int i, j, temp;

    // Check if k is valid
    if (k <= 0 || k > size)
    {
        printf("-1");
        return;
    }

    // Bubble Sort
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (*(arr + j) > *(arr + j + 1))
            {
                temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }

    // kth position means index k-1
    printf("kth smallest element: %d", *(arr + k - 1));
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

    kth_smallest(arr, size, k);

    return 0;
}
