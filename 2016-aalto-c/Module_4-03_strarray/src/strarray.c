#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "strarray.h"

/* Exercise a: Initializes the string array to contain the initial
 * NULL pointer, but nothing else.
 * Returns: pointer to the array of strings that has one element
 *      (that contains NULL)
 */
char **init_array(void) {
    /*allocate for one pointer to an array of chars*/
    char** strarr = malloc(sizeof (char*));
    if (!strarr) return NULL;
    strarr[0] = NULL;
    return strarr;
}

int getNumOfElements(char** array) {
    int n = 0;
    while (*(n + array)) {
        n++;
    }
    return n;
}

/* Releases the memory used by the strings.
 */
void free_strings(char **array) {
    int counter = 0;
    while (array[counter])
        free(array[counter++]);
    free(array[counter++]);
    free(array);
}

/* Exercise b: Add <string> to the end of array <array>.
 * Returns: pointer to the array after the string has been added.
 */
char **add_string(char **array, const char *string) {
    int numElements = getNumOfElements(array);
    char** newArray = realloc(array, (numElements + 2) * sizeof (char*));
    if (!newArray) return array;

    char* newString = malloc((strlen(string)+1) * sizeof (char));
    if (!newString) return newArray;

    strncpy(newString, string, strlen(string)+1);

    newArray[numElements] = newString;
    newArray[numElements + 1] = NULL;
    return newArray;
}

/* Exercise c: Convert letters of all strings in <array> to lower case.
 */
void make_lower(char **array) {
    int i = 0;
    while (array[i]) {
        int j = 0;
        while (array[i][j]) {
            array[i][j] = tolower(array[i][j]);
            j++;
        }
        i++;
    }
}



/* Exercise d: reorder strings in <array> to lexicographical order */
void sort_strings(char **array)
{
  int size = getNumOfElements(array);
  for(int i = 0; i < size; i++) {
    int j_min = i;
    for(int j = i + 1; j < size; j++) {
      if(strcmp(array[j], array[j_min]) < 0) j_min = j;
    }
    if(j_min != i) {
      char *tmp = array[i];
      array[i] = array[j_min];
      array[j_min] = tmp;
    }
  }
}

/* You can use this function to check what your array looks like.
 */
void print_strings(char **array) {
    if (!array)
        return;
    while (*array) {
        printf("%s  ", *array);
        array++;
    }
    printf("\n");
}
