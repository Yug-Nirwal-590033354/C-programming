#include <stdio.h>

void toUpperCase(char str[]) {
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
        i++;
    }

    printf("Uppercase String: %s\n", str);
}

void reverseString(char str[]) {
    int length = 0, i;
    char temp;

    while (str[length] != '\0') {
        length++;
    }

    for (i = 0; i < length / 2; i++) {
        temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }

    printf("Reversed String: %s\n", str);
}

void checkPalindrome(char str[]) {
    int length = 0;
    int i, flag = 1;

    while (str[length] != '\0') {
        length++;
    }

    for (i = 0; i < length / 2; i++) {
        if (str[i] != str[length - i - 1]) {
            flag = 0;
            break;
        }
    }

    if (flag == 1)
        printf("The string is a palindrome.\n");
    else
        printf("The string is not a palindrome.\n");
}

int main() {
    char str[100];
    int choice;

    do {
        printf("\n----- STRING MENU -----\n");
        printf("1. Convert lowercase string to uppercase\n");
        printf("2. Reverse a string\n");
        printf("3. Check palindrome\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {

            case 1:
                printf("Enter a string: ");
                fgets(str, sizeof(str), stdin);

                // Remove newline added by fgets
                int i = 0;
                while (str[i] != '\n' && str[i] != '\0')
                    i++;
                str[i] = '\0';

                toUpperCase(str);
                break;

            case 2:
                printf("Enter a string: ");
                fgets(str, sizeof(str), stdin);

                int j = 0;
                while (str[j] != '\n' && str[j] != '\0')
                    j++;
                str[j] = '\0';

                reverseString(str);
                break;

            case 3:
                printf("Enter a string: ");
                fgets(str, sizeof(str), stdin);

                int k = 0;
                while (str[k] != '\n' && str[k] != '\0')
                    k++;
                str[k] = '\0';

                checkPalindrome(str);
                break;

            case 4:
                printf("Program terminated.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}
