#include <stdio.h>
#include <math.h>
#include "source.h"

void multi_table(unsigned int xsize, unsigned int ysize) {
    for(int i=1;i<=ysize;i++){
        for(int j=1;j<=xsize;j++){
            printf("%4d", i * j);
        }
        printf("\n");
    }
}

void draw_triangle(unsigned int size) {
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(i < size -j - 1)
                printf(".");
            else
                printf("#");
        }
        printf("\n");
    }
}

double distance(int x, int y, int radius) {
    return sqrt((x-radius)*(x-radius) + (y-radius)*(y-radius));
}

void draw_ball(unsigned int radius) {
    for(int i=0;i<2 * radius + 1;i++){
        for(int j=0;j<radius*2 + 1;j++){
            if(distance(j,i, radius) <= radius){
                printf("*");
            }else
                printf(".");
        }
        printf("\n");
    }
}
