#include <stdio.h>
#include "source.h"


#ifndef MAWKKE
// longer solution by Pasi

/* 03-mastermind
 */
void mastermind(const int *solution, const int *guess, char *result, unsigned int len) {
    for (unsigned int i = 0; i < len; i++) {
        *(result + i) = '-'; // set all to negative 

        for (unsigned int j = 0; j < len; j++) // check if it exists elsewhere
            if (*(guess + i) == *(solution + j))
                *(result + i) = '*';
        
        if (*(solution + i) == *(guess + i)) // if its correct
            *(result + i) = '+';
    }
}
#endif
