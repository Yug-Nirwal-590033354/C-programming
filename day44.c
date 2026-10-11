#include <stdio.h>
#include <string.h>

void reverseWords(char str[]);
void printInitials(char name[]);

int main()
{
    int choice;
    char str[200];

    do
    {
        printf("\n--- MENU ---\n");
        printf("1. Reverse each word in a sentence\n");
        printf("2. Print initials of a name\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice)
        {
            case 1:
                printf("Enter a sentence: ");
                fgets(str, sizeof(str), stdin);

                str[strcspn(str, "\n")] = '\0';

                reverseWords(str);
                break;

            case 2:
                printf("Enter a name: ");
                fgets(str, sizeof(str), stdin);

                str[strcspn(str, "\n")] = '\0';

                printInitials(str);
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 3);

    return 0;
}


void reverseWords(char str[])
{
    int i = 0, start, end;
    char temp;

    while(str[i] != '\0')
    {
        /* Skip spaces */
        while(str[i] == ' ')
            i++;

        start = i;

        /* Find end of current word */
        while(str[i] != ' ' && str[i] != '\0')
            i++;

        end = i - 1;

        /* Reverse current word */
        while(start < end)
        {
            temp = str[start];
            str[start] = str[end];
            str[end] = temp;

            start++;
            end--;
        }
    }

    printf("Output: %s\n", str);
}


void printInitials(char name[])
{
    int i;

    /* First character of name */
    if(name[0] != '\0' && name[0] != ' ')
        printf("%c.", name[0]);

    /* Character after every space */
    for(i = 1; name[i] != '\0'; i++)
    {
        if(name[i - 1] == ' ' && name[i] != ' ')
            printf("%c.", name[i]);
    }

    printf("\n");
}
