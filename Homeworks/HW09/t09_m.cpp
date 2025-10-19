#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double **create_matrix(int rows, int cols);
void fill_matrix(double **A, int rows, int cols, int mode);
void print_matrix(double **A, int rows, int cols, const char *title);
double **delete_columns(double **A, int rows, int cols, int k1, int k2, int *new_cols);
void free_matrix(double **A, int rows);

int main() {
    int N, M;
    printf("Введіть кількість рядків (N) і стовпців (M): ");
    scanf("%d %d", &N, &M);

    if (N <= 0 || M <= 0) {
        printf("Некоректні розміри матриці!\n");
        return 1;
    }

    double **A = create_matrix(N, M);

    int choice;
    printf("Оберіть спосіб заповнення:\n1 - випадковими числами\n2 - з консолі\n> ");
    scanf("%d", &choice);
    fill_matrix(A, N, M, choice);

    print_matrix(A, N, M, "\nПочаткова матриця:");

    int k1, k2;
    printf("\nВведіть індекси стовпців для видалення (від k1 до k2, нумерація з 0): ");
    scanf("%d %d", &k1, &k2);

    if (k1 < 0 || k2 >= M || k1 > k2) {
        printf("Некоректні індекси!\n");
        free_matrix(A, N);
        return 1;
    }

    int newM;
    double **B = delete_columns(A, N, M, k1, k2, &newM);

    print_matrix(B, N, newM, "\nМатриця після видалення стовпців:");
    free_matrix(B, N);
    return 0;
}


// створення динамічної матриці N×M
double **create_matrix(int rows, int cols) {
    double **A = (double **)malloc(rows * sizeof(double *));
    if (!A) {
        printf("Помилка виділення пам'яті!\n");
        exit(1);
    }
    for (int i = 0; i < rows; i++) {
        A[i] = (double *)malloc(cols * sizeof(double));
        if (!A[i]) {
            printf("Помилка виділення пам'яті!\n");
            exit(1);
        }
    }
    return A;
}

void fill_matrix(double **A, int rows, int cols, int mode) {
    if (mode == 1) {
        srand(time(NULL)); //для випадкового заповнення матриці
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                A[i][j] = ((double)rand() / RAND_MAX) * 20 - 10; // [-10, 10]
    } else if (mode == 2) {
        printf("Введіть елементи матриці (%d×%d):\n", rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                scanf("%lf", &A[i][j]);
    } else {
        printf("Некоректний вибір режиму!\n");
        exit(1);
    }
}

void print_matrix(double **A, int rows, int cols, const char *title) {
    printf("%s\n", title);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%8.2lf ", A[i][j]);
        printf("\n");
    }
}

double **delete_columns(double **A, int rows, int cols, int k1, int k2, int *new_cols) {
    *new_cols = cols - (k2 - k1 + 1);

    double **B = create_matrix(rows, *new_cols);

    for (int i = 0; i < rows; i++) {
        int new_j = 0;
        for (int j = 0; j < cols; j++) {
            if (j < k1 || j > k2) {
                B[i][new_j] = A[i][j];
                new_j++;
            }
        }
    }

    free_matrix(A, rows);
    return B;
}

void free_matrix(double **A, int rows) {
    for (int i = 0; i < rows; i++)
        free(A[i]);
    free(A);
}
