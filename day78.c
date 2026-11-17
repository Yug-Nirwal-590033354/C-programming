#include <stdio.h>

struct Student {
    char name[50];
    int roll_no;
    int marks;
};

int main() {
    struct Student s;

    printf("Name: ");
    scanf("%49s", s.name);

    printf("Roll: ");
    scanf("%d", &s.roll_no);

    printf("Marks: ");
    scanf("%d", &s.marks);

    printf("\nName: %s | Roll: %d | Marks: %d\n",
           s.name, s.roll_no, s.marks);

    return 0;
}
