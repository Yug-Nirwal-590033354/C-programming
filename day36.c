#include <stdio.h>

int countCharacters(char str[])
{
    int i = 0;

    while (str[i] != '\0')
    {
        i++;
    }

    return i;
}

void printCharacters(char str[])
{
    int i = 0;

    printf("\nCharacters are:\n");

    while (str[i] != '\0')
    {
        printf("%c\n", str[i]);
        i++;
    }
}

void countVowelsConsonants(char str[])
{
    int i = 0;
    int vowels = 0, consonants = 0;

    while (str[i] != '\0')
    {
        char ch = str[i];

        if (ch >= 'A' && ch <= 'Z')
        {
            ch = ch + 32;
        }

        if (ch >= 'a' && ch <= 'z')
        {
            if (ch == 'a' || ch == 'e' || ch == 'i' ||
                ch == 'o' || ch == 'u')
            {
                vowels++;
            }
            else
            {
                consonants++;
            }
        }

        i++;
    }

    printf("Number of vowels = %d\n", vowels);
    printf("Number of consonants = %d\n", consonants);
}

int main()
{
    char str[100];
    int choice;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline added by fgets
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '\n')
        {
            str[i] = '\0';
            break;
        }
        i++;
    }

    do
    {
        printf("\n----- MENU -----\n");
        printf("1. Count characters\n");
        printf("2. Print each character on new line\n");
        printf("3. Count vowels and consonants\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Number of characters = %d\n",
                       countCharacters(str));
                break;

            case 2:
                printCharacters(str);
                break;

            case 3:
                countVowelsConsonants(str);
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please enter 1-4.\n");
        }

    } while (choice != 4);

    return 0;
}
