#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include "oodi.h"

/* Exercise a: Initialize student record
 * 
 * Parameters:
 * or: Oodi record to be changed (does not need to be allocated)
 * p_student, p_course, p_grade, p_compdate: Values for different structure
 *      fields (must be copied)
 * 
 * Returns: 1 if initialization was succesful, 0 if it failed
 * If student ID is more than 6 characters, initialization fails.
 * 
 * -- Note that structure contains enough space for student ID, but not for
 * course name
 * -- Remember to check that reserved space is not overwritten
 */
int init_record(struct oodi *or, const char *p_student, const char *p_course,
        unsigned char p_grade, struct date p_date) {

    //check to make sure valid ID
    if (strlen(p_student) > 6) return 0;

    //copy over p_student to or student and terminate with null byte
    strncpy(or->student, p_student, 6);
    or->student[6] = '\0';

    //allocate memory for course and set or course
    or->course = malloc(sizeof (char)*(1 + strlen(p_course)));
    if (!or->course)
        return 0;
    strncpy(or->course, p_course, strlen(p_course) + 1);
    //set or grade and date
    or->grade = p_grade;
    or->compdate = p_date;

    //return true that init was completed
    return 1;
}

/* Exercise b: Add a new record to a dynamic array.
 * (Resize the array as needed). All content of the new structure is copied.
 * 
 * Parameters:
 * array: start of an dynamic array (may be NULL, if array is empty)
 * length: current length of the array (number of entries)
 * newrec: new record to be added, all fields need to be copied.
 * 
 * Returns: pointer to the array after adding the new item
 */
struct oodi *add_record(struct oodi *array, unsigned int length, struct oodi newrec) {
    //realocate memory on heap for the array
    struct oodi* newArray = realloc(array, (length + 1) * sizeof (struct oodi));
    if (!newArray)
        return array;

    init_record(newArray + length, newrec.student, newrec.course, newrec.grade, newrec.compdate);
    return newArray;
}

/* Exercise c: Change grade and date in existing record.
 * 
 * Parameters:
 * array: beginning of array
 * size: size of array
 * student: student ID to be changed
 * course: course to be changed
 * newgrade: new value for grade
 * newdate: new value for date
 * 
 * Returns: number of entries changed, i.e. either 1 or 0
 */
int change_grade(struct oodi *array, unsigned int size, const char *p_student,
        const char *p_course, unsigned char newgrade, struct date newdate) {
    for (unsigned int i = 0; i < size; i++) {
        if (!strcmp(p_student, array[i].student) && !strcmp(p_course, array[i].course)) {
            array[i].grade = newgrade;
            array[i].compdate = newdate;
            return 1;
        }
    }
    return 0;
}

/* Exercise d: Delete array (and all memory allocated for it)
 * 
 * Parameters:
 * array: beginning of the array
 * 
 * Returns: 1 when array is deleted
 */
int delete_array(struct oodi *array, unsigned int size) {
    //free course string in array
    for (unsigned int i = 0; i < size; i++) {
        free(array[i].course);
    }

    //free the struct array
    free(array);
    return 1;
}

void print_array(struct oodi *array, unsigned int size) {
    for (unsigned int i = 0; i < size; i++) {
        printf("student: %s\n", array[i].student);
        printf("course: %s\n", array[i].course);
        printf("grade: %hhu\n", array[i].grade);
    }
}