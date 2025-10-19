#include <stdio.h>

#define N 20
#define M 20

void read_matrix(double matr[N][M], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("matr[%d][%d] = ", i, j);
            scanf("%lf", &matr[i][j]);
        }
    }

}


int main() {
    int n;
    int m;
    printf("n: ");
    scanf("%d", &n);
    printf("m: ");
    scanf("%d", &m);

    double matr[N][M];

    read_matrix(matr, n, m);


}