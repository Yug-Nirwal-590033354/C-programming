#include <stdio.h>

void duplicate_element(int *nums, int size)
{
    int result = 0;

    // XOR all array elements
    for (int i = 0; i < size; i++)
    {
        result ^= *(nums + i);
    }

    // XOR numbers from 1 to size-1
    for (int i = 1; i < size; i++)
    {
        result ^= i;
    }

    printf("Repeated element: %d", result);
}

int main()
{
    int size;

    scanf("%d", &size);

    int nums[size];

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &nums[i]);
    }

    duplicate_element(nums, size);

    return 0;
}
