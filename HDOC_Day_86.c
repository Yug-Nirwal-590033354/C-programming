#include <stdio.h>

int main(void) {
    FILE *fp;
    int n, number, count = 0;
    long long sum = 0;
    double average;

    printf("Enter the number of integers: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Error: Enter at least one integer.\n");
        return 1;
    }

    fp = fopen("numbers.txt", "w");
    if (fp == NULL) {
        printf("Error: Cannot open numbers.txt for writing.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter integer %d: ", i + 1);
        if (scanf("%d", &number) != 1) {
            printf("Error: Invalid integer input.\n");
            fclose(fp);
            return 1;
        }
        fprintf(fp, "%d%s", number, (i == n - 1) ? "\n" : " ");
    }
    if (fclose(fp) == EOF) {
        printf("Error: Failed to finish writing numbers.txt.\n");
        return 1;
    }

    printf("Numbers saved successfully to numbers.txt.\n");
    fp = fopen("numbers.txt", "r");
    if (fp == NULL) {
        printf("Error: Cannot open numbers.txt for reading.\n");
        return 1;
    }

    while (fscanf(fp, "%d", &number) == 1) {
        sum += number;
        count++;
    }
    fclose(fp);

    if (count == 0) {
        printf("Error: No integers found. Average cannot be calculated.\n");
        return 1;
    }

    average = (double)sum / count;
    printf("Sum = %lld\n", sum);
    printf("Average = %.2f\n", average);
    return 0;
}
