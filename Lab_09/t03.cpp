#include <stdio.h>
#include <stdlib.h>

double* create_vector(unsigned n) {
    double* vec = (double*)malloc(n * sizeof(double));
    if (!vec) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    for (unsigned i = 0; i < n; i++) {
        printf("vec[%u] = ", i);
        if (scanf("%lf", &vec[i]) != 1) {
            printf("Invalid input!\n");
            free(vec);
            return NULL;
        }
    }
    return vec;
}

void free_vector(double* vec) {
    free(vec);
}

double* vector_difference(const double* a, const double* b, unsigned n1, unsigned n2) {
    if (n1 != n2) {
        printf("Error: Vectors must have the same dimension!\n");
        return NULL;
    }

    double* diff = (double*)malloc(n1 * sizeof(double));
    if (!diff) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    for (unsigned i = 0; i < n1; i++) {
        diff[i] = a[i] - b[i];
    }
    return diff;
}


void print_vector(const double* vec, unsigned n) {
    printf("[");
    for (unsigned i = 0; i < n; i++) {
        printf("%lf", vec[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    unsigned n1, n2;

    printf("Enter dimension of first vector: ");
    scanf("%u", &n1);
    double* v1 = create_vector(n1);
    if (!v1) return 1;

    printf("Enter dimension of second vector: ");
    scanf("%u", &n2);
    double* v2 = create_vector(n2);
    if (!v2) {
        free_vector(v1);
        return 1;
    }

    double* diff = vector_difference(v1, v2, n1, n2);
    if (diff) {
        printf("Difference vector: ");
        print_vector(diff, n1);
        free_vector(diff);
    }


    free_vector(v1);
    free_vector(v2);

    return 0;
}