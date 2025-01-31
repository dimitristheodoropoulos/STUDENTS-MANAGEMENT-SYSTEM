#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "studentsmarks.h"

// Initialize global variables
Student *students = NULL;
int current_student_count = 0;
int max_students = INITIAL_SIZE;

// Resize the student list (double the size)
void resizeStudentList() {
    max_students *= 2;
    students = realloc(students, max_students * sizeof(Student));
    if (students == NULL) {
        printf("Memory allocation error!\n");
        exit(1);
    }
}

// Add a new student
void addStudent(char name[], int grade) {
    if (strlen(name) >= 50) {
        printf("Error: Name too long. Maximum allowed length is 49 characters.\n");
        return;
    }
    if (grade < 0 || grade > 20) {
        printf("Error: Grade must be between 0 and 20.\n");
        return;
    }

    if (current_student_count == max_students) {
        resizeStudentList();
    }
    strcpy(students[current_student_count].name, name);
    students[current_student_count].grade = grade;
    current_student_count++;
}

// Display all students
void displayStudents() {
    if (current_student_count == 0) {
        printf("No students available.\n");
        return;
    }
    printf("\nStudent List:\n");
    for (int i = 0; i < current_student_count; i++) {
        printf("Name: %s, Grade: %d\n", students[i].name, students[i].grade);
    }
}

// Delete a student by name
void deleteStudent(char name[]) {
    int found = 0;
    for (int i = 0; i < current_student_count; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("Found student '%s' at index %d. Deleting...\n", name, i);
            found = 1;
            for (int j = i; j < current_student_count - 1; j++) {
                students[j] = students[j + 1];
            }
            current_student_count--;
            printf("Student '%s' deleted. Current count: %d\n", name, current_student_count);
            //break;
            return;
        }
    }
    if (!found) {
        printf("Student %s not found.\n", name);
    }
}

// Other functions (e.g., searchStudent, editStudent, etc.) remain unchanged.
