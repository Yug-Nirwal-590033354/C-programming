#include <stdio.h>

void majority_element(int *nums, int size)
{
    int i, j, count;

    for (i = 0; i < size; i++)
    {
        count = 0;

        // Count occurrences of nums[i]
        for (j = 0; j < size; j++)
        {
            if (*(nums + i) == *(nums + j))
            {
                count++;
            }
        }

        // Check majority condition
        if (count > size / 2)
        {
            printf("Majority element: %d\n", *(nums + i));
            return;
        }
    }

    // No majority element
    printf("-1\n");
}

int main()
{
    int size, i;

    printf("Enter size of array: ");
    scanf("%d", &size);

    int nums[size];

    printf("Enter array elements: ");
    for (i = 0; i < size; i++)
    {
        scanf("%d", (nums + i));
    }

    // Passing array using its address
    majority_element(nums, size);

    return 0;
}
