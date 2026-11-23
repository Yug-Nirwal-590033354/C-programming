#include <stdio.h>
#include <string.h>

int main(void) {
    char sourceName[256], destName[256], line[512];
    FILE *source, *dest;
    int ch;

    printf("Enter source file name: ");
    if (fgets(sourceName, sizeof(sourceName), stdin) == NULL) return 1;
    sourceName[strcspn(sourceName, "\n")] = '\0';

    printf("Enter destination file name: ");
    if (fgets(destName, sizeof(destName), stdin) == NULL) return 1;
    destName[strcspn(destName, "\n")] = '\0';

    if (strcmp(sourceName, destName) == 0) {
        printf("Error: Source and destination must be different files.\n");
        return 1;
    }

    source = fopen(sourceName, "r");
    if (source == NULL) {
        perror("Error opening source file");
        return 1;
    }

    dest = fopen(destName, "w");
    if (dest == NULL) {
        perror("Error opening destination file");
        fclose(source);
        return 1;
    }

    while ((ch = fgetc(source)) != EOF) {
        if (fputc(ch, dest) == EOF) {
            perror("Error copying file");
            fclose(source);
            fclose(dest);
            return 1;
        }
    }
    if (ferror(source)) {
        perror("Error reading source file");
        fclose(source);
        fclose(dest);
        return 1;
    }
    fclose(source);
    if (fclose(dest) == EOF) {
        perror("Error closing destination file");
        return 1;
    }
    printf("File copied successfully.\n");

    dest = fopen(destName, "a");
    if (dest == NULL) {
        perror("Error opening destination file for appending");
        return 1;
    }
    printf("Enter lines to append (type END on a separate line to finish):\n");
    while (fgets(line, sizeof(line), stdin) != NULL) {
        if (strcmp(line, "END\n") == 0 || strcmp(line, "END") == 0)
            break;
        if (fputs(line, dest) == EOF) {
            perror("Error appending text");
            fclose(dest);
            return 1;
        }
    }
    if (fclose(dest) == EOF) {
        perror("Error saving appended text");
        return 1;
    }
    printf("Text appended successfully.\n");

    dest = fopen(destName, "r");
    if (dest == NULL) {
        perror("Error reopening destination file");
        return 1;
    }
    printf("\nComplete contents of %s:\n", destName);
    while ((ch = fgetc(dest)) != EOF)
        putchar(ch);
    if (ferror(dest)) {
        perror("Error reading destination file");
        fclose(dest);
        return 1;
    }
    fclose(dest);
    printf("\n");
    return 0;
}
