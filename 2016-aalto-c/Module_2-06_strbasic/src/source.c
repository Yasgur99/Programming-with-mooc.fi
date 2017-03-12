#include "source.h"
#include <ctype.h>
#include <string.h>

/* Count Alpha
 * Count number of alphabetic characters in the given string <str>,
 * and return the count
 */
int count_alpha(const char *str) {
    int num_alpha = 0;
    while (*str) {
        if (isalpha(*(str++)))
            num_alpha++;
    }
    return num_alpha;
}

/* Count Substring
 * Count number of occurances of substring <sub> in string <str>,
 * and return the count.
 */
int count_substr(const char *str, const char *sub) {
    int num_sub = 0;
    while (*str) {
        if (strstr((str), sub)) {
            str = strstr(str, sub) + strlen(sub);
            num_sub++;
        } else
            return num_sub;
    }
    return num_sub;
}


