#include <stdio.h>

#define N 100
#define M 100


void read_matrix(int matr[N][M], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("matr[%d][%d] = ", i, j);
            scanf("%lf", &matr[i][j]);
        }
    }

}


void transpose(int matr[N][M], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int temp = matr[i][j];
            matr[i][j] = matr[j][i];
            matr[j][i] = temp;
        }
    }
}


int sum_diagonal(int matr[N][M], int n, int m, int k) {
    int sum = 0;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j >= 0 && j < m && (i - j == k)) {
                sum += matr[i][j];
            }
        }
    }

    return sum;
}



int main() {
    int n, m, k;
    printf("n, m: ");
    scanf("%d %d", &n, &m);
    int matr[N][M];

    read_matrix(matr, n, m);
    //if (n == m) {
    //    transpose(matr, n);
    //}

    printf("k:");
    scanf("%d", &k);
    int res;
    res = sum_diagonal(matr, n, m, k);
    printf("suma %d\n", res);




}