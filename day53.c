#include <stdio.h>

void product_except_self(int *nums, int size)
{
    int answer[size];
    int prefix = 1;
    int suffix = 1;

    // Store product of all elements to the left
    for (int i = 0; i < size; i++)
    {
        answer[i] = prefix;
        prefix = prefix * *(nums + i);
    }

    // Multiply by product of all elements to the right
    for (int i = size - 1; i >= 0; i--)
    {
        answer[i] = answer[i] * suffix;
        suffix = suffix * *(nums + i);
    }

    // Display answer array
    for (int i = 0; i < size; i++)
    {
        printf("%d", answer[i]);

        if (i < size - 1)
            printf(", ");
    }
}

int main()
{
    int size;

    printf("Enter the size of array: ");
    scanf("%d", &size);

    int nums[size];

    printf("Enter the elements: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", nums + i);
    }

    printf("Output: ");
    product_except_self(nums, size);

    return 0;
}
