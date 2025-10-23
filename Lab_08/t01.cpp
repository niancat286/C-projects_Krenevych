#include <stdio.h>

#define ROWS 3
#define COLS 3

int main() {
    // Статичний двовимірний масив 3x3
    int matrix[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int N, M;

    printf("Введіть N і M: ");
    scanf("%d %d", &N, &M);

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] == M) {
                matrix[i][j] = N;
            }
        }
    }

    printf("Отримана матриця:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
