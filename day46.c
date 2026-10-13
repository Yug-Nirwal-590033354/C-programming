#include <stdio.h>

/* Function for Bubble Sort */
void Bubble_sort(int *nums, int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (*(nums + j) > *(nums + j + 1))
            {
                temp = *(nums + j);
                *(nums + j) = *(nums + j + 1);
                *(nums + j + 1) = temp;
            }
        }
    }
}

/* Function to find first and last occurrence */
void occurrence(int *nums, int n)
{
    int target;
    int first = -1, last = -1;
    int i;

    printf("Enter target: ");
    scanf("%d", &target);

    for (i = 0; i < n; i++)
    {
        if (*(nums + i) == target)
        {
            if (first == -1)
            {
                first = i;
            }

            last = i;
        }
    }

    if (first == -1)
    {
        printf("-1, -1\n");
    }
    else
    {
        printf("First occurrence: %d at index %d\n",
               *(nums + first), first);

        printf("Last occurrence: %d at index %d\n",
               *(nums + last), last);
    }
}

int main()
{
    int n, i;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter %d elements:\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    /* Passing array using its address */
    Bubble_sort(nums, n);

    printf("Sorted array: ");

    for (i = 0; i < n; i++)
    {
        printf("%d ", nums[i]);
    }

    printf("\n");

    occurrence(nums, n);

    return 0;
}
