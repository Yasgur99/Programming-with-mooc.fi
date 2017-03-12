#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int* join_arrays(unsigned int n1, int * arr1, unsigned int n2, int * arr2, unsigned int n3, int * arr3) {
    int* big_array = malloc((n1 + n2 + n3) * sizeof (int));
    if (!big_array)
        return NULL;

    memcpy(big_array, arr1, sizeof (int)*n1);
    memcpy(big_array+n1, arr2, sizeof (int)*n2);
    memcpy(big_array+n1+n2, arr3, sizeof (int)*n3);

    return big_array;
}