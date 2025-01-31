#ifndef STUDENT_UTILS_H
#define STUDENT_UTILS_H

// Δηλώσεις συναρτήσεων σύγκρισης για ταξινόμηση
extern int compareByName(const void *a, const void *b);
extern int compareByGrade(const void *a, const void *b);

// Δηλώσεις άλλων συναρτήσεων
extern void sortStudents(int byName);
extern void filterByGrade(int gradeThreshold);

#endif // STUDENT_UTILS_H
