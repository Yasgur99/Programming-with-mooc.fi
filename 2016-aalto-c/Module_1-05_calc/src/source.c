#include <stdio.h>
#include <math.h>
#include "source.h"

void simple_sum(void) {
    int a, b;
    int ret_a = scanf("%d%d", &a, &b);
    printf("%d + %d = %d\n", a, b, a + b);
}

void simple_math(void) {
    float a, b;
    char operator;
    scanf("%f %c %f", &a, &operator, &b);

    switch (operator) {
        case '+':
            printf("%.1f\n", a + b);
            break;
        case '-':
            printf("%.1f\n", a - b);
            break;
        case '*':
            printf("%.1f\n", a * b);
            break;
        case '/':
            printf("%.1f\n", a / b);
            break;
        default:
            printf("ERR\n");
            break;
    }
}
