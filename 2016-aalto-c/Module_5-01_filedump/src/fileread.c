#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "fileread.h"

/* Prints the given file as text on the screen.
 * Only printable characters are shown. Non-printable characters are printed
 * as '?'. <filename> parameter is the name of the file.
 *
 * Returns the number of characters read
 */
int textdump(const char *filename) {\
    /*Open file*/
    FILE* fp = fopen(filename, "r");
    if (!fp) 
        return -1;

    char buffer;
    int charsRead = 0;

    while ((buffer = fgetc(fp)) != EOF) {
        if (isprint(buffer))
            fputc(buffer, stdout);
        else
            fputc('?', stdout);
        charsRead++;
    }
    fclose(fp);
    return charsRead;
}

/* Prints the given file as hexdump, at most 16 numbers per line.
 * <filename> parameter is the name of the file.
 * 
 * Returns the number of characters read
 */
int hexdump(const char *filename) {
    /*Open file*/
    FILE* fp = fopen(filename, "r");
    if (!fp) 
        return -1;
    
    int bytesRead = 0;
    int buffer;
    while ((buffer = fgetc(fp)) != EOF) {
        if (bytesRead != 0 && bytesRead % 16 == 0)
            printf("\n");
        printf("%02x ", buffer);
        bytesRead++;
    }
    fclose(fp);
    return bytesRead;
}
