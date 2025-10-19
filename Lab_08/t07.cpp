#include <stdio.h>
#include <stdlib.h>

#define MAX 10

double determinant(double A[MAX][MAX], int n) {
    if (n == 1) return A[0][0];

    if (n == 2)  // базовий випадок 2x2
        return A[0][0]*A[1][1] - A[0][1]*A[1][0];

    double det = 0;
    double temp[MAX][MAX];

    for (int col = 0; col < n; col++) {
        int subi = 0;
        for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
                if (j == col) continue;
                temp[subi][subj] = A[i][j];
                subj++;
            }
            subi++;
        }
        double sign = (col % 2 == 0) ? 1 : -1;
        det += sign * A[0][col] * determinant(temp, n-1);
    }
    return det;
}

int main() {
    int n;
    double A[MAX][MAX];

    printf("Введіть розмір квадратної матриці (<=%d): ", MAX);
    scanf("%d", &n);
    if (n <= 0 || n > MAX) {
        printf("Невірний розмір!\n");
        return 1;
    }

    printf("Введіть елементи матриці %dx%d:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    double det = determinant(A, n);
    printf("Детермінант матриці: %.2lf\n", det);

    return 0;
}
