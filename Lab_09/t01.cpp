#include <stdio.h>
#include <stdlib.h>

int input_arr(double* arr, unsigned n);
double sum_sqr(const double* arr, unsigned n);

int main() {
    unsigned n;
    double* arr;

    printf("n = ");
    if (scanf("%u", &n) != 1 || n == 0) {
        printf("Invalid n\n");
        return 1;
    }

    arr = (double*)malloc(n * sizeof(*arr));
    if (!arr) {
        printf("Memory allocation error\n");
        return 1;
    }

    int k = input_arr(arr, n);
    if (k < (int)n) {
        printf("Only %d elements were entered\n", k);
    }

    printf("\nNorma is %lf\n", sum_sqr(arr, k));

    free(arr);
    return 0;
}

int input_arr(double* arr, unsigned n) {
    int k = 0;
    for (unsigned i = 0; i < n; i++) {
        printf("a[%u] = ", i);
        if (scanf("%lf", &arr[i]) != 1) {
            break;
        }
        k++;
    }
    return k;
}

double sum_sqr(const double* arr, unsigned n) {
    double total = 0;
    for (unsigned i = 0; i < n; i++) {
        total += arr[i] * arr[i];
    }
    return total;
}