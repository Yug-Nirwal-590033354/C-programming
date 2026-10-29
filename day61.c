#include <stdio.h>

void two_sum(int *nums, int size, int target)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (*(nums + i) + *(nums + j) == target)
            {
                printf("%d %d", i, j);
                return;
            }
        }
    }

    printf("-1 -1");
}

int main()
{
    int size, target;

    printf("Enter size: ");
    scanf("%d", &size);

    int nums[size];

    printf("Enter array elements: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &nums[i]);
    }

    printf("Enter target: ");
    scanf("%d", &target);

    two_sum(nums, size, target);

    return 0;
}
