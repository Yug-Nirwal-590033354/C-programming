#include <stdio.h>
#include <string.h>

enum BookType {
    FICTION,
    NON_FICTION,
    REFERENCE
};

struct Book {
    char title[100];
    char author[100];
    enum BookType type;
};

int main() {
    struct Book b;
    int choice;

    printf("Enter book title: ");
    fgets(b.title, sizeof(b.title), stdin);
    b.title[strcspn(b.title, "\n")] = '\0';

    printf("Enter author name: ");
    fgets(b.author, sizeof(b.author), stdin);
    b.author[strcspn(b.author, "\n")] = '\0';

    printf("Enter book type (0-Fiction, 1-Non-Fiction, 2-Reference): ");
    scanf("%d", &choice);

    b.type = (enum BookType)choice;

    printf("\nBook Details\n");
    printf("----------------\n");
    printf("Title: %s\n", b.title);
    printf("Author: %s\n", b.author);

    printf("Book Type: ");

    switch (b.type) {
        case FICTION:
            printf("Fiction\n");
            break;

        case NON_FICTION:
            printf("Non-Fiction\n");
            break;

        case REFERENCE:
            printf("Reference\n");
            break;

        default:
            printf("Invalid Book Type\n");
    }

    return 0;
}
