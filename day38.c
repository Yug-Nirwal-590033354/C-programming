#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function 1: Count spaces, digits and special characters
void countCharacters(char str[])
{
    int spaces = 0, digits = 0, special = 0;
    int i;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            spaces++;
        }
        else if (isdigit(str[i]))
        {
            digits++;
        }
        else if (!isalpha(str[i]))
        {
            special++;
        }
    }

    printf("\nNumber of spaces = %d", spaces);
    printf("\nNumber of digits = %d", digits);
    printf("\nNumber of special characters = %d\n", special);
}

// Function 2: Count frequency of a given character
void countFrequency(char str[])
{
    char ch;
    int count = 0, i;

    printf("Enter the character to find: ");
    scanf(" %c", &ch);

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ch)
        {
            count++;
        }
    }

    printf("Frequency of '%c' = %d\n", ch, count);
}

// Function 3: Toggle case of each character
void toggleCase(char str[])
{
    int i;

    printf("String after toggling case: ");

    for (i = 0; str[i] != '\0'; i++)
    {
        if (islower(str[i]))
        {
            printf("%c", toupper(str[i]));
        }
        else if (isupper(str[i]))
        {
            printf("%c", tolower(str[i]));
        }
        else
        {
            printf("%c", str[i]);
        }
    }

    printf("\n");
}

int main()
{
    char str[200];
    int choice;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline added by fgets
    str[strcspn(str, "\n")] = '\0';

    do
    {
        printf("\n----- MENU -----\n");
        printf("1. Count spaces, digits and special characters\n");
        printf("2. Count frequency of a character\n");
        printf("3. Toggle case of each character\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                countCharacters(str);
                break;

            case 2:
                countFrequency(str);
                break;

            case 3:
                toggleCase(str);
                break;

            case 4:
                printf("Program exited successfully.\n");
                break;

            default:
                printf("Invalid choice! Please enter 1 to 4.\n");
        }

    } while (choice != 4);

    return 0;
}
