#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "studentsmarks.h"
#include "student_utils.h"

// Ταξινόμηση μαθητών κατά όνομα
int compareByName(const void *a, const void *b) {
    return strcmp(((Student *)a)->name, ((Student *)b)->name);
}

// Ταξινόμηση μαθητών κατά βαθμό (Φθίνουσα)
int compareByGrade(const void *a, const void *b) {
    return ((Student *)b)->grade - ((Student *)a)->grade;
}

// Συνάρτηση για την ταξινόμηση των μαθητών
void sortStudents(int byName) {
    if (byName) {
        qsort(students, current_student_count, sizeof(Student), compareByName);
    } else {
        qsort(students, current_student_count, sizeof(Student), compareByGrade);
    }
    printf("Η λίστα μαθητών ταξινομήθηκε.\n");
}

// Φιλτράρισμα μαθητών με βαθμό >= gradeThreshold
void filterByGrade(int gradeThreshold) {
    printf("Μαθητές με βαθμό >= %d:\n", gradeThreshold);
    for (int i = 0; i < current_student_count; i++) {
        if (students[i].grade >= gradeThreshold) {
            printf("Μαθητής: %s, Βαθμός: %d\n", students[i].name, students[i].grade);
        }
    }
}
