#include <stdio.h>
#include <stdlib.h>
#include "ships.h"

const unsigned int xsize = 10;
const unsigned int ysize = 10;
const unsigned int shiplen = 3;

/* implement these functions */

/* Task a: Place <num> ships on the game map.
 */
void set_ships(unsigned int num) {
    (void) num;
    for (unsigned int i = 0; i < num;) {
        if (place_ship(rand() % 10, rand() % 10, rand() % 2))
            i++;
    }
}

/* Task b: print the game field
 */
void print_field(void) {
    for (unsigned int y = 0; y < ysize; y++) {
        for (unsigned int x = 0; x < xsize; x++) {
            if (is_visible(x, y))
                printf("%c", is_ship(x, y));
            else
                printf("?");

        }
        printf("\n");
    }
}

/* Task c: Ask coordinates (two integers) from user, and shoot the location.
 * Returns -1 if user gave invalid input or coordinates, 0 if there was no ship
 * at the given location; and 1 if there was a ship hit at the location.
 */
int shoot(void) {
    unsigned int x, y;
    int argumentsGood = scanf("%d%d", &x, &y);
    if(argumentsGood != 2)
        return -1;
    
    if (x >= xsize || y >= ysize)
        return -1;

    checked(x, y);
    if (is_ship(x, y) == '.')
        return 0;

    hit_ship(x, y);

    return 1;
}

/* Task d: Returns 1 if game is over (all ships are sunk), or 0 if there
 * still are locations that have not yet been hit. <num> is the number of
 * ships on the game map. It is assumed to be the same as in the call to
 * set_ships function.
 */
int game_over(unsigned int num) {
    (void) num;
    unsigned int points = 0;
    for (unsigned int y = 0; y < ysize; y++){
        for (unsigned int x = 0; x < xsize; x++){
            if (is_ship(x, y) == '#')
                points++;
        }
    }
        
    if (num * 3 <= points)
        return 1;
    else
        return 0;
}
