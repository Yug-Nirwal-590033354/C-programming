#include <stdio.h>
#include <string.h>

void longestWord()
{
    char str[200], word[100], longest[100];
    int i = 0, j = 0, maxLength = 0;

    printf("Enter a sentence: ");
    getchar();
    fgets(str, sizeof(str), stdin);

    while (1)
    {
        if (str[i] != ' ' && str[i] != '\0' && str[i] != '\n')
        {
            word[j] = str[i];
            j++;
        }
        else
        {
            word[j] = '\0';

            if (j > maxLength)
            {
                maxLength = j;
                strcpy(longest, word);
            }

            j = 0;
        }

        if (str[i] == '\0')
            break;

        i++;
    }

    printf("Longest word: %s\n", longest);
    printf("Length: %d\n", maxLength);
}


void checkRotation()
{
    char str1[100], str2[100];
    char temp[200];

    printf("Enter first string: ");
    scanf("%99s", str1);

    printf("Enter second string: ");
    scanf("%99s", str2);

    if (strlen(str1) != strlen(str2))
    {
        printf("The strings are NOT rotations of each other.\n");
        return;
    }

    strcpy(temp, str1);
    strcat(temp, str1);

    if (strstr(temp, str2) != NULL)
        printf("The strings ARE rotations of each other.\n");
    else
        printf("The strings are NOT rotations of each other.\n");
}


int main()
{
    int choice;

    do
    {
        printf("\n----- MENU -----\n");
        printf("1. Find longest word in a sentence\n");
        printf("2. Check string rotation\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                longestWord();
                break;

            case 2:
                checkRotation();
                break;

            case 3:
                printf("Program terminated.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 3);

    return 0;
}
