#include <stdio.h>
#include <string.h>

void longest_unique_substring(char *s)
{
    int maxLength = 0;
    int i, j, k;
    int length;

    if (*s == '\0')
    {
        printf("0");
        return;
    }

    for (i = 0; s[i] != '\0'; i++)
    {
        length = 0;

        for (j = i; s[j] != '\0'; j++)
        {
            int repeated = 0;

            for (k = i; k < j; k++)
            {
                if (*(s + k) == *(s + j))
                {
                    repeated = 1;
                    break;
                }
            }

            if (repeated)
                break;

            length++;

            if (length > maxLength)
                maxLength = length;
        }
    }

    printf("Length of longest substring: %d", maxLength);
}

int main()
{
    char s[1000];

    printf("Enter string: ");
    fgets(s, sizeof(s), stdin);

    s[strcspn(s, "\n")] = '\0';

    longest_unique_substring(s);

    return 0;
}
