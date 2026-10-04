#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000
#define WORD_MAX 100
#define MAX_WORDS 200

// Function declarations
void readParagraph(char paragraph[], size_t size);

void findLongestAndShortestWords(const char paragraph[],
                                 char longestWord[],
                                 char shortestWord[]);

void removeRepeatedSpaces(const char paragraph[],
                          char modifiedParagraph[]);

void convertToTitleCase(const char paragraph[],
                        char titleCaseParagraph[]);

void findWordFrequencies(const char paragraph[]);


// --------------------------------------------------
// 1. Read paragraph
// --------------------------------------------------
void readParagraph(char paragraph[], size_t size)
{
    fgets(paragraph, size, stdin);

    // Remove newline added by fgets()
    paragraph[strcspn(paragraph, "\n")] = '\0';
}


// --------------------------------------------------
// 2. Find longest and shortest word
// --------------------------------------------------
void findLongestAndShortestWords(const char paragraph[],
                                 char longestWord[],
                                 char shortestWord[])
{
    char temp[MAX];

    strcpy(temp, paragraph);

    char *word = strtok(temp, " ,.!?;:\t\n");

    if (word == NULL)
    {
        strcpy(longestWord, "");
        strcpy(shortestWord, "");
        return;
    }

    // First word is initially both longest and shortest
    strcpy(longestWord, word);
    strcpy(shortestWord, word);

    while (word != NULL)
    {
        if (strlen(word) > strlen(longestWord))
        {
            strcpy(longestWord, word);
        }

        if (strlen(word) < strlen(shortestWord))
        {
            strcpy(shortestWord, word);
        }

        word = strtok(NULL, " ,.!?;:\t\n");
    }
}


// --------------------------------------------------
// 3. Remove repeated spaces
// --------------------------------------------------
void removeRepeatedSpaces(const char paragraph[],
                          char modifiedParagraph[])
{
    int i = 0;
    int j = 0;
    int previousWasSpace = 0;

    while (paragraph[i] != '\0')
    {
        if (isspace((unsigned char)paragraph[i]))
        {
            if (!previousWasSpace)
            {
                modifiedParagraph[j] = ' ';
                j++;

                previousWasSpace = 1;
            }
        }
        else
        {
            modifiedParagraph[j] = paragraph[i];
            j++;

            previousWasSpace = 0;
        }

        i++;
    }

    modifiedParagraph[j] = '\0';
}


// --------------------------------------------------
// 4. Convert paragraph to Title Case
// --------------------------------------------------
void convertToTitleCase(const char paragraph[],
                        char titleCaseParagraph[])
{
    int i = 0;
    int newWord = 1;

    while (paragraph[i] != '\0')
    {
        if (isalpha((unsigned char)paragraph[i]))
        {
            if (newWord)
            {
                titleCaseParagraph[i] =
                    toupper((unsigned char)paragraph[i]);

                newWord = 0;
            }
            else
            {
                titleCaseParagraph[i] =
                    tolower((unsigned char)paragraph[i]);
            }
        }
        else
        {
            titleCaseParagraph[i] = paragraph[i];

            if (isspace((unsigned char)paragraph[i]))
            {
                newWord = 1;
            }
        }

        i++;
    }

    titleCaseParagraph[i] = '\0';
}


// --------------------------------------------------
// 5. Find frequency of every distinct word
// --------------------------------------------------
void findWordFrequencies(const char paragraph[])
{
    char temp[MAX];
    char words[MAX_WORDS][WORD_MAX];
    int frequency[MAX_WORDS];

    int wordCount = 0;

    strcpy(temp, paragraph);

    char *word = strtok(temp, " ,.!?;:\t\n");

    while (word != NULL)
    {
        // Convert word to lowercase
        for (int i = 0; word[i] != '\0'; i++)
        {
            word[i] = tolower((unsigned char)word[i]);
        }

        int found = -1;

        // Check if word already exists
        for (int i = 0; i < wordCount; i++)
        {
            if (strcmp(words[i], word) == 0)
            {
                found = i;
                break;
            }
        }

        // Word already exists
        if (found != -1)
        {
            frequency[found]++;
        }

        // New word
        else
        {
            if (wordCount < MAX_WORDS)
            {
                strcpy(words[wordCount], word);
                frequency[wordCount] = 1;

                wordCount++;
            }
        }

        word = strtok(NULL, " ,.!?;:\t\n");
    }

    printf("\nWord Frequencies:\n");

    for (int i = 0; i < wordCount; i++)
    {
        printf("%s : %d\n", words[i], frequency[i]);
    }
}


// --------------------------------------------------
// MAIN FUNCTION
// --------------------------------------------------
int main()
{
    char paragraph1[MAX];
    char paragraph2[MAX];

    char longest[WORD_MAX];
    char shortest[WORD_MAX];

    char modified[MAX];
    char titleCase[MAX];

    int choice;

    printf("Enter Paragraph 1:\n");
    readParagraph(paragraph1, MAX);

    printf("\nEnter Paragraph 2:\n");
    readParagraph(paragraph2, MAX);

    do
    {
        printf("\n====================================\n");
        printf("              MENU\n");
        printf("====================================\n");

        printf("1. Find longest and shortest words\n");
        printf("2. Remove repeated spaces\n");
        printf("3. Convert to Title Case\n");
        printf("4. Find word frequencies\n");
        printf("5. Display original paragraphs\n");
        printf("6. Exit\n");

        printf("====================================\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:

                printf("\n--- Paragraph 1 ---\n");

                findLongestAndShortestWords(
                    paragraph1,
                    longest,
                    shortest
                );

                printf("Longest Word  : %s\n", longest);
                printf("Shortest Word : %s\n", shortest);


                printf("\n--- Paragraph 2 ---\n");

                findLongestAndShortestWords(
                    paragraph2,
                    longest,
                    shortest
                );

                printf("Longest Word  : %s\n", longest);
                printf("Shortest Word : %s\n", shortest);

                break;


            case 2:

                printf("\n--- Paragraph 1 ---\n");

                removeRepeatedSpaces(
                    paragraph1,
                    modified
                );

                printf("%s\n", modified);


                printf("\n--- Paragraph 2 ---\n");

                removeRepeatedSpaces(
                    paragraph2,
                    modified
                );

                printf("%s\n", modified);

                break;


            case 3:

                printf("\n--- Paragraph 1 ---\n");

                convertToTitleCase(
                    paragraph1,
                    titleCase
                );

                printf("%s\n", titleCase);


                printf("\n--- Paragraph 2 ---\n");

                convertToTitleCase(
                    paragraph2,
                    titleCase
                );

                printf("%s\n", titleCase);

                break;


            case 4:

                printf("\n--- Paragraph 1 ---\n");
                findWordFrequencies(paragraph1);

                printf("\n--- Paragraph 2 ---\n");
                findWordFrequencies(paragraph2);

                break;


            case 5:

                printf("\nParagraph 1:\n%s\n", paragraph1);
                printf("\nParagraph 2:\n%s\n", paragraph2);

                break;


            case 6:

                printf("\nProgram terminated.\n");
                break;


            default:

                printf("\nInvalid choice! Please enter 1-6.\n");
        }

    } while (choice != 6);

    return 0;
}
