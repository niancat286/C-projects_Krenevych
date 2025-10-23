#include <stdio.h>

int main() {
    double matrix[3][3] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };

    int i, j;
    double a;

    printf("Enter row index i (0..2): ");
    scanf("%d", &i);

    printf("Enter column index j (0..2): ");
    scanf("%d", &j);

    printf("Enter a real number a: ");
    scanf("%lf", &a);


    if (i < 0 || i >= 3 || j < 0 || j >= 3) {
        printf("Error: indices out of range!\n");
        return 1;
    }

    matrix[i][j] = a;


    printf("\nResulting matrix:\n");
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            printf("%.2lf ", matrix[r][c]);
        }
        printf("\n");
    }

    return 0;
}