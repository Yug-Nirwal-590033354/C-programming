#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Student {
    char name[50];
    int id;
    struct Date dob;
};

int main() {
    int n, i, identical = 1;

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student *students1 = (struct Student *)malloc(n * sizeof(struct Student));
    struct Student *students2 = (struct Student *)malloc(n * sizeof(struct Student));

    if (students1 == NULL || students2 == NULL) {
        printf("Memory allocation failed.\n");
        free(students1);
        free(students2);
        return 1;
    }

    printf("\nEnter student details:\n");

    for (i = 0; i < n; i++) {
        printf("\nStudent %d\n", i + 1);

        printf("Name: ");
        scanf(" %49[^\n]", students1[i].name);

        printf("ID: ");
        scanf("%d", &students1[i].id);

        printf("Date of Birth (DD MM YYYY): ");
        scanf("%d %d %d",
              &students1[i].dob.day,
              &students1[i].dob.month,
              &students1[i].dob.year);
    }

    /* Copy records from first array to second array */
    for (i = 0; i < n; i++) {
        students2[i] = students1[i];
    }

    /* Compare both arrays */
    for (i = 0; i < n; i++) {
        if (strcmp(students1[i].name, students2[i].name) != 0 ||
            students1[i].id != students2[i].id ||
            students1[i].dob.day != students2[i].dob.day ||
            students1[i].dob.month != students2[i].dob.month ||
            students1[i].dob.year != students2[i].dob.year) {
            identical = 0;
            break;
        }
    }

    printf("\n--- First Array ---\n");
    for (i = 0; i < n; i++) {
        printf("Name: %s | ID: %d | DOB: %02d/%02d/%04d\n",
               students1[i].name,
               students1[i].id,
               students1[i].dob.day,
               students1[i].dob.month,
               students1[i].dob.year);
    }

    printf("\n--- Second Array ---\n");
    for (i = 0; i < n; i++) {
        printf("Name: %s | ID: %d | DOB: %02d/%02d/%04d\n",
               students2[i].name,
               students2[i].id,
               students2[i].dob.day,
               students2[i].dob.month,
               students2[i].dob.year);
    }

    if (identical)
        printf("\nBoth arrays are identical.\n");
    else
        printf("\nBoth arrays are not identical.\n");

    free(students1);
    free(students2);

    return 0;
}
