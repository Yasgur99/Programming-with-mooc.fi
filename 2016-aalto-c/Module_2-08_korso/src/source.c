#include "source.h"
#include <string.h>
#include <stdio.h>

/* Korsoraattori
 */
void korsoroi(char *dest, const char *src) {
    int three_spaces = 0;
    int four_spaces = 0;
    while (*src) {
        if (*src == 'k' && *(src + 1) == 's') {
            *dest++ = 'x';
            src += 2;
        } else if (*src == 't' && *(src + 1) == 's') {
            *dest++ = 'z';
            src += 2;
        } else if (*src == ' ') {
            src++;
            three_spaces++;
            four_spaces++;
            *(dest++) = ' ';
            if (three_spaces == 3) {
                strcpy(dest, "niinku ");
                dest += 7;
                three_spaces = 0;
            } else if (four_spaces == 4) {
                strcpy(dest, "totanoin ");
                dest += 9;
                four_spaces = 0;
            }
        } else
            *dest++ = *src++;
    }
    *(dest) = '\0';
}
