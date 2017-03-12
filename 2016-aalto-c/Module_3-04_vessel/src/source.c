#include "source.h"
#include <stddef.h>
#include <string.h>
#include <stdio.h>

struct vessel create_vessel(const char *p_name,
        double p_length,
        double p_depth,
        struct cargo p_crg) {
   
    struct vessel ship;
    strncpy(ship.name,p_name,30);
    ship.name[30] = '\0';
    
    ship.length = p_length;
    ship.depth = p_depth;
    ship.crg = p_crg;
    
    return ship;
}

void print_vessel(const struct vessel *ship) {
    printf("%s\n%.1f\n%.1f\n", ship->name, ship->length,ship->depth);
    printf("%s\n%d\n%.1f\n",ship->crg.title,ship->crg.quantity,ship->crg.weight);
}
