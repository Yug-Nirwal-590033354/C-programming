#include <stdio.h>
#include <stdlib.h>

// Function declarations
int **createMatrix(int students, int days);
void recordAttendance(int **matrix, int start, int students, int days);
int **addStudents(int **matrix, int *students, int newStudents, int days);
void displayAttendance(int **matrix, int students, int days);
void calculatePercentage(int **matrix, int students, int days);
void freeMatrix(int **matrix, int students);

int main()
{
    int students, days, newStudents;
    int **attendance;

    printf("Enter number of students: ");
    if (scanf("%d", &students) != 1 || students <= 0)
    {
        printf("Invalid number of students.\n");
        return 1;
    }

    printf("Enter number of working days: ");
    if (scanf("%d", &days) != 1 || days <= 0)
    {
        printf("Invalid number of working days.\n");
        return 1;
    }

    // Create initial matrix
    attendance = createMatrix(students, days);

    if (attendance == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Record initial attendance
    recordAttendance(attendance, 0, students, days);

    printf("\nInitial Attendance Record:\n");
    displayAttendance(attendance, students, days);

    // Add new students
    printf("\nEnter number of additional students: ");
    if (scanf("%d", &newStudents) != 1 || newStudents < 0)
    {
        printf("Invalid input.\n");
        freeMatrix(attendance, students);
        return 1;
    }

    if (newStudents > 0)
    {
        attendance = addStudents(attendance, &students,
                                 newStudents, days);

        if (attendance == NULL)
        {
            printf("Memory allocation failed.\n");
            return 1;
        }
    }

    printf("\nFinal Attendance Record:\n");
    displayAttendance(attendance, students, days);

    printf("\nAttendance Percentages:\n");
    calculatePercentage(attendance, students, days);

    // Release allocated memory
    freeMatrix(attendance, students);

    return 0;
}


// Create initial attendance matrix
int **createMatrix(int students, int days)
{
    int **matrix;
    int i, j;

    matrix = (int **)malloc(students * sizeof(int *));

    if (matrix == NULL)
        return NULL;

    for (i = 0; i < students; i++)
    {
        matrix[i] = (int *)malloc(days * sizeof(int));

        if (matrix[i] == NULL)
        {
            for (j = 0; j < i; j++)
                free(matrix[j]);

            free(matrix);
            return NULL;
        }
    }

    return matrix;
}


// Record attendance
void recordAttendance(int **matrix, int start,
                      int students, int days)
{
    int i, j, value;

    for (i = start; i < students; i++)
    {
        printf("\nEnter attendance for Student %d:\n", i + 1);

        for (j = 0; j < days; j++)
        {
            do
            {
                printf("Day %d (0 = Absent, 1 = Present): ", j + 1);

                if (scanf("%d", &value) != 1)
                {
                    printf("Invalid input.\n");
                    exit(1);
                }

                if (value != 0 && value != 1)
                    printf("Please enter only 0 or 1.\n");

            } while (value != 0 && value != 1);

            *(*(matrix + i) + j) = value;
        }
    }
}


// Add new students using realloc
int **addStudents(int **matrix, int *students,
                  int newStudents, int days)
{
    int oldStudents = *students;
    int totalStudents = oldStudents + newStudents;
    int **temp;
    int i;

    temp = (int **)realloc(matrix,
                           totalStudents * sizeof(int *));

    if (temp == NULL)
    {
        freeMatrix(matrix, oldStudents);
        return NULL;
    }

    matrix = temp;

    for (i = oldStudents; i < totalStudents; i++)
    {
        matrix[i] = (int *)malloc(days * sizeof(int));

        if (matrix[i] == NULL)
        {
            int j;

            for (j = oldStudents; j < i; j++)
                free(matrix[j]);

            freeMatrix(matrix, oldStudents);
            return NULL;
        }
    }

    *students = totalStudents;

    // Record attendance of newly added students
    recordAttendance(matrix, oldStudents, totalStudents, days);

    return matrix;
}


// Display attendance matrix
void displayAttendance(int **matrix, int students, int days)
{
    int i, j;

    printf("\nStudent\t");

    for (j = 0; j < days; j++)
        printf("Day%d\t", j + 1);

    printf("\n");

    for (i = 0; i < students; i++)
    {
        printf("%d\t", i + 1);

        for (j = 0; j < days; j++)
        {
            printf("%d\t", *(*(matrix + i) + j));
        }

        printf("\n");
    }
}


// Calculate attendance percentage
void calculatePercentage(int **matrix,
                         int students, int days)
{
    int i, j, present;
    float percentage;

    for (i = 0; i < students; i++)
    {
        present = 0;

        for (j = 0; j < days; j++)
        {
            if (*(*(matrix + i) + j) == 1)
                present++;
        }

        percentage = ((float)present / days) * 100;

        printf("Student-%d: %.1f%%\n",
               i + 1, percentage);
    }
}


// Free dynamically allocated memory
void freeMatrix(int **matrix, int students)
{
    int i;

    for (i = 0; i < students; i++)
        free(matrix[i]);

    free(matrix);
}
