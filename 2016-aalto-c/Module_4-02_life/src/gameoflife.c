#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "gameoflife.h"
 
/* Exercise a: Allocates needed memory for the field structure and
 * the actual game field. 'xsize' and 'ysize' indicate the horizontal and
 * vertical dimensions of the field.
 *
 * Returns: pointer to the Field structure allocated by this function.
 */
State** createCells(unsigned int xsize, unsigned int ysize) {
    State** state;
    state = malloc(ysize * sizeof (State*));
    if (!state) return NULL;
    /*create memory for columns at each row entry*/
    for (unsigned int i = 0; i < ysize; i++) {
        state[i] = malloc(xsize * sizeof (State));
        /*free allocated memory if something fails*/
        if (!state[i]) {
            for (unsigned int j = 0; j < i; j++)
                free(state[j]);
            free(state);
            return NULL;
        }
    }
     /*set cells to dead so valgrind doesnt say that unitialized value was created by a heap allocation*/
    for(unsigned int i=0;i<ysize;i++)
        for(unsigned int j=0;j<xsize;j++)
            state[i][j] = DEAD;
    return state;
}
 
Field *createField(unsigned int xsize, unsigned int ysize) {
    /*create rows (allocate pointers to arrays)*/
    Field* field = malloc(sizeof (Field));
    if(!field) return NULL;
     
    State** cells = createCells(xsize, ysize);
    if (!cells){
        free(field);
        return NULL;
    }
     
    field->xsize = xsize;
    field->ysize = ysize;
    field->cells = cells;
    return field;
}

/* Free memory allocated for field <f>.
 */
void releaseField(Field *f) {
    for (unsigned int i = 0; i < f->ysize; i++)
        free(f->cells[i]);
    free(f->cells);
    free(f);
}

/* Exercise b: Initialize game field by setting exactly <n> cells into
 * ALIVE state in the game field <f>.
 */
void initField(Field *f, unsigned int n) {
    if (!f) return;
    unsigned int counter = 0;
    unsigned int randX;
    unsigned int randY;

    for (unsigned int i = 0; i < f->ysize; i++)
        for (unsigned int j = 0; j < f->xsize; j++)
            f->cells[i][j] = DEAD;

    while (counter < n) {
        randX = rand() % f->xsize;
        randY = rand() % f->ysize;
        if (f->cells[randY][randX] == DEAD) {
            f->cells[randY][randX] = ALIVE;
            counter++;
        }
    }
}

/* Exercise c: Output the current state of field <f>.
 */
void printField(const Field *f) {
    for (unsigned int i = 0; i < f->ysize; i++) {
        for (unsigned int j = 0; j < f->xsize; j++) {
            if (f->cells[i][j])
                printf("%c", '*');
            else
                printf("%c", '.');
        }
        printf("\n");
    }
}

/* Exercise d: Advance field <f> by one generation.
 */
void tick(Field *f) {
    State** new_cells = createCells(f->xsize, f->ysize);
    if (!new_cells) return;

    for (unsigned int i = 0; i < f->ysize; i++) {
        for (unsigned int j = 0; j < f->xsize; j++) {
            unsigned int neighbors = 0;
            if (i != f->ysize - 1) {
                if (f->cells[i + 1][j] == ALIVE)
                    neighbors++;
            }
            if (i != 0) {
                if (f->cells[i - 1][j] == ALIVE)
                    neighbors++;
            }
            if (j != f->xsize - 1) {
                if (f->cells[i][j + 1] == ALIVE)
                    neighbors++;
            }
            if (j != 0) {
                if (f->cells[i][j - 1] == ALIVE)
                    neighbors++;
            }
            if (j != 0 && i != 0)
                if (f->cells[i - 1][j - 1] == ALIVE)
                    neighbors++;
            if (j != 0 && i != f->ysize - 1)
                if (f->cells[i + 1][j - 1] == ALIVE)
                    neighbors++;
            if (j != f->xsize - 1 && i != 0)
                if (f->cells[i - 1][j + 1] == ALIVE)
                    neighbors++;
            if (j != f->xsize - 1 && i != f->ysize - 1)
                if (f->cells[i + 1][j + 1] == ALIVE)
                    neighbors++;

            if (neighbors < 2 || neighbors > 3)
                new_cells[i][j] = DEAD;
            else if (neighbors == 3 || (neighbors == 2 && f->cells[i][j] == ALIVE))
                new_cells[i][j] = ALIVE;
        }
    }
    for (unsigned int i = 0; i < f->ysize; i++)
        free(f->cells[i]);
    free(f->cells);
    f->cells = new_cells;
}
