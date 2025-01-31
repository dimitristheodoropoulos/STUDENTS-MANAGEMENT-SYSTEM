#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "studentsmarks.h"
#include <stdlib.h>

//Student *students;

// Test Setup: Initialize global variables
int test_setup(void) {
    students = malloc(INITIAL_SIZE * sizeof(Student));
    if (students == NULL) {
        printf("Memory allocation failed!\n");
        //exit(1);
        return 1;// Return non-zero to indicate failure
    }
    current_student_count = 0;
    max_students = INITIAL_SIZE;
    printf("Test setup initialized successfully.\n");
    return 0; // Return 0 to indicate success
}

// Test Teardown: Free global memory
int test_teardown(void) {
    printf("Cleaning up memory...\n");
    if(students!=NULL){
    free(students);
    students = NULL;
}
current_student_count = 0;
max_students = 0;
return 0; // Return 0 to indicate success
}
// Test case for adding a student
void test_add_student() {
    addStudent("Alice", 15);
    CU_ASSERT_EQUAL(current_student_count, 1);
    CU_ASSERT_STRING_EQUAL(students[0].name, "Alice");
    CU_ASSERT_EQUAL(students[0].grade, 15);
}

// Test case for deleting a student
void test_delete_student() {
     current_student_count = 0;  // Reset the student count
    max_students = INITIAL_SIZE;  // Reset maximum size

    // Add Bob, then delete him
    addStudent("Bob", 18);
    deleteStudent("Bob");
    CU_ASSERT_EQUAL(current_student_count, 0);
}

// Main function to run the tests
int main() {
    if (CU_initialize_registry() != CUE_SUCCESS) {
        return CU_get_error();
    }

    CU_pSuite pSuite = CU_add_suite("Student Management Tests", test_setup, test_teardown);
    if (pSuite == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_add_test(pSuite, "test_add_student", test_add_student);
    CU_add_test(pSuite, "test_delete_student", test_delete_student);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
