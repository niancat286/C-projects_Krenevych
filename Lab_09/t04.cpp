#include <stdio.h>
#include <stdlib.h>


// Створити n x n матрицю, заповнену нулями
double **create_zero_matrix_ptr(int n) {
    double **A = (double**) malloc(n * sizeof(double *));
    if (!A) {
        fprintf(stderr, "Помилка виділення пам'яті (A pointers)\n");
        return NULL;
    }
    for (int i = 0; i < n; ++i) {
        A[i] = (double*) calloc(n, sizeof(double)); // явний каст
        if (!A[i]) {
            fprintf(stderr, "Помилка виділення пам'яті (A[%d])\n", i);
            for (int j = 0; j < i; ++j) free(A[j]);
            free(A);
            return NULL;
        }
    }
    return A;
}

// Зчитати n x n матрицю з консолі (впорядковано рядок за рядком)
void input_matrix_ptr(double **A, int n) {
    printf("Введіть %d x %d елементів матриці (рядок за рядком):\n", n, n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%lf", &A[i][j]);
}

// Вивести матрицю формату double **
void print_matrix_ptr(double **A, int n, const char *title) {
    printf("%s\n", title);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            printf("%10.4lf ", A[i][j]);
        printf("\n");
    }
}

// Звільнити пам'ять
void free_matrix_ptr(double **A, int n) {
    if (!A) return;
    for (int i = 0; i < n; ++i) free(A[i]);
    free(A);
}

// Множення матриць A * B
double **multiply_ptr(double **A, double **B, int n) {
    double **C = create_zero_matrix_ptr(n);
    if (!C) return NULL;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            double sum = 0.0;
            for (int k = 0; k < n; ++k)
                sum += A[i][k] * B[k][j];
            C[i][j] = sum;
        }
    return C;
}


// Створити n*n лінійний масив, ініціалізований нулями
double *create_zero_matrix_lin(int n) {
    double *A = (double*) calloc((size_t)n * n, sizeof(double));
    if (!A) {
        fprintf(stderr, "Помилка виділення пам'яті (linear)\n");
        return NULL;
    }
    return A;
}

// Індекс в лінійному масиві для (i,j)
static inline size_t idx(int i, int j, int n) {
    return (size_t)i * n + j;
}

// Зчитати матрицю у лінійний масив
void input_matrix_lin(double *A, int n) {
    printf("Введіть %d x %d елементів матриці (рядок за рядком):\n", n, n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%lf", &A[idx(i,j,n)]);
}

// Вивід лінійної матриці
void print_matrix_lin(double *A, int n, const char *title) {
    printf("%s\n", title);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            printf("%10.4lf ", A[idx(i,j,n)]);
        printf("\n");
    }
}

// Звільнення лінійної матриці
void free_matrix_lin(double *A) {
    free(A);
}

// Множення лінійних матриць A * B
double *multiply_lin(double *A, double *B, int n) {
    double *C = create_zero_matrix_lin(n);
    if (!C) return NULL;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            double sum = 0.0;
            for (int k = 0; k < n; ++k)
                sum += A[idx(i,k,n)] * B[idx(k,j,n)];
            C[idx(i,j,n)] = sum;
        }
    return C;
}

int main() {
    int n;

    printf("Введіть порядок квадратних матриць n: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Некоректне значення n\n");
        return 1;
    }

    /* ----- Варіант 1 ----- */
    printf("\n=== Подання через double ** (масив вказівників) ===\n");
    double **A1 = create_zero_matrix_ptr(n);
    double **B1 = create_zero_matrix_ptr(n);
    if (!A1 || !B1) { free_matrix_ptr(A1,n); free_matrix_ptr(B1,n); return 1; }

    printf("\nВводьте першу матрицю (A):\n");
    input_matrix_ptr(A1, n);
    printf("\nВводьте другу матрицю (B):\n");
    input_matrix_ptr(B1, n);

    print_matrix_ptr(A1, n, "Матриця A:");
    print_matrix_ptr(B1, n, "Матриця B:");

    double **C1 = multiply_ptr(A1, B1, n);
    if (!C1) { fprintf(stderr, "Помилка при множенні (ptr)\n"); free_matrix_ptr(A1,n); free_matrix_ptr(B1,n); return 1; }
    print_matrix_ptr(C1, n, "Добуток C = A * B (ptr):");

    free_matrix_ptr(A1, n);
    free_matrix_ptr(B1, n);
    free_matrix_ptr(C1, n);

    /* ----- Варіант 2 ----- */
    printf("\n=== Подання через лінійний масив double * (розмір n*n) ===\n");
    double *A2 = create_zero_matrix_lin(n);
    double *B2 = create_zero_matrix_lin(n);
    if (!A2 || !B2) { free_matrix_lin(A2); free_matrix_lin(B2); return 1; }

    printf("\nВводьте першу матрицю (A):\n");
    input_matrix_lin(A2, n);
    printf("\nВводьте другу матрицю (B):\n");
    input_matrix_lin(B2, n);

    print_matrix_lin(A2, n, "Матриця A (lin):");
    print_matrix_lin(B2, n, "Матриця B (lin):");

    double *C2 = multiply_lin(A2, B2, n);
    if (!C2) { fprintf(stderr, "Помилка при множенні (lin)\n"); free_matrix_lin(A2); free_matrix_lin(B2); return 1; }
    print_matrix_lin(C2, n, "Добуток C = A * B (lin):");

    free_matrix_lin(A2);
    free_matrix_lin(B2);
    free_matrix_lin(C2);

    return 0;
}
