#include <stdio.h>

#define N 25
#define M 25

void read_matrix(int matr[N][M], int n, int m) {
    for (int i = 0; i < n; i++) {
        printf("enter row %d: \n", i);
        for (int j = 0; j < m; j++) {
            scanf("%d", &matr[i][j]);
        }
    }
}


void transpose(int matr[N][M], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < m; j++) {
            int temp = matr[i][j];
            matr[i][j] = matr[j][i];
            matr[j][i] = temp;
        }
    }
}


int main() {
    int n, m;
    printf("n, m: ");
    scanf("%d %d", &n, &m);
    int matr[N][M];

    read_matrix(matr, n, m);
    if (n == m) {
        transpose(matr, n);
    }




}