#include "source.h"


/* Selective sort */

/* Parameters:
 * start: start of an array
 * size: length of an array
 */
void sort(int *start, int size) {
    int temp;
    for (int i = 0; i < size; i++) {
        for(int j=0;j<size;j++){
            if(*(start + j) > *(start + i)){
                temp = *(start +i);
                *(start + i) = *(start +j);
                *(start +j) = temp;
            }
        }
    }
}

