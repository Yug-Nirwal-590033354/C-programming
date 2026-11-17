#include <stdio.h>

struct Student {
    char name[50];
    int roll_no;
    int marks;
};

int main() {
    struct Student students[5];
    int i;

    printf("Enter details of 5 students:\n");

    for (i = 0; i < 5; i++) {
        printf("\nStudent %d\n", i + 1);

        printf("Name: ");
        scanf("%49s", students[i].name);

        printf("Roll: ");
        scanf("%d", &students[i].roll_no);

        printf("Marks: ");
        scanf("%d", &students[i].marks);
    }

    printf("\nStudent Details\n");
    printf("------------------------------------\n");
    printf("Name\t\tRoll\tMarks\n");
    printf("------------------------------------\n");

    for (i = 0; i < 5; i++) {
        printf("%-15s\t%d\t%d\n",
               students[i].name,
               students[i].roll_no,
               students[i].marks);
    }

    return 0;
}
