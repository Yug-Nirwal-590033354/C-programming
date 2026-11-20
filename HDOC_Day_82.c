#include <stdio.h>
#include <string.h>

#define MAX 100

struct Date {
    int day;
    int month;
    int year;
};

struct Employee {
    char name[50];
    int id;
    struct Date joiningDate;
};

int main() {
    struct Employee emp1[MAX], emp2[MAX];
    int n, i;
    int identical = 1;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter details of Employee %d:\n", i + 1);

        printf("Name: ");
        scanf(" %[^\n]", emp1[i].name);

        printf("ID: ");
        scanf("%d", &emp1[i].id);

        printf("Date of Joining (DD MM YYYY): ");
        scanf("%d %d %d",
              &emp1[i].joiningDate.day,
              &emp1[i].joiningDate.month,
              &emp1[i].joiningDate.year);
    }

    for (i = 0; i < n; i++) {
        emp2[i] = emp1[i];
    }

    for (i = 0; i < n; i++) {
        if (strcmp(emp1[i].name, emp2[i].name) != 0 ||
            emp1[i].id != emp2[i].id ||
            emp1[i].joiningDate.day != emp2[i].joiningDate.day ||
            emp1[i].joiningDate.month != emp2[i].joiningDate.month ||
            emp1[i].joiningDate.year != emp2[i].joiningDate.year) {
            identical = 0;
            break;
        }
    }

    printf("\nCopied Employee Details:\n");
    for (i = 0; i < n; i++) {
        printf("%s %d %02d/%02d/%04d\n",
               emp2[i].name,
               emp2[i].id,
               emp2[i].joiningDate.day,
               emp2[i].joiningDate.month,
               emp2[i].joiningDate.year);
    }

    if (identical)
        printf("\nBoth arrays are identical.\n");
    else
        printf("\nBoth arrays are not identical.\n");

    return 0;
}
