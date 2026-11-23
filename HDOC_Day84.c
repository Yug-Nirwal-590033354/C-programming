#include <stdio.h>
#include <string.h>

int main(void) {
    char name[100];
    char line[200];
    int age;
    FILE *file;

    printf("Enter your name: ");
    if (fgets(name, sizeof(name), stdin) == NULL) {
        printf("Error reading name.\n");
        return 1;
    }
    name[strcspn(name, "\n")] = '\0';

    printf("Enter your age: ");
    if (scanf("%d", &age) != 1 || age < 0) {
        printf("Invalid age.\n");
        return 1;
    }

    file = fopen("info.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    if (fprintf(file, "Name: %s\nAge: %d\n", name, age) < 0) {
        printf("Error writing to file.\n");
        fclose(file);
        return 1;
    }
    if (fclose(file) == EOF) {
        printf("Error closing file after writing.\n");
        return 1;
    }
    printf("Data successfully written to info.txt\n");

    file = fopen("info.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return 1;
    }

    printf("\nContents of info.txt:\n");
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }
    if (ferror(file)) {
        printf("Error reading file.\n");
        fclose(file);
        return 1;
    }
    fclose(file);
    return 0;
}
