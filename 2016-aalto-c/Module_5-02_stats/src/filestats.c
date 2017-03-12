#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "filestats.h"

/* Returns the line count in given file
 * 
 * Parameters:
 * filename: name of the file to be investigated.
 * 
 * Returns:
 * The number of lines in file. */
int line_count(const char *filename) {
    FILE* fp = fopen(filename, "r");
    if (!fp) return -1;

    int numOfLines = 0;
    char buffer;
    int flag =0;
    
    while ((buffer = fgetc(fp)) != EOF) {
        flag = 1;
        if(buffer == '\n' && flag){
            numOfLines++;
            flag =0;
        }
    }
    fclose(fp);
    if (flag) return numOfLines + 1;
    return numOfLines;
}

/* Count the number of words in the file. Word has to include at least one
 * alphabetic character, and words are separated by whitespace.
 * 
 * Parameters:
 * filename: name of the file to be investigated.
 * 
 * Returns:
 * number of words in the file */
int word_count(const char *filename) {
    FILE* fp = fopen(filename, "r");
    if (!fp) return -1;

    int numOfWords = 0;
    char currentChar;
    short flag = 0; //if it contains alpha character
    
    while ((currentChar = fgetc(fp)) != EOF) {
        if ((isspace(currentChar)) && flag > 0) {
            numOfWords++;
            flag = 0;
        }else if (isalpha(currentChar)) flag = 1;
    }

    fclose(fp);
    if (flag > 0) return numOfWords + 1;
    return numOfWords;
}
