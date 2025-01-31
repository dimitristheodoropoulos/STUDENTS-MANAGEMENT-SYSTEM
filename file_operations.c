#include <stdio.h>
#include "studentsmarks.h"

void saveToFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for saving.\n");
        return;
    }
    for (int i = 0; i < current_student_count; i++) {
        fprintf(file, "%s %d\n", students[i].name, students[i].grade);
    }
    fclose(file);
}

void loadFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for loading.\n");
        return;
    }
    char name[50];
    int grade;
    while (fscanf(file, "%s %d", name, &grade) != EOF) {
        addStudent(name, grade);
    }
    fclose(file);
}
