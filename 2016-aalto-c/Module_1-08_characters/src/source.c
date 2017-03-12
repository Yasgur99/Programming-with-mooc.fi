#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "source.h"

/* Don't touch the definition of msgs array! Checker uses this. */
char *msgs[10] = {
    "'6=*w+~)._", "J65+~5+~=0/*69,~+9;,9*~19++=79"
};

void ascii_chart(char min, char max) {
    int counter = 1;
    for (int i = min; i <= max; i++) {
        if (isprint(i))
            printf("%3d 0x%x %c", i, i, i);
        else
            printf("%3d 0x%x ?", i, i);
        if (counter++ % 4 == 0)
            printf("\n");
        else
            printf("\t");
    }
}

char get_character(int msg, unsigned int cc) {
    if (msg >= 10 || !msgs[msg])
        return 0;

    if (strlen(msgs[msg]) <= cc)
        return 0;

    return msgs[msg][cc];
}

void secret_msg(int msg) {
    for (int i = 0;; i++) {
        if (get_character(msg, i) == 0) {
            break;
        }
        printf("%c", 158 - get_character(msg,i));
    }
}
