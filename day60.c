#include <stdio.h>
#include <string.h>

void check_anagram(char *s, char *t)
{
    int freq[26] = {0};

    if (strlen(s) != strlen(t))
    {
        printf("Not Anagram");
        return;
    }

    while (*s != '\0')
    {
        freq[*s - 'a']++;
        s++;
    }

    while (*t != '\0')
    {
        freq[*t - 'a']--;
        t++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (freq[i] != 0)
        {
            printf("Not Anagram");
            return;
        }
    }

    printf("Anagram");
}

int main()
{
    char s[100], t[100];

    printf("String s: ");
    scanf("%99s", s);

    printf("String t: ");
    scanf("%99s", t);

    check_anagram(s, t);

    return 0;
}
