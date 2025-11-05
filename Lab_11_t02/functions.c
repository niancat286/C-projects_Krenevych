#include "functions.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>



void filter_file(const char *fileF, const char *fileG, double a) {
    FILE *f = fopen(fileF, "r");
    FILE *g = fopen(fileG, "w");

    if (!f || !g) {
        printf("Error opening file!\n");
        exit(1);
    }

    double x;
    // write down into G all |x| < a
    while (fscanf(f, "%lf", &x) == 1) {
        if (fabs(x) < a) {
            fprintf(g, "%lf\n", x);
        }
    }

    fclose(g);
    rewind(f); // return on the beginning

    // rewrite F (temp file)
    FILE *tmp = fopen("temp.txt", "w");
    if (!tmp) {
        printf("Error opening temp file!\n");
        exit(1);
    }

    while (fscanf(f, "%lf", &x) == 1) {
        if (fabs(x) >= a) {
            fprintf(tmp, "%lf\n", x);
        }
    }

    fclose(f);
    fclose(tmp);

    // rewrite temp in F
    tmp = fopen("temp.txt", "r");
    f = fopen(fileF, "w");
    while (fscanf(tmp, "%lf", &x) == 1) {
        fprintf(f, "%lf\n", x);
    }

    fclose(tmp);
    fclose(f);

    remove("temp.txt");
}
