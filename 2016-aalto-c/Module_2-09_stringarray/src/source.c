#include "source.h"
#include <stddef.h>
#include <stdio.h>

/* Print string array, last element is NULL */

/* Parameters:
 * array: string array to be printed, each string on own line */
void print_strarray(char *array[]) {
    while (*array != NULL) {
        printf("%s\n", *array);
        array++;
    }
}

/* Put strings from string separated by space to a string array */

/* Parameters:
 * string: string to be cut into parts and placed into the array, 
   remember to add ending zeros '\0' for strings and NULL to the end of the whole array!
 * arr: ready-made array that the strings will be put into */
void str_to_strarray(char* string, char** arr) {
    int i = 0;
    int j = 0;
    while (*string) {
        if (*string == ' ') {
            arr[j][i] = '\0';
            j++;
            i = 0;
            string++;
        }
        arr[j][i++] = *string++;
    }
    arr[j][i] = '\0';
    arr[j+1] = NULL;
}
