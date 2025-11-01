#include "polynome.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    Polynome p, out, deriv;

    if (input_polynome(&p) != 0) {
        printf("Error inputting polynome\n");
        return EXIT_FAILURE;
    }

    printf("Input polynome: ");
    output_polynome(&p);

    const char *filename = "polynome.dat";
    if (write_to_file(filename, &p) != 0) {
        printf("Error writing to file\n");
        free_polynome(&p);
        return EXIT_FAILURE;
    }

    out = read_from_file(filename);
    printf("Read from file: ");
    output_polynome(&out);

    deriv = derivative(&p);
    printf("Derivative: ");
    output_polynome(&deriv);

    if (append_to_file(filename, &deriv) != 0) {
        printf("Error appending to file\n");
    }

    free_polynome(&p);
    free_polynome(&out);
    free_polynome(&deriv);

    return EXIT_SUCCESS;
}