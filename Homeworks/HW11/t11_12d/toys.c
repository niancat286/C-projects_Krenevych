#include "toys.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int load_names_from_file(const char *filename, Toy **arr, size_t *n) {
    if (!filename || !arr || !n) return -1;
    FILE *f = fopen(filename, "r");
    if (!f) return -1;


    size_t cap = 16;
    Toy *data = malloc(cap * sizeof(Toy));
    if (!data) { fclose(f); return -1; }
    size_t count = 0;


    while (1) {
        char name_buf[Toy_name_LEN + 2];
        double price;
        int amin, amax;

        int r = fscanf(f, "%50s %lf %d %d", name_buf, &price, &amin, &amax);
        if (r == EOF) break;
        if (r != 4) {
            /* skip fail line */
            int c;
            while ((c = fgetc(f)) != '\n' && c != EOF) ;
            continue;
        }

        if (count >= cap) {
            size_t newcap = cap * 2;
            Toy *tmp = realloc(data, newcap * sizeof(Toy));
            if (!tmp) { free(data); fclose(f); return -1; }
            data = tmp;
            cap = newcap;
        }

        strncpy(data[count].name, name_buf, Toy_name_LEN);
        data[count].name[Toy_name_LEN] = '\0';
        data[count].price = price;
        data[count].age_min = amin;
        data[count].age_max = amax;
        count++;
    }

    fclose(f);
    *arr = data;
    *n = count;
    return 0;
}


void print_toy(const Toy *t) {
    if (!t) return;
    printf("Name: %s\tPrice: %.2f UAH\tAge: %d-%d\n", t->name, t->price, t->age_min, t->age_max);
}

int save_matches(const char *bin_filename, const Toy *arr, size_t n, const char *query_name) {
    if (!bin_filename || !arr || !query_name) return -1;
    FILE *bf = fopen(bin_filename, "wb");
    if (!bf) {
        return -1;
    }

    int found = 0;
    for (size_t i = 0; i < n; ++i) {
        if (strcmp(arr[i].name, query_name) == 0) {
            /* write into bin file */
            if (fwrite(&arr[i], sizeof(Toy), 1, bf) != 1) {
                fclose(bf);
                return -1;
            }
            /* i for console */
            print_toy(&arr[i]);
            found++;
        }
    }

    fclose(bf);
    return found; /* 0 or numbers of matched */
}

void free_toy(Toy *arr) {
    free(arr);
}