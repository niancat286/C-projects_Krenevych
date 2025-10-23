#ifndef C_PROJECTS_KRENEVYCH_POLYNOME_H
#define C_PROJECTS_KRENEVYCH_POLYNOME_H

#include <stdio.h>
#include <stdlib.h>

struct Polynome {
    size_t n;
    double* a;
};

extern int input_polynome(struct Polynome* p);
extern void output_polynome(const struct Polynome* p);

extern void free_polynome(struct Polynome* p);

#endif //C_PROJECTS_KRENEVYCH_POLYNOME_H