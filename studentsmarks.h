#ifndef STUDENTSMARKS_H
#define STUDENTSMARKS_H

#define INITIAL_SIZE 2  // Default size of the student list

// Structure to hold student details
typedef struct {
    char name[50];
    int grade;
} Student;

extern Student *students;          // Pointer to array of students
extern int current_student_count;  // Total number of students
extern int max_students;           // Maximum students in memory

// Function declarations
void addStudent(char name[], int grade);
void displayStudents();
void deleteStudent(char name[]);
void searchStudent(char name[]);
void saveToFile(const char *filename);
void loadFromFile(const char *filename);
void resizeStudentList();
void sortStudents(int byName);
void filterByGrade(int gradeThreshold);
void editStudent(char name[]);
void searchByGradeRange(int minGrade, int maxGrade);
void calculateStatistics();

#endif // STUDENTSMARKS_H
