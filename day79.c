#include <stdio.h>

struct Student {
    char name[50];
    int roll_no;
    int marks;
};

void printStudent(struct Student s) {
    printf("%s %d %d\n", s.name, s.roll_no, s.marks);
}

int main() {
    int n, i, maxIndex = 0;
    char choice;

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student students[n];

    printf("Enter student details (Name Roll Marks):\n");

    for (i = 0; i < n; i++) {
        scanf("%49s %d %d",
              students[i].name,
              &students[i].roll_no,
              &students[i].marks);
    }

    do {
        printf("\nMenu:\n");
        printf("a. Find student with highest marks\n");
        printf("b. Print all students\n");
        printf("c. Exit\n");
        printf("Enter choice: ");
        scanf(" %c", &choice);

        switch (choice) {

            case 'a':
                maxIndex = 0;

                for (i = 1; i < n; i++) {
                    if (students[i].marks > students[maxIndex].marks) {
                        maxIndex = i;
                    }
                }

                printf("\nStudent with highest marks:\n");
                printStudent(students[maxIndex]);
                break;

            case 'b':
                printf("\nAll Student Details:\n");

                for (i = 0; i < n; i++) {
                    printStudent(students[i]);
                }
                break;

            case 'c':
                printf("Program exits\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 'c');

    return 0;
}
