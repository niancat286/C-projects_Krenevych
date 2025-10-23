#include <stdio.h>

#define MAX 10   // максимально допустимий розмір для n, m, k

int main() {
    int n, m, k;
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX]; //можемо не перевіряти розміри матриць, бо при такому заданні розмірів
    //точно гарантоване множення

    printf("Введіть n, m і k: ");
    scanf("%d %d %d", &n, &m, &k);

    // Введення A (n × m)
    printf("Введіть елементи матриці A (%d x %d):\n", n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Введення B (m × k)
    printf("Введіть елементи матриці B (%d x %d):\n", m, k);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // C = A * B
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = 0;
            for (int t = 0; t < m; t++) {
                C[i][j] += A[i][t] * B[t][j];
            }
        }
    }

    printf("Добуток матриць (C = A * B):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            printf("%5d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
