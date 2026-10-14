#include <stdio.h>

int ceil_index(int *arr, int n, int target)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (*(arr + i) >= target)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int n, target, i, index;

    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &target);

    index = ceil_index(arr, n, target);

    if (index == -1)
    {
        printf("-1");
    }
    else
    {
        printf("Ceil of %d: %d at index %d",
               target, arr[index], index);
    }

    return 0;
}
