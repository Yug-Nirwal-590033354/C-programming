#include <stdio.h>

int digitalRoot(int n)
{
    static int calls = 0;
    calls++;

    if (n < 10)
    {
        printf("Number of recursive calls: %d\n", calls);
        return n;
    }

    int sum = 0;

    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }

    return digitalRoot(sum);
}

int main()
{
    int n, result;

    printf("Enter a number: ");
    scanf("%d", &n);

    result = digitalRoot(n);

    printf("Digital root: %d\n", result);

    return 0;
}
