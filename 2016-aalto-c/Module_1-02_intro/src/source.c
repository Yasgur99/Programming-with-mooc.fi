#include <stdio.h>
#include <math.h>
#include "source.h"

void three_lines(void) {
    printf("January\nFebruary\nMarch\n");
}

void fix_types(void) {
    float a1 = 2.1;
    float a2 = 3.2;
    float result_a = a1 + a2;

    char b1 = 100;
    long b2 = 80000;
    long result_b = b1 * b2;

    float c1 = 100000;
    float c2 = 1.5;
    int result_c = c1 / c2;


    // Do not change the following line
    printf("%.1f  %d  %d\n", result_a, result_b, result_c);
}
