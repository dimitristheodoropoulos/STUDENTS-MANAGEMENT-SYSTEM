#include <stdio.h>
#include <stdlib.h>
#include "studentsmarks.h"
#include "file_operations.h"

int main() {
    students = (Student *)malloc(INITIAL_SIZE * sizeof(Student));
    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    loadFromFile("students.txt");

    int option;
    char name[50];
    int grade;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Delete Student\n");
        printf("4. Search Student\n");
        printf("5. Sort Students\n");
        printf("6. Save to File\n");
        printf("7. Load from File\n");
        printf("8. Edit Student\n");
        printf("9. View Statistics\n");
        printf("10. Search by Grade Range\n");
        printf("11. Exit\n");
        printf("Choice: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("Enter student's name: ");
                scanf("%s", name);
                printf("Enter student's grade: ");
                scanf("%d", &grade);
                addStudent(name, grade);
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                printf("Enter student's name to delete: ");
                scanf("%s", name);
                deleteStudent(name);
                break;
            case 4:
                printf("Enter student's name to search: ");
                scanf("%s", name);
                searchStudent(name);
                break;
            case 5:
                printf("Choose sorting criteria (1 for name, 0 for grade): ");
                scanf("%d", &option);
                sortStudents(option);
                break;
            case 6:
                saveToFile("students.txt");
                break;
            case 7:
                loadFromFile("students.txt");
                break;
            case 8:
                printf("Enter student's name to edit: ");
                scanf("%s", name);
                editStudent(name);
                break;
            case 9:
                calculateStatistics();
                break;
            case 10:
                printf("Enter grade range (min max): ");
                int minGrade, maxGrade;
                scanf("%d %d", &minGrade, &maxGrade);
                searchByGradeRange(minGrade, maxGrade);
                break;
            case 11:
                saveToFile("students.txt");
                free(students);
                return 0;
            default:
                printf("Invalid option.\n");
                break;
        }
    }

    return 0;
}
