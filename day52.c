#include <stdio.h>

void previous_greater(int *arr, int size)
{
    int i, j, greater;

    for (i = 0; i < size; i++)
    {
        greater = -1;

        // Search towards the left
        for (j = i - 1; j >= 0; j--)
        {
            if (*(arr + j) > *(arr + i))
            {
                greater = *(arr + j);
                break;   // nearest greater element found
            }
        }

        printf("%d", greater);

        if (i < size - 1)
        {
            printf(", ");
        }
    }
}

int main()
{
    int size, i;

    printf("Enter size of array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter array elements: ");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Previous greater elements: ");
    previous_greater(arr, size);

    return 0;
}
