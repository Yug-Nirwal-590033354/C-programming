#include <stdio.h>
#include <string.h>

/* Function to change date format */
void changeDateFormat()
{
    int day, month, year;

    char months[12][4] = {
        "Jan", "Feb", "Mar", "Apr",
        "May", "Jun", "Jul", "Aug",
        "Sep", "Oct", "Nov", "Dec"
    };

    printf("Enter date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &day, &month, &year);

    if (month >= 1 && month <= 12)
    {
        printf("Formatted Date: %02d-%s-%02d\n",
               day, months[month - 1], year % 100);
    }
    else
    {
        printf("Invalid month!\n");
    }
}

/* Function to print all substrings */
void printSubstrings()
{
    char str[100];
    int i, j, k;
    int n;

    printf("Enter a string: ");
    scanf("%99s", str);

    n = strlen(str);

    printf("Substrings are:\n");

    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            for (k = i; k <= j; k++)
            {
                printf("%c", str[k]);
            }

            printf("\n");
        }
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n----- MENU -----\n");
        printf("1. Change Date Format\n");
        printf("2. Print All Substrings\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                changeDateFormat();
                break;

            case 2:
                printSubstrings();
                break;

            case 3:
                printf("Program terminated.\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 3);

    return 0;
}
