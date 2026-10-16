#include <stdio.h>

void pivot_integer(int *n)
{
    int x, i;
    int leftSum, rightSum;

    for (x = 1; x <= *n; x++)
    {
        leftSum = 0;
        rightSum = 0;

        // Sum from 1 to x
        for (i = 1; i <= x; i++)
        {
            leftSum += i;
        }

        // Sum from x to n
        for (i = x; i <= *n; i++)
        {
            rightSum += i;
        }

        if (leftSum == rightSum)
        {
            printf("Pivot integer: %d\n", x);
            return;
        }
    }

    printf("-1\n");
}

int main()
{
    int n;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    pivot_integer(&n);

    return 0;
}
