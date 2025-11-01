#ifndef C_PROJECTS_KRENEVYCH_TOYS_H
#define C_PROJECTS_KRENEVYCH_TOYS_H

#include <stddef.h>
# define Toy_name_LEN 50

typedef struct {
    char name[Toy_name_LEN + 1];
    double price;    /* в гривнях */
    int age_min;
    int age_max;
} Toy;

int load_names_from_file(const char *filename, Toy **arr, size_t *n);
int save_matches(const char *bin_filename, const Toy *arr, size_t n, const char *query_name);
void print_toy(const Toy *t);
void free_toy(Toy *arr);


#endif //C_PROJECTS_KRENEVYCH_TOYS_H