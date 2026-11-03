#include <stdio.h>

void missing_number(int *nums, int size)
{
    int expected_sum = size * (size + 1) / 2;
    int actual_sum = 0;

    for (int i = 0; i < size; i++)
    {
        actual_sum += *(nums + i);
    }

    int missing = expected_sum - actual_sum;

    printf("Missing number: %d", missing);
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

    missing_number(nums, size);

    return 0;
}
