#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isValidInteger(char str[])
{
    int i = 0;

    if (str[0] == '-' || str[0] == '+')
    {
        i = 1;
    }

    if (str[i] == '\0')
    {
        return 0;
    }

    while (str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9')
        {
            return 0;
        }

        i++;
    }

    return 1;
}

void sortArray(int arr[], int n)
{
    int temp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

double calculateAverage(int arr[], int n)
{
    double sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    return sum / n;
}

double calculateMedian(int arr[], int n)
{
    if (n % 2 == 0)
    {
        return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    }
    else
    {
        return arr[n / 2];
    }
}

int secondLargestDistinct(int arr[], int n, int *found)
{
    int largest = arr[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] != largest)
        {
            *found = 1;
            return arr[i];
        }
    }

    *found = 0;
    return 0;
}

int main(int argc, char *argv[])
{
    int arr[argc];
    int count = 0;

    for (int i = 1; i < argc; i++)
    {
        if (isValidInteger(argv[i]))
        {
            arr[count] = atoi(argv[i]);
            count++;
        }
        else
        {
            printf("Invalid argument ignored: %s\n", argv[i]);
        }
    }

    if (count == 0)
    {
        printf("No valid integers provided.\n");
        return 0;
    }

    sortArray(arr, count);

    printf("Valid integers in ascending order: ");

    for (int i = 0; i < count; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    printf("Minimum: %d\n", arr[0]);

    printf("Maximum: %d\n", arr[count - 1]);

    printf("Average: %.2f\n",
           calculateAverage(arr, count));

    printf("Median: %.2f\n",
           calculateMedian(arr, count));

    int found;
    int secondLargest =
        secondLargestDistinct(arr, count, &found);

    if (found)
    {
        printf("Second-largest distinct value: %d\n",
               secondLargest);
    }
    else
    {
        printf("Second-largest distinct value does not exist.\n");
    }

    return 0;
}
