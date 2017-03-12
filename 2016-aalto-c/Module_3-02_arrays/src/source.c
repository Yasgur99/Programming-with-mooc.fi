#include <stdlib.h>
#include <stdio.h>
#include "source.h"


/* Dynamic Array Reader */

/* Parameters:
 * n: Number of values to be read
 * 
 * Returns: pointer to the dynamically allocated array
 */
int *dyn_reader(unsigned int n) {
    int* array = malloc(n * sizeof (int));
    if (!array)
        return NULL;
    else {
        unsigned int num_read = 0;
        printf("Enter %u integers so they can be put into this array\n", n);
        while (num_read < n) {
            num_read += scanf("%d", array + num_read);
        }
    }
    return array;
}

/* Add to array */

/* Parameters:
 * arr: Existing array of integers
 * num: number of integers in the array before the call
 * newval: new value to be added
 * 
 * Returns: pointer to the allocated array
 */
int *add_to_array(int *arr, unsigned int num, int newval) {
    int* newarray = realloc(arr, (num+1) * sizeof (int)); //allocate one more space
    if (newarray == NULL) //Return original array if failed to allocate
        return arr;
    
    //free(arr); //free old array -- this throws an error when i try and free up the old array
    newarray[num] = newval;
    return newarray;
}
