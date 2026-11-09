#include <stdio.h>

int calls = 0;

int fibonacci(int n)
{
    calls++;

    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n, i;

    printf("Enter n: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid input");
        return 0;
    }

    printf("First %d Fibonacci numbers: ", n);

    for (i = 0; i < n; i++)
    {
        printf("%d ", fibonacci(i));
    }

    printf("\nNumber of recursive calls: %d", calls);

    return 0;
}
