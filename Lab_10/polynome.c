#include "polynome.h"

int input_polynome(struct Polynome* p) {
    printf("Input size :\n");
    scanf("%zu", &p->n);

    p->a = (double*)calloc(p->n, sizeof(double));
    if (!p->a) return EXIT_FAILURE;

    for (size_t i = 0; i < p->n; i++) {
        printf("a[%d]=", i);
        scanf("%lf", &p->a[i]);
    }
    return EXIT_SUCCESS;
}

void output_polynome(const struct Polynome* p) {
    if (!p) return;

    for (size_t i = p->n -1; i > 0; i--) {
        printf("%lf*x^%zu+", p->a[i], i);
    }
    printf("%lf\n", p->a[0]);
}

void free_polynome(struct Polynome* p) {
    if (p && p->a) free(p->a);
}