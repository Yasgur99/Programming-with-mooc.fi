#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <float.h>
#include "spreadsheet.h"

const struct {
    char *name;
    double (*fptr)(Sheet *, Point, Point);
} functions[] = {
    { "sum", sumfunc},
    { "max", maxfunc},
    { "count", countfunc},
    { NULL, NULL}
};

/* Creates a new spreadsheet with given dimensions.
 * Returns pointer to the allocated Sheet structure.
 */
Sheet *create_sheet(unsigned int xsize, unsigned int ysize) {
    Sheet* newSheet = malloc(sizeof (Sheet));
    if (!newSheet) return NULL;

    Cell** cells = malloc(ysize * sizeof (Cell*));
    if (!cells) {
        free(newSheet);
        return NULL;
    }

    for (unsigned int i = 0; i < ysize; i++) {
        cells[i] = malloc(xsize * sizeof (Cell));
        if (!cells[i]) {
            for (unsigned int j = 0; j < i; j++) {
                free(cells[j]);
            }
            free(cells);
            return NULL;
        }
    }

    for (unsigned int y = 0; y < ysize; y++)
        for (unsigned int x = 0; x < xsize; x++)
            cells[y][x].type = UNSPEC;

    newSheet->cells = cells;
    newSheet->xsize = xsize;
    newSheet->ysize = ysize;
    return newSheet;
}

/* Releases the memory allocated for sheet.
 */
void free_sheet(Sheet *sheet) {
    for (unsigned int y = 0; y < sheet->ysize; y++)
        free(sheet->cells[y]);
    free(sheet->cells);
    free(sheet);
}

/* Returns pointer to the Cell structure at given location <p>
 * in spreadsheet <sheet>.
 */
Cell *get_cell(Sheet *sheet, Point p) {
    if (sheet->ysize - 1 < p.y || sheet->xsize - 1 < p.x) return NULL;
    else return &sheet->cells[p.y][p.x];
}

/* Convert two-letter user input into coordinates of type Point.
 */
Point get_point(char xc, char yc) {
    Point p;
    p.x = toupper(xc) - 'A';
    p.y = toupper(yc) - 'A';
    return p;
}

/* Parses user input in <command> and applies it in spreadsheet <sheet>.
 * Returns 1 if input was valid, or 0 if it was not.
 */
int parse_command(Sheet *sheet, const char *command) {
    double val;
    Point p;
    char xc, yc;
    int ret = sscanf(command, "%c%c %lf", &xc, &yc, &val);
    if (ret == 3) {
        p = get_point(xc, yc);
        set_value(sheet, p, val);
        return 1;
    }

    char func[10];
    Point ul, dr;
    char xc1, yc1, xc2, yc2;

    ret = sscanf(command, "%c%c %9s %c%c %c%c", &xc, &yc, func, &xc1, &yc1, &xc2, &yc2);
    if (ret == 7) {
        p = get_point(xc, yc);
        ul = get_point(xc1, yc1);
        dr = get_point(xc2, yc2);
        int i = 0;
        while (functions[i].name) {
            if (!strcmp(functions[i].name, func)) {
                set_func(sheet, p, functions[i].fptr, ul, dr);
                return 1;
            }
            i++;
        }
    }
    return 0;
}

/* Prints the content of given spreadsheet.
 */
void print_sheet(Sheet *sheet) {
    printf("%-8c", ' ');
    for (unsigned int x = 0; x < sheet->xsize; x++) {
        printf("%-8c", 'A' + x);
    }
    fputs("\n", stdout);

    for (unsigned int y = 0; y < sheet->ysize; y++) {
        printf("%-8c", 'A' + y);
        for (unsigned int x = 0; x < sheet->xsize; x++) {
            Point p;
            p.x = x;
            p.y = y;
            Cell *c = get_cell(sheet, p);
            switch (c->type) {
                case VALUE:
                case FUNC:
                    printf("%-8.1f", eval_cell(sheet, p));
                    break;

                default:
                    printf("%-8c", '*');
                    break;
            }
        }
        fputs("\n", stdout);
    }
}

/* Set the content of location <p> in spreadsheet to constant <value>
 */
void set_value(Sheet *sheet, Point p, double value) {
    if (get_cell(sheet, p) != NULL) {
        get_cell(sheet, p)->type = VALUE;
        get_cell(sheet, p)->un.value = value;
    }
}

/* Set the content of location <p> in spreadsheet to given function.
 * <func> is pointer to the function. <ul> is the upper left corner and 
 * <dr> is the lower right corner of the area over which the function
 * is applied.
 */
void set_func(Sheet *sheet, Point p,
        double (*func)(Sheet *, Point, Point),
        Point ul, Point dr) {
    if (get_cell(sheet, p) != NULL) {

        get_cell(sheet, p)->type = FUNC;
        get_cell(sheet, p)->un.func.fptr = func;
        get_cell(sheet, p)->un.func.upleft = ul;
        get_cell(sheet, p)->un.func.downright = dr;
    }
}

/* Evaluate the content of cell at location <p>.
 * If cell is constant value, that is returned.
 * If cell contains function, the function is evaluated and its result returned.
 * If cell is unspecified or location out of bounds, NAN is returned.
 */
double eval_cell(Sheet *sheet, Point p) {
    if (!get_cell(sheet, p) || get_cell(sheet, p)->type == UNSPEC) return NAN;
    switch (get_cell(sheet, p)->type) {
        case VALUE: return get_cell(sheet, p)->un.value;
            break;
        case FUNC: return get_cell(sheet, p)->un.func.fptr(sheet, get_cell(sheet, p)->un.func.upleft, get_cell(sheet, p)->un.func.downright);
            break;
        case UNSPEC: return NAN;

    }
    return NAN;
}

/* Calculate the maximum value within area with upper left corner <ul>
 * and lower right corner <dl>, and return it.
 */
double maxfunc(Sheet *sheet, Point ul, Point dr) {
    double maxNum = 0;
    for (unsigned int i = ul.y; i  <= dr.y; i++) {
        for (unsigned int j = ul.x; j  <= dr.x; j++) {
            Point p = {j, i};
            if (eval_cell(sheet, p) > maxNum && eval_cell(sheet, p) != NAN)
                maxNum = eval_cell(sheet, p);
        }
    }
    return maxNum;
}

/* Calculate the sum of values within upper left corner <ul> and
 * lower right corner <dr>, and return the result.
 */
double sumfunc(Sheet *sheet, Point ul, Point dr) {
    double sum = 0;
    for (unsigned int i = ul.y; i <= dr.y; i++) {
        for (unsigned int j = ul.x; j  <= dr.x; j++) {
            Point p = {j, i};
            if (eval_cell(sheet, p) != NAN && eval_cell(sheet, p) > 0)
                sum += eval_cell(sheet, p);
        }
    }
    return sum;
}

/* Count the number of specified cells inside the area with upper left
 * corner <ul> and lower right corner <dr>.
 */
double countfunc(Sheet *sheet, Point ul, Point dr) {
    int count = 0;
    for (unsigned int i = ul.y; i <= dr.y; i++) {
        for (unsigned int j = ul.x; j <= dr.x; j++) {
            Point p = {j, i};
            if (get_cell(sheet, p)->type == VALUE || get_cell(sheet, p)->type == FUNC)
                count++;
        }
    }
    return count;
}
