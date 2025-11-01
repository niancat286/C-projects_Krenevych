#include "polynome.h"
#include <stdlib.h>

int input_polynome(Polynome* p) {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    if (n <= 0) return -1;

    p->n = n;
    p->mon = (Monome*)calloc(n, sizeof(Monome));
    if (p->mon == NULL) return -1;

    for (int i = 0; i < n; i++) {
        printf("Degree: ");
        scanf("%d", &p->mon[i].degree);

        printf("a= ");
        scanf("%lf", &p->mon[i].a);
    }
    return 0;
}

void output_polynome(const Polynome* p) {
    if (p == NULL || p->mon == NULL) return;

    for (int i = 0; i < p->n; i++) {
        if (p->mon[i].a >= 0)
            printf("+%lf * x^%d", p->mon[i].a, p->mon[i].degree);
        else
            printf("%lf * x^%d", p->mon[i].a, p->mon[i].degree);
    }
    printf("\n");
}

void free_polynome(Polynome* p) {
    if (p != NULL && p->mon != NULL) {
        free(p->mon);
        p->mon = NULL;
        p->n = 0;
    }
}

Polynome read_from_file(const char* filename) {
    Polynome p = {0, NULL};
    FILE* file = fopen(filename, "rb");
    if (file == NULL) return p;

    int m = 0;
    if (fread(&m, sizeof(m), 1, file) != 1) {
        fclose(file);
        return p;
    }

    p.n = m;
    p.mon = (Monome*)calloc(m, sizeof(Monome));
    if (p.mon == NULL) {
        fclose(file);
        p.n = 0;
        return p;
    }

    for (int i = 0; i < m; i++) {
        if (fread(&p.mon[i], sizeof(Monome), 1, file) != 1) {
            free(p.mon);
            p.mon = NULL;
            p.n = 0;
            break;
        }
    }
    fclose(file);
    return p;
}

int write_to_file(const char *filename, const Polynome* p) {
    if (p == NULL) return -1;

    FILE* file = fopen(filename, "wb");
    if (file == NULL) return -1;

    int res1 = fwrite(&p->n, sizeof(p->n), 1, file);
    if (res1 < 1) {
        fclose(file);
        return -2;
    }

    int res2 = fwrite(p->mon, sizeof(Monome), p->n, file);
    fclose(file);

    return (res2 == p->n) ? 0 : -3;
}

// Реалізації функцій, які були оголошені, але не реалізовані
Polynome derivative(const Polynome* p) {
    Polynome result = {0, NULL};
    if (p == NULL || p->mon == NULL) return result;

    // Знаходимо кількість ненульових похідних
    int count = 0;
    for (int i = 0; i < p->n; i++) {
        if (p->mon[i].degree != 0) count++;
    }

    if (count == 0) return result;

    result.n = count;
    result.mon = (Monome*)calloc(count, sizeof(Monome));
    if (result.mon == NULL) {
        result.n = 0;
        return result;
    }

    int idx = 0;
    for (int i = 0; i < p->n; i++) {
        if (p->mon[i].degree != 0) {
            result.mon[idx].degree = p->mon[i].degree - 1;
            result.mon[idx].a = p->mon[i].a * p->mon[i].degree;
            idx++;
        }
    }

    return result;
}

int append_to_file(const char* fname, const Polynome* p) {
    if (p == NULL) return -1;

    FILE* file = fopen(fname, "ab");
    if (file == NULL) return -1;

    int res1 = fwrite(&p->n, sizeof(p->n), 1, file);
    if (res1 < 1) {
        fclose(file);
        return -2;
    }

    int res2 = fwrite(p->mon, sizeof(Monome), p->n, file);
    fclose(file);

    return (res2 == p->n) ? 0 : -3;
}

int replace_in_file(const char* fname, const Polynome* p) {
    return write_to_file(fname, p);
}