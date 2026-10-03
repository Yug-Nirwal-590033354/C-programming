#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function declarations
void combineNames(const char firstName[], const char middleName[],
                  const char lastName[], char fullName[]);

void findLength(const char fullName[], size_t *length);

void copyName(const char source[], char destination[]);

void compareNames(const char firstName[], const char lastName[],
                  int *comparisonResult);

void reverseNameOrder(const char firstName[], const char middleName[],
                      const char lastName[], char reverseName[]);

void countCharacters(const char fullName[], int *vowels,
                     int *consonants, int *digits, int *spaces);

void searchWord(const char fullName[], const char word[],
                int *searchResult);


int main()
{
    char firstName[50], middleName[50], lastName[50];
    char fullName[150];
    char copiedName[150];
    char reverseName[150];
    char word[50];

    int choice;
    int comparisonResult;
    int vowels, consonants, digits, spaces;
    int searchResult;

    size_t length;

    // Input student name
    printf("Enter first name: ");
    scanf("%49s", firstName);

    printf("Enter middle name: ");
    scanf("%49s", middleName);

    printf("Enter last name: ");
    scanf("%49s", lastName);

    // Create full name initially
    combineNames(firstName, middleName, lastName, fullName);

    do
    {
        printf("\n========== MENU ==========\n");
        printf("1. Combine names\n");
        printf("2. Find length of full name\n");
        printf("3. Copy full name\n");
        printf("4. Compare first and last name\n");
        printf("5. Display name in reverse order\n");
        printf("6. Count vowels, consonants, digits and spaces\n");
        printf("7. Search a word in full name\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                combineNames(firstName, middleName, lastName, fullName);

                printf("Full Name: %s\n", fullName);
                break;


            case 2:
                findLength(fullName, &length);

                printf("Length of full name: %zu\n", length);
                break;


            case 3:
                copyName(fullName, copiedName);

                printf("Copied Name: %s\n", copiedName);
                break;


            case 4:
                compareNames(firstName, lastName, &comparisonResult);

                if(comparisonResult == 0)
                    printf("First name and last name are equal.\n");
                else
                    printf("First name and last name are different.\n");

                break;


            case 5:
                reverseNameOrder(firstName, middleName,
                                 lastName, reverseName);

                printf("Reverse Order: %s\n", reverseName);
                break;


            case 6:
                countCharacters(fullName, &vowels, &consonants,
                                &digits, &spaces);

                printf("Vowels: %d\n", vowels);
                printf("Consonants: %d\n", consonants);
                printf("Digits: %d\n", digits);
                printf("Spaces: %d\n", spaces);

                break;


            case 7:
                printf("Enter word to search: ");
                scanf("%49s", word);

                searchWord(fullName, word, &searchResult);

                if(searchResult == 1)
                    printf("Word found in full name.\n");
                else
                    printf("Word not found in full name.\n");

                break;


            case 8:
                printf("Program exited.\n");
                break;


            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 8);

    return 0;
}


// 1. Combine first, middle and last name
void combineNames(const char firstName[], const char middleName[],
                  const char lastName[], char fullName[])
{
    strcpy(fullName, firstName);

    strcat(fullName, " ");
    strcat(fullName, middleName);

    strcat(fullName, " ");
    strcat(fullName, lastName);
}


// 2. Find length of full name
void findLength(const char fullName[], size_t *length)
{
    *length = strlen(fullName);
}


// 3. Copy full name
void copyName(const char source[], char destination[])
{
    strcpy(destination, source);
}


// 4. Compare first name and last name
void compareNames(const char firstName[], const char lastName[],
                  int *comparisonResult)
{
    *comparisonResult = strcmp(firstName, lastName);
}


// 5. Reverse name order
void reverseNameOrder(const char firstName[], const char middleName[],
                      const char lastName[], char reverseName[])
{
    strcpy(reverseName, lastName);

    strcat(reverseName, " ");
    strcat(reverseName, middleName);

    strcat(reverseName, " ");
    strcat(reverseName, firstName);
}


// 6. Count characters
void countCharacters(const char fullName[], int *vowels,
                     int *consonants, int *digits, int *spaces)
{
    int i;
    char ch;

    *vowels = 0;
    *consonants = 0;
    *digits = 0;
    *spaces = 0;

    for(i = 0; i < strlen(fullName); i++)
    {
        ch = tolower((unsigned char)fullName[i]);

        if(isalpha((unsigned char)ch))
        {
            if(ch == 'a' || ch == 'e' || ch == 'i' ||
               ch == 'o' || ch == 'u')
            {
                (*vowels)++;
            }
            else
            {
                (*consonants)++;
            }
        }
        else if(isdigit((unsigned char)ch))
        {
            (*digits)++;
        }
        else if(isspace((unsigned char)ch))
        {
            (*spaces)++;
        }
    }
}


// 7. Search word in full name
void searchWord(const char fullName[], const char word[],
                int *searchResult)
{
    if(strstr(fullName, word) != NULL)
        *searchResult = 1;
    else
        *searchResult = 0;
}
